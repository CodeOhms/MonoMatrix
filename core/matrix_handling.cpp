/*
 * matrix_handling.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#include "include/matrix_handling.h"


void rowData(unsigned row, unsigned rowLength, num::byte* frame, num::byte* data)
{
    size_t byteSpan = (rowLength + 7)/ 8; //Rounds up. Read http://www.cs.nott.ac.uk/~psarb2/G51MPC/slides/NumberLogic.pdf
    size_t atByte = (row * rowLength) / 8;
    size_t offset = 0;
    auto offsetCalc = [=] (size_t byteIndex) -> size_t {
        size_t const offsetSpan = (rowLength / 8);
        return (byteIndex / offsetSpan) % rowLength;
    };

    auto shiftLeft = [&] (size_t dataIndex, size_t byteIndex, size_t shift) -> void {
        data[dataIndex] = frame[byteIndex] << shift;
    };
    auto shiftRight = [&] (size_t dataIndex, size_t byteIndex, size_t shift) -> void {
        data[dataIndex] |= frame[byteIndex] >> 8 - shift;
    };

    if(byteSpan == 1)
    {
        data[0] = frame[atByte];
        return;
    }

    // a) run once
    offset = offsetCalc(atByte);
    shiftLeft(0, atByte, offset);
    ++atByte;

    //b) may not run
    if(byteSpan >= 3)
    {
        for(size_t i = 1; i < byteSpan -1; ++i)
        {
            shiftRight(i -1, atByte, offset);
            shiftLeft(i, atByte, offset);
            ++atByte;
        }
    }

    //c) run once
    shiftRight(byteSpan -2, atByte, offset);
    shiftLeft(byteSpan -1, atByte, offset);
    num::byte mask = 255 << 8 - (rowLength % 8);
    data[byteSpan -1] &= mask;

    return;
}


void storeSymbols(unsigned index, num::byte symbols*, array buffer)
{
    for(unsigned byteCount = 0; byteCount < buffer.len; ++byteCount)
    {
        symbols[index] = buffer.arr[byteCount];
        ++index;
    }
}