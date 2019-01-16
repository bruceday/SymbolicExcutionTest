#include "DFL_POL_TIME_DEPENDENT_binary.h"
#include "kcg_const.h"


void DFL_reset_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC)
{
	outC->init = kcg_true;
}

void DFL_POL_TIME_DEPENDENT_binary(binary * I1, outC_DFL_POL_TIME_DEPENDENT_binary * outC)
{
	outC->O1.status = NO_FAULT;
	outC->O2.status = NO_FAULT;
	if ((*I1).status){
		if (outC->init){
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