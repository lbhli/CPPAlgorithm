#include "stdafx.h"
#include "addString_test.h"
#include "../leetcode/addString.h"
#include <random>
#include <ctime>
#include <sstream>
#include <iostream>
#define LONG_TEST 100000

addString_test addString_test::m_self;
addString_test::addString_test()
    : UnitBase()
{
}


addString_test::~addString_test()
{
}

void addString_test::TestMain()
{
    // Test 1
    string str1("235");
    string str2("1890");
    string strResult = addStrings(str1, str2);
    ASSERT_T(strResult.compare("2125") == 0);

    // Test 2
    str1 = string("1355");
    str2 = string("5645");
    strResult = addStrings(str1, str2);
    // std::cout << "1:" << strResult << std::endl;
    ASSERT_T(strResult.compare("7000") == 0);


    // Test: Random test
    srand((int)time(0));
    int nValue1 = rand();
    int nValue2 = rand();    
    std::stringstream ss;
    ss << nValue1;
    ss >> str1;
    ss.clear();

    ss << nValue2;
    ss >> str2;
    ss.clear();

    ss << (nValue1 + nValue2);
    string strExpect;
    ss >> strExpect;
    
    strResult = addStrings(str1, str2);
    //std::cout << strResult << std::endl;
    ASSERT_T(strResult.compare(strExpect) == 0 );
    
}