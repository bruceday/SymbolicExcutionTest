#include<stdio.h>
#include "RPC.h"
#include<stdlib.h>
#include <klee/klee.h>

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
