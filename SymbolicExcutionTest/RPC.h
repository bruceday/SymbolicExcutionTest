#ifndef _RPC_H_
#define _RPC_H_
#include "kcg_types.h"
#include "FSF_POL_TIME_INDEPENDENT_analog.h"
#include "THC_ANA_TIME_DEPENDENT.h"
#include "DFL_POL_TIME_DEPENDENT_binary.h"

typedef struct{
	binary IN_MNB;
	kcg_real SVAL;
	kcg_real HYST;
	analog I_A;
}inC_RPC;

typedef struct{
	binary O_TEMP;
	binary O_A_WARNING;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_2;
	outC_THC_ANA_TIME_DEPENDENT Context_1;
}outC_RPC;

extern void RPC(inC_RPC *inC, outC_RPC *outC);

extern void RPC_reset(outC_RPC *outC);

#endif // !_RPC_H_
