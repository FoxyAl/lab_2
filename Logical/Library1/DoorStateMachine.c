
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library1.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void DoorStateMachine(struct DoorStateMachine* inst)
{
	/*TODO: Add your code here*/
	switch (inst->state)
	{
		case SM_INIT:
			{
				if(inst->s0==0 && inst->s1==0 && inst->s2==0 && inst->s3==0)
					inst->state=SM_UNKNOWN;
				break;
			}
		case SM_UNKNOWN:
			{
				if (inst->s0 == 1)
					inst->state=SM_CLOSE;
				if (inst->s1 == 1)
					inst->state=SM_ACC_POS;
				if (inst->s2 == 1)
					inst->state=SM_DEC_POS;
				if (inst->s3 == 1)
					inst->state=SM_OPEN;
				break;
			}
		case SM_CLOSE:
			{
				inst->speed = 0;
				if(inst->direction==1)
					inst->state=SM_ACC_POS;
				break;
			}
		case SM_ACC_NEG:
			{
				inst->speed = -200;
				if(inst->direction==1)
					inst->state=SM_DEC_POS;
				if(inst->direction==0 && inst->s2==1)
					inst->state=SM_NEG;
				break;
			}
		case SM_NEG:
			{
				inst->speed = -700;
				if(inst->direction==1)
					inst->state=SM_POS;
				if(inst->direction==0 && inst->s1==1)
					inst->state=SM_DEC_NEG;
				break;
				
			}
	
		case SM_DEC_NEG:
			{
				inst->speed = -200;
				if(inst->direction==1)
					inst->state=SM_ACC_POS;
				if(inst->direction==0 && inst->s0==1)
					inst->state=SM_CLOSE;
				break;
			}
		case SM_OPEN:
			{
				inst->speed = 0;
				if(inst->direction==0)
					inst->state=SM_ACC_NEG;
				break;
			}
		case SM_ACC_POS:
			{
				inst->speed = 200;
				if(inst->direction==0)
					inst->state=SM_DEC_NEG;
				if(inst->direction==1 && inst->s1==1)
					inst->state=SM_POS;
				break;
			}
		case SM_POS:
			{
				inst->speed = 700;
				if(inst->direction==0)
					inst->state=SM_NEG;
				if(inst->direction==1 && inst->s2==1)
					inst->state=SM_DEC_POS;
				break;
			}
	
		case SM_DEC_POS:
			{
				inst->speed = 200;
				if(inst->direction==0)
					inst->state=SM_ACC_NEG;
				if(inst->direction==1 && inst->s3==1)
					inst->state=SM_OPEN;

				break;
			}
	}
}
