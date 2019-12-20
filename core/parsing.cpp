/*
 * parsing.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 19 Dec. 2019
 */


#include "parsing.h"


void parseSymbols(unsigned index, num::byte symbols[], array buffer)
{
    for(unsigned byteCount = 0; byteCount < buffer.len; ++byteCount)
    {
        symbols[index] = buffer.arr[byteCount];
        ++index;
    }
}


void parseDisplayData()
{
    //Read effects data

    //Read display data
    
}