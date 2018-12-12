#include "stdafx.h"
#include "substring_test.h"



#include "../include/timer.h"
#include "../leetcode/substring.h"



substring_test substring_test::m_self;
substring_test::substring_test()
	: UnitBase()
{
}


substring_test::~substring_test()
{
}

void substring_test::TestMain()
{
	string a("ab");
	string b("ba");

	ASSERT_T(buddyStrings(a, b));


	a = string("aaaaaaabc");
	b = string("aaaaaaacb");

	ASSERT_T(buddyStrings(a, b));

	a = string("aa");
	b = string("aa");

	ASSERT_T(buddyStrings(a, b));

	a = string("ab");
	b = string("ab");

	ASSERT_T(!buddyStrings(a, b));

	a = string("");
	b = string("ab");

	ASSERT_T(!buddyStrings(a, b));
}
