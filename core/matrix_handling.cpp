/*
 * matrix_handling.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#include "include/matrix_handling.h"


////////////////////
//Business logic
void rowData(unsigned row, unsigned rowLength, Num::byte* frame, Num::byte* data)
{
    Num::size_t byteSpan = (rowLength + 7)/ 8; //Rounds up. Read http://www.cs.nott.ac.uk/~psarb2/G51MPC/slides/NumberLogic.pdf
    Num::size_t atByte = (row * rowLength) / 8;
    Num::size_t offset = 0;
    // auto offsetCalc = [=] (Num::size_t byteIndex) -> Num::size_t {
    //     Num::size_t const offsetSpan = (rowLength / 8);
    //     return (byteIndex / offsetSpan) % rowLength;
    // };

    auto shiftLeft = [&] (Num::size_t dataIndex, Num::size_t byteIndex, Num::size_t shift) -> void {
        data[dataIndex] = frame[byteIndex] << shift;
    };
    auto shiftRight = [&] (Num::size_t dataIndex, Num::size_t byteIndex, Num::size_t shift) -> void {
        data[dataIndex] |= frame[byteIndex] >> 8 - shift;
    };

    if(byteSpan == 1)
    {
        data[0] = frame[atByte];
        return;
    }

    // a) run once
    offset = (atByte / (rowLength / 8)) % rowLength;
    // offset = offsetCalc(atByte);
    shiftLeft(0, atByte, offset);
    ++atByte;

    //b) may not run
    if(byteSpan >= 3)
    {
        for(Num::size_t i = 1; i < byteSpan -1; ++i)
        {
            shiftRight(i -1, atByte, offset);
            shiftLeft(i, atByte, offset);
            ++atByte;
        }
    }

    //c) run once
    shiftRight(byteSpan -2, atByte, offset);
    shiftLeft(byteSpan -1, atByte, offset);
    Num::byte mask = 255 << 8 - (rowLength % 8);
    data[byteSpan -1] &= mask;

    return;
}


void uncompress(Num::byte* dispData, Num::byte* newFrame)
{
    for(Num::size_t row = 0; row < FRAME_HEIGHT; ++row)
    {
        rowData(row, FRAME_WIDTH, newFrame, dispData);
    }
}


////////////////////
//Effects Rendering
bool isQueueFree(FrameQueue::Queue& fQueue, Num::byte* draw)
{
    if(FrameQueue::write(fQueue, draw))
    {
        return true;
    }
    return false;
}


bool plain(FrameQueue::Queue& fQueue, Num::byte* newFrame)
{
    Num::byte* draw;
    if(isQueueFree(fQueue, draw))
    {
        for(Num::size_t byte = 0; byte < (FRAME_WIDTH * FRAME_HEIGHT); ++byte)
        {
            draw[byte] = newFrame[byte];
        }

        return true;
    }
    else
    {
        return false;
    }
}


bool scrollLeft(FrameQueue::Queue& fQueue, Num::byte* newFrame)
{
    Num::byte* draw;
    if(FrameQueue::write(fQueue, draw))
    {
        //Scroll left
        return true;
    }
    else
    {
        return false;
    }
    
}