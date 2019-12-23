/*
 * macros.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 22 Dec. 2019
 */


 #ifndef  MACROS_H
 #define  MACROS_H

//Set by CMake
#define MBED
//const int FRAME_QUEUE_SIZE = 5;
const int FRAME_WIDTH      = 8;
const int FRAME_HEIGHT     = 8;
//const int FRAME_RATE       = 30;


#ifdef  MBED
#include <stdint.h> //uint8_t
#include <cstddef>  //size_t
#endif //MBED


 #endif //MACROS_H
