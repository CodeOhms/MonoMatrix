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
#include "matrix_data.h"


Settings* parseSettings(Num::byte* fileBuf);


//Pass infomation for one symbol at a time. Prepares info for SymbolGroup objects
void parseSymbols(array fileBuf, Num::byte* symbols, Num::size_t& index, Num::byte** tracer, Num::size_t sID);


void parseEffectsData(array fileBuf, Effects* effects, Num::size_t& index, int effectsLimit);


// void parseDispData(array fileBuf, array rawDispData);


#endif //PARSING_H