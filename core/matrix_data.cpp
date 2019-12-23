/*
 * matrix_data.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 21 Dec. 2019
 */


#include "include/matrix_data.h"


////////////////////
//Frames
namespace FrameQueue
{
    bool read(Queue& q, Num::byte* newFrame)
    {
        if(q.count > 0)
        {
            newFrame = q.frames[q.head];
            q.tail   = (q.tail +1) % q.len;
            q.count -= 1;
            return true;
        }
        return false;
    }

    bool write(Queue& q, Num::byte* frameGrab)
    {
        if(q.count < q.len)
        {
            frameGrab = q.frames[q.head];
            q.head   = (q.head +1) % q.len;
            q.count += 1;
            return true;
        }
        frameGrab = nullptr;
        return false;
    }
}


////////////////////
//Symbols
SymbolGroup::SymbolGroup(int w, int h, Num::byte* symbols, Num::byte** tracer) :
  _width(w), _height(h), symbols(symbols), tracer(tracer) { }

SymbolGroup::~SymbolGroup()
{
    delete symbols;
    delete *tracer;
    delete tracer;
}

int SymbolGroup::width()
{
    return _width;
}

int SymbolGroup::height()
{
    return _height;
}

Num::byte* SymbolGroup::getSymbol(std::size_t id)
{
    return tracer[id];
}


Symbols::Symbols(SymbolGroup* groups, SymbolGroup** tracer) :
  groups(groups), tracer(tracer) { }

Symbols::~Symbols()
{
    delete groups;
    delete *tracer;
    delete tracer;
}

SymbolGroup* Symbols::getSymbolGroup(std::size_t id)
{
    return tracer[id];
}