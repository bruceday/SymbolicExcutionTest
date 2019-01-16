#ifndef _THC_ANA_TIME_DEPENDENT_H_
#define _THC_ANA_TIME_DEPENDENT_H_
#include "kcg_types.h"
typedef struct 
{
	binary O1;
	kcg_bool init;
	SSM_ST_SM1 SM1_state_nxt;
	kcg_bool OutputValue;
}outC_THC_ANA_TIME_DEPENDENT;

extern void THC_ANA_TIME_DEPENDENT(analog *I1,kcg_real SVAL,kcg_real HYST,outC_THC_ANA_TIME_DEPENDENT *outC);

extern void THC_reset_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT *outC);

#endif // !_THC_ANA_TIME_DEPENDENT_H_

