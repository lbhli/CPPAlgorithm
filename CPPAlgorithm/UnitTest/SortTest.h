#pragma once

#include "UnitBase.h"
class SortTest : public UnitBase
{
public:
    SortTest();
    ~SortTest();
    virtual void TestMain();

private:
    void QuickSortTest();
    bool CompareArray(int *arrayA,
        int *arrayB,
        int nLength);
    static int compare(const void * a,
        const void * b)
    {
        return (*(int*)a - *(int*)b);
    }

private:
    static SortTest m_self;
};