#include "FSF_POL_TIME_INDEPENDENT_analog.h"
#include"kcg_const.h"

void FSF_POL_TIME_INDEPENDENT_anolog(binary * I1, analog * I2, analog * O1)
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
