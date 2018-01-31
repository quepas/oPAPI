#ifndef _OPAPI_STATUS_H_
#define _OPAPI_STATUS_H_

#include "mex.h"

#define OPAPI_STATUS_NONE -2
#define OPAPI_STATUS_INIT -1
#define OPAPI_STATUS_COUNTING 0
/* oPAPI_STATUS_1, 2, 3,... number of active counters */

/*
 *  Set global variable oPAPI_status
 */
void oPAPI_setGlobalStatus(int initial_value)
{
    mxArray *oPAPI_status = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    int *status = (int *)mxGetData(oPAPI_status);
    *status = initial_value;
    mexPutVariable("global", "oPAPI_status", oPAPI_status);
}

/*
 *  Get global variable oPAPI_status
 */
int oPAPI_getGlobalStatus()
{
    mxArray *oPAPI_status = mexGetVariable("global", "oPAPI_status");
    if (oPAPI_status == 0)
    {
        return OPAPI_STATUS_NONE;
    }
    return *((int *)mxGetData(oPAPI_status));
}

int oPAPI_getNumRunningCounters()
{
    int current_status = oPAPI_getGlobalStatus();
    if (current_status > OPAPI_STATUS_COUNTING)
    {
        return current_status;
    }
    return 0;
}

/* _OPAPI_STATUS_H_ */
#endif
