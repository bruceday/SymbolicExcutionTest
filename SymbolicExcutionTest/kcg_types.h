#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#ifndef kcg_int
#define kcg_int kcg_int
typedef int kcg_int;
#endif // kcg_int

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif // !kcg_bool

#ifndef kcg_real
#define kcg_real kcg_real
typedef double kcg_real;
#endif // !kcg_real

#ifndef kcg_true
#define kcg_true ((kcg_bool)1)
#endif // !kcg_true

#ifndef kcg_false
#define kcg_false ((kcg_bool)0)
#endif // !kcg_false

typedef struct analog
{
	kcg_real value;
	kcg_bool status;
}analog;

typedef struct binary
{
	kcg_bool value;
	kcg_bool status;
}binary;

typedef enum
{
	SSM_st_Init_SM1,
	SSM_st_NO_FAULT_SM1,
	SSM_st_FAULT_SM1
}SSM_ST_SM1;



void kcg_copy_binary(binary *T1,binary *T2);



#endif // !_KCG_TYPES_H_
