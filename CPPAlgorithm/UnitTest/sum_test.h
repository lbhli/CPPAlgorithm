#pragma once

#pragma once

#include "UnitBase.h"
#include <vector>
using std::vector;
class sum_test : public UnitBase
{
public:
    sum_test();
    ~sum_test();
    virtual void TestMain();

private:
    bool CompareVector(vector<vector<int>>& result, vector<vector<int>>& expectation);
    
private:
    static sum_test m_self;
};