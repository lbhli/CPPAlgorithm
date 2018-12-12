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
	vector<int> testdate1({ 1, 2, 6, 4, 5, 16, 8, 7 });

	vector<int> vResult = twoSum(testdate1, 8);
	vector<int> vExpect({ 0,7 });
	ASSERT_T(CompareVector(vResult,vExpect));	
}


bool sum_test::CompareVector(vector<int>& result, vector<int>& expectation)
{
	int nSize1 = static_cast<int>(result.size());
	int nSize2 = static_cast<int>(expectation.size());

	if (nSize1 != nSize2)
	{
		return false;
	}

	for (int i = 0; i < nSize1; ++i)
	{
		if (result[i] != expectation[i])
		{
			return false;
		}
	}

	return true;
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

