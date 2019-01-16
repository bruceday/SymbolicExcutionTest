#include<stdio.h>
//#include "RPC.h"
#include<stdlib.h>
#include <windows.h> 
#include"THC_ANA_TIME_DEPENDENT.h"

void main()
{
		inC_RPC *inC = (inC_RPC*)malloc(sizeof(inC_RPC));
		outC_RPC *outC = (outC_RPC*)malloc(sizeof(outC_RPC));
		RPC_reset(outC);
		inC->IN_MNB.status = kcg_true;
		inC->IN_MNB.value = kcg_true;
		inC->I_A.status = kcg_false;
		inC->I_A.value = 20.0;
		inC->SVAL = 190.0;
		inC->HYST = 130.0;
		for (double i = 0; i < 50; i++)
			for (double j = 0; j < 50; j++)
				for (double k = 0; k < 50; k++)
				{
					inC->I_A.value = i;
					inC->SVAL = j;
					inC->HYST = k;
					RPC(inC, outC);			
					printf("_L24:%d--", outC->Context_2._L24);
					printf("O_TEMP_STATUS:%d--", outC->O_TEMP.status);
					printf("O_TEMP_VALUE:%d--", outC->O_TEMP.value);
					printf("O_A_WARNING_STATUS:%d--", outC->O_A_WARNING.status);
					printf("O_A_WARNING_VALUE:%d\n", outC->O_A_WARNING.value);
				}
	}
	//analog *I1 = (analog*)malloc(sizeof(analog));
	//outC_THC_ANA_TIME_DEPENDENT * outC = (outC_THC_ANA_TIME_DEPENDENT*)malloc(sizeof(outC_THC_ANA_TIME_DEPENDENT));
	//kcg_real SVAL = 190;
	//kcg_real HYST = 130;
	//I1->status = kcg_true;
	//I1->value = 5;
	//kcg_bool tmp_status = kcg_false;
	//kcg_bool tmp_value = kcg_false;
	//THC_reset_ANA_TIME_DEPENDENT(outC);
	//for (double i = 0; i < 30; i++)
	//	for (double j = 0; j < 30; j++)
	//		for (double k = 0; k < 3000; k++)
	//		{
	//			SVAL = i;
	//			HYST = j;
	//			I1->value = k;
	//			THC_ANA_TIME_DEPENDENT(I1, SVAL, HYST, outC);
	//			if (tmp_status != outC->O1.status || tmp_value != outC->O1.value) {
	//				printf("SVAL:%f---", SVAL);
	//				printf("HYST:%f---", HYST);
	//				printf("I1_value:%f---", I1->value);
	//				printf("status:%d---", outC->O1.status);
	//				printf("value:%d\n", outC->O1.value);
	//			}
	//			tmp_status = outC->O1.status;
	//			tmp_value = outC->O1.value;
	//		}
}
