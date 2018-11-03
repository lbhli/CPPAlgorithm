#include "stdafx.h"
#include "UnitBase.h"
#include<list>
#include<iostream>
#include<string>
#include<windows.h>

// const strings
const std::string LOGFILE = "d:\\UnitTestResult.txt";
const std::string SPLITLINE = "-------------------------------------------------------------------------------";
const std::string RETURN = "\r\n";

const std::string STARTSTRING = "Start to test ";
const std::string TESTRESULT = " test result:";
const std::string TOTAL = " Total test:";
const std::string PASSED = " Passed :";
const std::string FAILED = " Failed :";

const std::string OPENAPPNAME = "NOTEPAD.EXE";
const std::string OPERATION = "open";

// static class member initialize
std::list<UnitBase*>* UnitBase::m_Test = nullptr;
std::ofstream UnitBase::outfile;
int UnitBase::m_CountAll = 0;
int UnitBase::m_CountErr = 0;
int UnitBase::m_CountSucc = 0;

UnitBase::UnitBase()
 :m_Count(0),
  m_Err(0),
  m_Succ(0)
{
	if (!m_Test)
	{
		m_Test = new std::list<UnitBase*>();
	}
	m_Test->push_back(this);
}


UnitBase::~UnitBase()
{
	if (m_Test)
	{
		m_Test->clear();
		delete m_Test;
		m_Test = nullptr;
	}
}


void UnitBase::BeforTest()
{
	// This function can be realize by derived class
	// construct resource here if needed;
	std::string classname(typeid(*this).name());
	std::cout << SPLITLINE.c_str() << std::endl;
	std::cout << STARTSTRING.c_str() << classname.c_str() << std::endl;
	if (outfile.is_open()) {
		outfile << SPLITLINE.c_str() << std::endl;
		outfile << RETURN.c_str();
		outfile << STARTSTRING.c_str() << classname.c_str() << std::endl;
		outfile << RETURN.c_str();
	}
}

void UnitBase::AfterTest()
{
	// This function can be realize by derived class
	// destruction resource here if need	
	std::string classname(typeid(*this).name());
	std::cout << classname.c_str() << TESTRESULT.c_str() << std::endl;
	std::cout << TOTAL.c_str() << m_Count << std::endl; 
	std::cout << PASSED.c_str() << m_Succ << std::endl; 
	std::cout << FAILED.c_str() << m_Err << std::endl;
	if (outfile.is_open()) {
		outfile << classname.c_str() << TESTRESULT.c_str();
		outfile << RETURN.c_str();
		outfile << TOTAL.c_str() << m_Count;
		outfile << RETURN.c_str();
		outfile << PASSED.c_str() << m_Succ;
		outfile << RETURN.c_str();
		outfile << FAILED.c_str() << m_Err;
		outfile << RETURN.c_str();
	}
}

void UnitBase::TestMain()
{
	// This function should be realize by derived class
	// Start to do NUNIT test here.	
}

// This is static function, and this function will be called to do 
// nunit test, and can be called only one time.
void UnitBase::StartTest()
{
	outfile.open(LOGFILE.c_str(), std::ofstream::binary );

	// Start do unit test for each class
	for (std::list<UnitBase*>::const_iterator it = m_Test->cbegin(); it != m_Test->cend(); ++it)
	//for( auto it : m_Test)
	{
		(*it)->BeforTest();
		(*it)->TestMain();
		(*it)->AfterTest();
		m_CountAll += (*it)->m_Count;
		m_CountErr += (*it)->m_Err;
		m_CountSucc += (*it)->m_Succ;
	}

	// show test result
	std::cout << SPLITLINE.c_str() << std::endl;
	std::cout << TOTAL.c_str() << m_CountAll << std::endl;
	std::cout << PASSED.c_str() << m_CountSucc << std::endl;
	std::cout << FAILED.c_str() << m_CountErr << std::endl;

	// save test result to file
	outfile << SPLITLINE.c_str();
	outfile << RETURN.c_str();
	outfile << TOTAL.c_str() << m_CountAll;
	outfile << RETURN.c_str();
	outfile << PASSED.c_str() << m_CountSucc;
	outfile << RETURN.c_str();
	outfile << FAILED.c_str() << m_CountErr;
	outfile << RETURN.c_str();
	outfile.close();
	
	// Open and show the test result file
#ifdef WIN32
	::ShellExecuteA(NULL, OPERATION.c_str(), OPENAPPNAME.c_str(), LOGFILE.c_str(), NULL, SW_SHOWNORMAL);
#endif // WIN32
#ifdef linux

#endif
}
