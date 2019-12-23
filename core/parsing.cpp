/*
 * parsing.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 19 Dec. 2019
 */


#include "parsing.h"


Settings* parseSettings(Num::byte* fileBuf)
{
    return new Settings(fileBuf[0], fileBuf[1], fileBuf[2], fileBuf[3], fileBuf[4]);
}


void parseSymbols(array fileBuf, Num::byte* symbols, Num::size_t& index, Num::byte** tracer, Num::size_t sID)
{
    tracer[sID] = &symbols[index];

    for(unsigned byteCount = 0; byteCount < fileBuf.len; ++byteCount)
    {
        symbols[index] = fileBuf.arr[byteCount];
        ++index;
    }
}


void parseEffectsData(array fileBuf, Effects* effects, Num::size_t& index, int effectsLimit)
{
    for(Num::size_t e = 0; e < fileBuf.len; ++e)
    {
        effects->effects[index] = fileBuf.arr[e];
        ++index;
    }
}


// void parseDispData(array fileBuf, array rawDispData)
// {

// }