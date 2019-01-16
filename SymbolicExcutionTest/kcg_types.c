#include "kcg_types.h"

void kcg_copy_binary(binary *T1, binary *T2)
{
	T1->status = T2->status;
	T1->value = T2->value;
}
