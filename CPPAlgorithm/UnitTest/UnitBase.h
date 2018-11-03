#pragma once

#include <list>
#include <fstream>

// This assert is used to do verify
#define ASSERT_T(bOK) \
{\
	++m_Count;\
	if( bOK )\
	{\
		++m_Succ;\
	}\
	else\
	{\
		++m_Err;\
		outfile << __FILE__ << " failed at line:" << __LINE__ ;\
		outfile << "\r\n";\
	}\
}


// base class for unit test
// This class can not be realized.
class UnitBase
{
public:	
	static void StartTest();// Call this function to start the unit test
public:
	UnitBase();
	virtual ~UnitBase();
	virtual void TestMain() = 0;
	virtual void BeforTest();
	virtual void AfterTest();
	
protected:
	static int m_CountAll;	// Record the whole test number for all class
	static int m_CountErr;	// Record the whole test number for all class
	static int m_CountSucc;	// Record the whole test number for all class

	int m_Count;			// Record the whole test number for this class
	int m_Err;				// Record the failed number for this class
	int m_Succ;				// Record the success number for this class
	static std::ofstream outfile;
private:
	static std::list<UnitBase*>* m_Test;	
};

