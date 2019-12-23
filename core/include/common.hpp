/*
 * common.hpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 15 Nov. 2019
 */


#ifndef  COMMON_HPP
#define  COMMON_HPP


#include "macros.h"


//Globals
struct Settings
{
    const int effectsLimit;
    const int dispDataBufSize;
    const int frameRate;
    const int defaultSpeed;
    const int frameQueueSize;

    Settings(int eL, int dDB, int fR, int dS, int fQS) :
      effectsLimit(eL), dispDataBufSize(dDB), frameRate(fR), defaultSpeed(dS), frameQueueSize(fQS) { }
};


namespace Num
{
    #ifdef  MBED
    typedef std::size_t size_t;
    typedef uint8_t byte;
    #endif //MBED
}


struct array
{
    Num::byte*  arr = nullptr;
    Num::size_t len = 0;
};


#endif //COMMON_HPP