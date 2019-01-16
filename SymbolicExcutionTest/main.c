#include<stdio.h>
#include "RPC.h"
#include<stdlib.h>
#include <klee/klee.h>

void RPC_SE(IN_MNB_status, IN_MNB_value, I_A_status, I_A_value, SVAL, HYST, O_TEMP_status, O_TEMP_value, O_A_WARING_status, O_A_WARING_value)
{
	inC_RPC * inC = (inC_RPC*)malloc(sizeof(inC_RPC));
	outC_RPC * outC = (outC_RPC*)malloc(sizeof(outC_RPC));
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
	//kcg_copy_binary(&outC->O_A_WARNING, &outC->Context_1.O1);
	outC->O_A_WARNING.status = outC->Context_1.O1.status;
	outC->O_A_WARNING.value = outC->Context_1.O1.value;
}

void main()
{
	inC_RPC inC;
	outC_RPC outC;

	kcg_bool IN_MNB_status;
	kcg_bool IN_MNB_value;
	kcg_bool I_A_status;
	kcg_bool I_A_value;
	kcg_real SVAL;
	kcg_real HYST;
	kcg_bool O_TEMP_status;
	kcg_bool O_TEMP_value;
	kcg_bool O_A_WARING_status;
	kcg_bool O_A_WARING_value;
	klee_make_symbolic(&IN_MNB_status, sizeof(IN_MNB_status), "IN_MNB_status");
	klee_make_symbolic(&IN_MNB_value, sizeof(IN_MNB_value), "IN_MNB_value");
	klee_make_symbolic(&I_A_status, sizeof(I_A_status), "I_A_status");
	klee_make_symbolic(&I_A_value, sizeof(I_A_value), "I_A_value");
	klee_make_symbolic(&SVAL, sizeof(SVAL), "SVAL");
	klee_make_symbolic(&HYST, sizeof(HYST), "HYST");
	klee_make_symbolic(&O_TEMP_status, sizeof(O_TEMP_status), "O_TEMP_status");
	klee_make_symbolic(&O_TEMP_value, sizeof(O_TEMP_value), "O_TEMP_value");
	klee_make_symbolic(&O_A_WARING_status, sizeof(O_A_WARING_status), "O_A_WARING_status");
	klee_make_symbolic(&O_A_WARING_value, sizeof(O_A_WARING_value), "O_A_WARING_value");
	//RPC_reset(O_TEMP_status, O_TEMP_value);
	RPC_SE(IN_MNB_status,IN_MNB_value,I_A_status,I_A_value,SVAL,HYST,O_TEMP_status, O_TEMP_value, O_A_WARING_status, O_A_WARING_value);
}
