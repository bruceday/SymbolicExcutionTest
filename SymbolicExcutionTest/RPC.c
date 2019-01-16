#include<stdio.h>
#include "RPC.h"

void RPC_reset(outC_RPC * outC)
{
	THC_reset_ANA_TIME_DEPENDENT(&outC->Context_1);
	DFL_reset_POL_TIME_DEPENDENT_binary(&outC->Context_2);
}

void RPC(inC_RPC * inC, outC_RPC * outC)
{
	analog tmp;
	binary _L13;
	DFL_POL_TIME_DEPENDENT_binary(&inC->IN_MNB,&outC->Context_2);
	kcg_copy_binary(&_L13,&outC->Context_2.O1);
	kcg_copy_binary(&outC->O_TEMP,&outC->Context_2.O2);
	FSF_POL_TIME_INDEPENDENT_anolog(&_L13,&inC->I_A,&tmp);
	THC_ANA_TIME_DEPENDENT(&tmp, inC->SVAL, inC->HYST, &outC->Context_1);
	kcg_copy_binary(&outC->O_A_WARNING,&outC->Context_1.O1);
}
