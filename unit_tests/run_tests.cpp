/*
 * run_tests.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 14 Nov. 2019
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "core_tests.hpp"


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}