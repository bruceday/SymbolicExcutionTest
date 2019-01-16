#include "THC_ANA_TIME_DEPENDENT.h"
#include"kcg_const.h"


void THC_reset_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT * outC)
{
	outC->init = kcg_true;
}


void THC_ANA_TIME_DEPENDENT(analog * I1, kcg_real SVAL, kcg_real HYST, outC_THC_ANA_TIME_DEPENDENT * outC)
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
		else if((*I1).value<SVAL-HYST)
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
