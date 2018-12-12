#include "stdafx.h"
#include "sum_test.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/timer.h"
#include "../leetcode/sum.h"



sum_test sum_test::m_self;
sum_test::sum_test()
    : UnitBase()
{
}


sum_test::~sum_test()
{
}

void sum_test::TestMain()
{
    vector<int> testdate({ 1, 2, -3, 4, 5, -6, 8, -3 });
    vector<vector<int>> result = threeSum(testdate);
    vector<vector<int>> expect({ {-6,2,4},{-6,1,5},{-3,1,2} });
    ASSERT_T(CompareVector(result, expect));
    for (auto i : result)
    {
        for (auto n : i)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }

}

bool sum_test::CompareVector(vector<vector<int>>& result,
    vector<vector<int>>& expectation)
{
    if (result.size() == expectation.size())
    {
        for (auto r : result)
        {
            auto ptr = std::find(expectation.begin(), expectation.end(), r);
            if (ptr == expectation.end())
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }    
}

