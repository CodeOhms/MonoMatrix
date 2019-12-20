/*
 * parsing.h
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 19 Dec. 2019
 */


#ifndef  PARSING_H
#define  PARSING_H

#include "common.h"

//Pass infomation for one symbol at a time

void parseSymbols(unsigned index, num::byte symbols[], array buffer);


void parseDisplayData();


#endif //PARSING_H