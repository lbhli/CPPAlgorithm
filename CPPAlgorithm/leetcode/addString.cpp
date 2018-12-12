#include "stdafx.h"
#include "addString.h"

string addStrings(const string& num1, const string& num2)
{
    const string& longStr = num1.size() >= num2.size() ? num1 : num2;
    const string& shortStr = num1.size() < num2.size() ? num1 : num2;

    int nLongLen = static_cast<int>(longStr.size());
    int nShortLen = static_cast<int>(shortStr.size());

    int nPos = 0;
    int nPos1 = 0;
    int nSum = 0;
    while (nLongLen > nShortLen)
    {
        nSum = nSum * 10 + (longStr[nPos] - '0');
        --nLongLen;
        ++nPos;
    }
    while (nShortLen > 0 )
    {
        nSum = nSum * 10 
            + ((longStr[nPos+nPos1] - '0') + (shortStr[nPos1] - '0'));
        --nShortLen;
        ++nPos1;
    }


    string strResult("");
    while (nSum > 0)
    {
        strResult.insert( strResult.begin(), char(nSum % 10 + '0'));
        nSum /= 10;
    }
    return strResult;
}