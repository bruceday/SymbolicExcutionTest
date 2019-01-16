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
	klee_make_symbolic(&inC.IN_MNB.status, sizeof(inC.IN_MNB.status), "IN_MNB_status");
	klee_make_symbolic(&inC.IN_MNB.value, sizeof(inC.IN_MNB.value), "IN_MNB_value");
	klee_make_symbolic(&inC.I_A.status, sizeof(inC.I_A.status), "I_A_status");
	klee_make_symbolic(&inC.I_A.value, sizeof(inC.I_A.value), "I_A_value");
	klee_make_symbolic(&inC.SVAL, sizeof(inC.SVAL), "SVAL");
	klee_make_symbolic(&inC.HYST, sizeof(inC.HYST), "HYST");
	klee_make_symbolic(&outC.O_TEMP.status, sizeof(outC.O_TEMP.status), "O_TEMP_status");
	klee_make_symbolic(&outC.O_TEMP.value, sizeof(outC.O_TEMP.value), "O_TEMP_value");
	klee_make_symbolic(&outC.O_A_WARNING.status, sizeof(outC.O_A_WARNING.status), "O_A_WARING_status");
	klee_make_symbolic(&outC.O_A_WARNING.value, sizeof(outC.O_A_WARNING.value), "O_A_WARING_value");
	RPC_reset(&outC);
	RPC(&inC, &outC);
}
