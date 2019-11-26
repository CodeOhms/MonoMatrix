/*
 * matrix_handling.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#ifndef   MATRIX_HANDLING_H
#define   MATRIX_HANDLING_H


#include "c_macros.h" //num::byte (uint8_t) and std::size_t


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


void rowData(unsigned row, unsigned rowLength, array frame, array data);


//Parsing
    //Pass infomation for one symbol at a time
void parseSymbols(unsigned index, num::byte symbols[], array buffer);

void parseEffects();


#endif //MATRIX_HANDLING_H