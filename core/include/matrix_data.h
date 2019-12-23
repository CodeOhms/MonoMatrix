/*
 * matrix_data.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 21 Dec. 2019
 */


#ifndef  MATRIX_DATA
#define  MATRIX_DATA


#include "common.hpp"


////////////////////
//Frames
namespace FrameQueue
{
    struct Queue
    {
        //'frames' is a 2 dimensional array: frames[FRAME_QUEUE_SIZE][FRAME_WIDTH * FRAME_HEIGHT]
        Num::byte** frames;
        Num::byte len;
        Num::byte count;
        Num::byte head;
        Num::byte tail;
    };

    bool read(Queue& q, Num::byte* newFrame);

    //Client code writes to pointer returned
    bool write(Queue& q, Num::byte* frameGrab);
}


// ////////////////////
// //Symbols
// class SymbolGroup
// {
//     Num::byte*  symbols;
//     Num::byte** tracer;
//     int _width;
//     int _height;

// public:

//     SymbolGroup(int w, int h, Num::byte* symbols, Num::byte** tracer);
//     ~SymbolGroup();

//     int width();
//     int height();

//     Num::byte* getSymbol(std::size_t id);
// };


// class Symbols
// {
//     SymbolGroup*  groups;
//     //Tracer array links symbol id to related group
//     SymbolGroup** tracer;

// public:

//     Symbols(SymbolGroup* groups, SymbolGroup** tracer);
//     ~Symbols();

//     SymbolGroup* getSymbolGroup(std::size_t id);
// };


////////////////////
//Effects
struct Effects
{
    Num::byte* effects;
    int*       speeds;
};


// ////////////////////
// //Display data
// struct RawDispData
// {
//     Num::byte* data;
// };



#endif //MATRIX_DATA