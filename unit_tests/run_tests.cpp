/*
 * run_tests.cpp
 *
 *      Author: CodeOhms
 *     Contact: codeohms@protonmail.com
 *  Created on: 14 Nov. 2019
 */


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <bitset>
#include <vector>

#include "../core/include/matrix_handling.h"


struct MatrixData
{
    std::size_t rowLength;
    array uncompressed;
    array frame;
    array testBuffer;
};

class MatrixDataSet
{
public:
    std::vector<MatrixData*> dataSet;

    MatrixDataSet()
    {
        MatrixData* set;

        //Set 1
        set = new MatrixData;
        set->rowLength = 8;
        set->frame.len = 8;
        set->frame.arr = new uint8_t[set->frame.len] {
            0b00000000,
            0b01111110,
            0b10000001,
            0b10000001,
            0b11111111,
            0b10000001,
            0b10000001,
            0b10000001
        };
        set->uncompressed = set->frame;
        set->testBuffer.len = 1;
        set->testBuffer.arr = new uint8_t[set->testBuffer.len];
        dataSet.push_back(set);

        //Set 2
        set = new MatrixData;
        set->rowLength = 9;
        set->frame.len = 11;
        /*
         * Uncompressed data (displays C++)
         * Padding     |------|
         * 11111110, 0 0000000
         * 10000000, 0 0000000
         * 10000000, 0 0000000
         * 10010001, 0 0000000
         * 10111011, 1 0000000
         * 10010001, 0 0000000
         * 10000000, 0 0000000
         * 10000000, 0 0000000
         * 11111110, 0 0000000
         */
        set->frame.arr = new uint8_t[set->frame.len] {
            0b11111110, 0b01000000,
            0b00100000, 0b00010010,
            0b00101011, 0b10111100,
            0b10001010, 0b00000001,
            0b00000000, 0b11111110,
            0b00000000
        };
        set->uncompressed.len = 18;
        set->uncompressed.arr = new uint8_t[set->uncompressed.len] {
            0b11111110, 0b00000000,
            0b10000000, 0b00000000,
            0b10000000, 0b00000000,
            0b10010001, 0b00000000,
            0b10111011, 0b10000000,
            0b10010001, 0b00000000,
            0b10000000, 0b00000000,
            0b10000000, 0b00000000,
            0b11111110, 0b00000000
        };
        set->testBuffer.len = 2;
        set->testBuffer.arr = new uint8_t[set->testBuffer.len];
        dataSet.push_back(set);
    }
    ~MatrixDataSet()
    {
        for(auto set : dataSet)
        {
            delete[] set->frame.arr;
            delete[] set->testBuffer.arr;
            delete[] set->uncompressed.arr;
            delete[] set;
        }
    }
};

class MatrixDataTest : public testing::TestWithParam<MatrixData*>
{
    
};

TEST_P(MatrixDataTest, FetchRowData)
{
    MatrixData* dataSet = GetParam();

    std::size_t byte = 0;
    for(std::size_t row = 0; row < dataSet->uncompressed.len / dataSet->testBuffer.len; ++row)
    {
        std::vector<uint8_t> original(dataSet->frame.arr, dataSet->frame.arr + dataSet->frame.len);
        rowData(row, dataSet->rowLength, dataSet->frame.arr, dataSet->testBuffer.arr);
        ASSERT_THAT(original, testing::ElementsAreArray(dataSet->frame.arr, dataSet->frame.len))
          << "Function 'rowData' modified frame buffer!" << std::endl;

        std::bitset<8> expected;
        std::bitset<8> output;
        for(std::size_t testByte = 0; testByte < dataSet->testBuffer.len; ++testByte)
        {
            EXPECT_EQ(dataSet->uncompressed.arr[byte], dataSet->testBuffer.arr[testByte])
              << "Row, byte: " << row << ", " << byte << std::endl
              << "Expected data: " << expected << std::endl
              << "Output:        " << output << std::endl;

            ++byte;
        }
    }
}

MatrixDataSet* makeMDataSet()
{
    /*
     * GMock library cleans this up.
     * 'Double free detected error' will occur if client code attempts to delete it.
     */
    return new MatrixDataSet();
}

INSTANTIATE_TEST_CASE_P(TestMatrixManipulation, MatrixDataTest,
    testing::ValuesIn(
        makeMDataSet()->dataSet
    )
);


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}