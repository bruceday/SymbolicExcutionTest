#include<stdio.h>
#include "RPC.h"
#include<stdlib.h>

void RPC_reset(outC_RPC * outC)
{
	THC_reset_ANA_TIME_DEPENDENT(&outC->Context_1);
	DFL_reset_POL_TIME_DEPENDENT_binary(&outC->Context_2);
}

void RPC_SE(IN_MNB_status, IN_MNB_value, I_A_status, I_A_value, SVAL, HYST, O_TEMP_status, O_TEMP_value, O_A_WARING_status, O_A_WARING_value)
{
	inC_RPC * inC = (inC_RPC*)malloc(sizeof(inC_RPC));
	outC_RPC * outC=(outC_RPC*)malloc(sizeof(outC_RPC));
	inC->IN_MNB.status = IN_MNB_status;
	inC->IN_MNB.value = IN_MNB_value;
	inC->I_A.status = I_A_status;
	inC->I_A.value = I_A_value;
	inC->SVAL = SVAL;
	inC->HYST = HYST;
	outC->O_TEMP.status = O_TEMP_status;
	outC->O_TEMP.value = O_TEMP_value;
	outC->O_A_WARNING.status = O_A_WARING_status;
	outC->O_A_WARNING.value = O_A_WARING_value;
	analog tmp;
	binary _L13;
	DFL_POL_TIME_DEPENDENT_binary(&inC->IN_MNB, &outC->Context_2);
	kcg_copy_binary(&_L13, &outC->Context_2.O1);
	kcg_copy_binary(&outC->O_TEMP, &outC->Context_2.O2);
	FSF_POL_TIME_INDEPENDENT_anolog(&_L13, &inC->I_A, &tmp);
	THC_ANA_TIME_DEPENDENT(&tmp, inC->SVAL, inC->HYST, &outC->Context_1);
	kcg_copy_binary(&outC->O_A_WARNING, &outC->Context_1.O1);
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
