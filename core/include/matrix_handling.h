/*
 * matrix_handling.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 10 Nov. 2019
 */


#ifndef   MATRIX_HANDLING_H
#define   MATRIX_HANDLING_H


#include "common.h" //Num::byte (uint8_t) and size_t (std::size_t)
#include "matrix_data.h"

////////////////////
//Business logic
// void rowData(unsigned row, unsigned rowLength, Num::byte* frame, Num::byte* data);
//Use uncompress() instead
void rowData(unsigned row, unsigned rowLength, Num::byte* frame, Num::byte** data);


void uncompress(Properties& p, Num::byte* compressed, Num::byte* newFrame);


////////////////////
//Effects Rendering
bool isQueueFree(FrameQueue::Queue& fQueue, Num::byte* draw);


//Provide following effects with uncompressed display data.
    //Jumps to next frame.
bool plain(Properties& p, FrameQueue::Queue& fQueue, Num::byte* newFrame);


    //Smoothly moves between frames. Needs info from 2 frames, at maximum.
    //To optimise: take previously rendered frame, uncompress next frame, store it, and copy what's needed.
bool scrollLeft(Properties& p, FrameQueue::Queue& fQueue, Num::byte* newFrame);


#endif //MATRIX_HANDLING_H