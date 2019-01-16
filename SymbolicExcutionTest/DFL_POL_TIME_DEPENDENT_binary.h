#ifndef _DFL_POL_TIME_DEPENDENT_binary_H_
#define _DFL_POL_TIME_DEPENDENT_binary_H_
#include"kcg_types.h"
typedef struct
{
	binary  O1;
	binary O2;
	kcg_bool init;
	kcg_bool _L24;
}outC_DFL_POL_TIME_DEPENDENT_binary;
extern void DFL_POL_TIME_DEPENDENT_binary(binary *I1,outC_DFL_POL_TIME_DEPENDENT_binary *outC);
extern void DFL_reset_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC);
#endif // !_DFL_POL_TIME_DEPENDENT_binary_H_
