/*
 * matrix_handling.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#include "include/matrix_handling.h"


void rowData(unsigned row, unsigned rowLength, array frame, array data)
{
    std::size_t byteSpan = (rowLength + 7)/ 8; //Rounds up. Read http://www.cs.nott.ac.uk/~psarb2/G51MPC/slides/NumberLogic.pdf
    std::size_t atByte = (row * rowLength) / 8;
    std::size_t offset = 0;
    auto offsetCalc = [=] (std::size_t byteIndex) -> std::size_t {
        std::size_t const offsetSpan = (rowLength / 8);
        return (byteIndex / offsetSpan) % rowLength;
    };

    auto shiftLeft = [&] (std::size_t dataIndex, std::size_t byteIndex, std::size_t shift) -> void {
        data.arr[dataIndex] = frame.arr[byteIndex] << shift;
    };
    auto shiftRight = [&] (std::size_t dataIndex, std::size_t byteIndex, std::size_t shift) -> void {
        data.arr[dataIndex] |= frame.arr[byteIndex] >> 8 - shift;
    };

    if(byteSpan == 1)
    {
        data.arr[0] = frame.arr[atByte];
        return;
    }

    // a)
    offset = offsetCalc(atByte);
    shiftLeft(0, atByte, offset);
    ++atByte;

    //b)
    if(byteSpan >= 3)
    {
        for(std::size_t i = 1; i < byteSpan -1; ++i)
        {
            shiftRight(i -1, atByte, offset);
            shiftLeft(i, atByte, offset);
            ++atByte;
        }
    }

    //c)
    shiftRight(byteSpan -2, atByte, offset);
    shiftLeft(byteSpan -1, atByte, offset);
    num::byte mask = 255 << 8 - (rowLength % 8);
    data.arr[byteSpan -1] &= mask;

    return;
}


void parseSymbols(unsigned index, num::byte symbols[], array buffer)
{
    for(unsigned byteCount = 0; byteCount < buffer.len; ++byteCount)
    {
        symbols[index] = buffer.arr[byteCount];
        ++index;
    }
}