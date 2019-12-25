/*
 * common.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 25 Dec. 2019
 */


#include "include/common.h"


////////////////////
//Globals
Properties::Properties(unsigned fW, unsigned fH, unsigned fR) : frameWidth(fW), frameHeight(fH), frameRate(fR) { }

Settings::Settings(unsigned fQS, unsigned eL, unsigned dDB, unsigned dS) :
  frameQueueSize(fQS), effectsLimit(eL), dispDataBufSize(dDB), defaultSpeed(dS) { }


////////////////////
//Miscellaneous
Num::size_t roundUp(Num::size_t m, Num::size_t n)
{
    //Read http://www.cs.nott.ac.uk/~psarb2/G51MPC/slides/NumberLogic.pdf
    return (m + n -1) / n;
}