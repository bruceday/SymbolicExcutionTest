#include<stdio.h>
#include "RPC.h"
#include"kcg_const.h"
#include<stdlib.h>
#include <klee/klee.h>

void kcg_copy_binary_SE(binary *T1, binary *T2)
{
	T1->status = T2->status;
	T1->value = T2->value;
}


void THC_ANA_TIME_DEPENDENT_SE(analog * I1, kcg_real SVAL, kcg_real HYST, outC_THC_ANA_TIME_DEPENDENT * outC)
{
	kcg_bool tmp1;
	kcg_bool tmp;
	SSM_ST_SM1 SM1_state_sel;
	SSM_ST_SM1 SM1_state_act;
	if (outC->init) {
		SM1_state_sel = SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_sel = outC->SM1_state_nxt;
	}
	switch (SM1_state_sel)
	{
	case SSM_st_Init_SM1:
		SM1_state_act = SSM_st_Init_SM1;
		break;
	case SSM_st_NO_FAULT_SM1:
		if ((*I1).status) {
			SM1_state_act = SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_FAULT_SM1:
		if ((*I1).status) {
			SM1_state_act = SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = SSM_st_NO_FAULT_SM1;
		}
		break;
	}
	switch (SM1_state_act)
	{
	case SSM_st_Init_SM1:
		if ((*I1).status == NO_FAULT) {
			tmp = NO_FAULT;
		}
		else
		{
			tmp = FAULT;
		}
		outC->O1.value = VALUE_0;
		outC->O1.status = tmp;
		outC->OutputValue = VALUE_0;
		if ((*I1).status) {
			outC->SM1_state_nxt = SSM_st_FAULT_SM1;
		}
		else
		{
			outC->SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_NO_FAULT_SM1:
		if ((*I1).value > SVAL) {
			tmp1 = VALUE_1;
		}
		else if ((*I1).value < SVAL - HYST)
		{
			tmp1 = VALUE_0;
		}
		else
		{
			tmp1 = outC->OutputValue;
		}
		outC->O1.value = tmp1;
		outC->O1.status = NO_FAULT;
		outC->OutputValue = tmp1;
		outC->SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		break;
	case SSM_st_FAULT_SM1:
		outC->O1.value = outC->OutputValue;
		outC->O1.status = FAULT;
		outC->SM1_state_nxt = SSM_st_FAULT_SM1;
		break;
	}
	outC->init = kcg_false;
}


void FSF_POL_TIME_INDEPENDENT_anolog_SE(binary * I1, analog * I2, analog * O1)
{
	(*O1).value = (*I2).value;
	if ((*I2).status | (*I1).value | (*I1).status)
	{
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}


void DFL_POL_TIME_DEPENDENT_binary_SE(binary * I1, outC_DFL_POL_TIME_DEPENDENT_binary * outC)
{
	outC->O1.status = NO_FAULT;
	outC->O2.status = NO_FAULT;
	if ((*I1).status) {
		if (outC->init) {
			outC->_L24 = VALUE_0;
		}
		outC->O2.value = VALUE_1;
	}
	else
	{
		outC->_L24 = (*I1).value;
		outC->O2.value = VALUE_0;
	}
	outC->O1.value = outC->_L24;
	outC->init = kcg_false;
}

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
	DFL_POL_TIME_DEPENDENT_binary_SE(&inC->IN_MNB, &outC->Context_2);
	kcg_copy_binary_SE(&_L13, &outC->Context_2.O1);
	kcg_copy_binary_SE(&outC->O_TEMP, &outC->Context_2.O2);
	FSF_POL_TIME_INDEPENDENT_anolog_SE(&_L13, &inC->I_A, &tmp);
	THC_ANA_TIME_DEPENDENT_SE(&tmp, inC->SVAL, inC->HYST, &outC->Context_1);
	kcg_copy_binary_SE(&outC->O_A_WARNING, &outC->Context_1.O1);
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
