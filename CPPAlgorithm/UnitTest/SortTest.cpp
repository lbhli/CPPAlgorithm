#include "stdafx.h"
#include "SortTest.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "../include/timer.h"
#include "../Sort/Sort.h"

#define LONG_TEST 100000

SortTest SortTest::m_self;
SortTest::SortTest()
    : UnitBase()
{
}


SortTest::~SortTest()
{
}

void SortTest::TestMain()
{
    QuickSortTest();
}

void SortTest::QuickSortTest()
{
    int data1[10] = { 1,4,7,3,9,2,5,8,6,0 };
    int order1[10] = { 0,1,2,3,4,5,6,7,8,9 };
    quickSort(data1, 0, 9);
    ASSERT_T(CompareArray(data1, order1, 10));


    int data2[10] = { 9,4,7,3,1,2,5,8,6,0 };
    int order2[10] = { 0,1,2,3,4,5,6,7,8,9 };
    quickSort(data2, 0, 9);
    ASSERT_T(CompareArray(data2, order2, 10));

    int data3[10] = { 5, 4, 7, 12, 4, 9, 2, 1, 13, 2 };
    int order3[10] = { 1, 2, 2, 4, 4, 5, 7, 9, 12, 13 };
    quickSort(data3, 0, 9);
    ASSERT_T(CompareArray(data3, order3, 10));


    int data4[20] = { 26,69,63,4,25,8,3,1,69,14,23,14,158,6981,256,26,4,589,63,457 };
    int order4[20] = { 26,69,63,4,25,8,3,1,69,14,23,14,158,6981,256,26,4,589,63,457 };
    std::qsort(order4, 20, sizeof(int), SortTest::compare);
    quickSort(data4, 0, 19);
    ASSERT_T(CompareArray(data4, order4, 20));

    int* data = new int[LONG_TEST];
    int* dataStd = new int[LONG_TEST];
    srand((int)time(0));
    for (int i = 0; i < LONG_TEST; ++i)
    {
        data[i] = rand();
        dataStd[i] = data[i];
    }

    {
        timer ti("quickSort");
        quickSort(data, 0, LONG_TEST - 1);
    }

    {
        timer ti("qsort");
        std::qsort(dataStd, LONG_TEST, sizeof(int), SortTest::compare);
    }

    ASSERT_T(CompareArray(data, dataStd, LONG_TEST));
}

bool SortTest::CompareArray(int * arrayA, int * arrayB, int nLength)
{
    for (int i = 0; i < nLength; ++i)
    {
        if (arrayA[i] != arrayB[i])
        {
            return false;
        }
    }
    return true;
}
