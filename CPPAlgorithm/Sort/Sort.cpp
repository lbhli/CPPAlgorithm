#include "stdafx.h"

#include "Sort.h"


int partition(int data[], int nStart, int nStop)
{
    int nValue = data[nStart];
    while (nStart < nStop)
    {
        while (nStart < nStop && data[nStop] > nValue)
        {
            --nStop;
        }

        if (nStart < nStop)
        {
            data[nStart++] = data[nStop];
        }

        while (nStart < nStop && data[nStart] < nValue)
        {
            ++nStart;
        }

        if (nStart < nStop)
        {
            data[nStop--] = data[nStart];
        }

    }

    data[nStart] = nValue;
    return nStart;
}

void quickSort(int data[], int nLeft, int nRight)
{
    if (data == nullptr)
    {
        return;
    }

    int nPos;
    if (nLeft < nRight)
    {
        nPos = partition(data, nLeft, nRight);
        quickSort(data, nLeft, nPos - 1);
        quickSort(data, nPos + 1, nRight);
    }
}