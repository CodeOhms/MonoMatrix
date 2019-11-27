/*
 * matrix_handling.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#ifndef   MATRIX_HANDLING_H
#define   MATRIX_HANDLING_H


#include "common.h" //num::byte (uint8_t) and size_t (std::size_t)


struct FrameQueue
{
    num::byte   frames[FRAME_QUEUE_SIZE][FRAME_WIDTH * FRAME_HEIGHT];
    num::byte** drawTracer;
    num::byte** displayTracer;
};


struct array
{
    num::byte*  arr = nullptr;
    num::size_t len = 0;
};


//All assume LSB is at right.
    //Will pad with zeros right if needed.
void rowData(unsigned row, unsigned rowLength, num::byte* frame, num::byte* data);

    //Pass infomation for one symbol at a time.
void storeSymbols(unsigned index, num::byte symbols*, array buffer);

void parseEffects();


#endif //MATRIX_HANDLING_H