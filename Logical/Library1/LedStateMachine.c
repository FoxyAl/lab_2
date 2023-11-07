
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
void LedStateMachine(struct LedStateMachine* inst)
{
	/*TODO: Add your code here*/

	switch(inst->state)
	{
		case SM_INIT:
			{
				
				break;
			}
		
		case SM_UNKNOWN:
			{
				if(inst->timer%10==0)
				{
					inst->led1=!inst->led1;
					inst->led2=!inst->led2;
					inst->led3=!inst->led3;
					inst->led4=!inst->led4;
				}
				break;
			}
		
		case SM_CLOSE:
			{
				inst->led1=1;
				inst->led2=1;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case SM_NEG:
			{
				inst->led1=0;
				inst->led2=0;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case SM_ACC_NEG:
			{
				inst->led1=0;
				inst->led2=0;
				inst->led3=0;
				inst->led4=1;
				break;
			}
		case SM_DEC_NEG:
			{
				inst->led1=0;
				inst->led2=1;
				inst->led3=1;
				inst->led4=1;
				break;
			}
	
		case SM_OPEN:
			{
				inst->led1=0;
				inst->led2=0;
				inst->led3=0;
				inst->led4=0;
				break;
			}
		case SM_POS:
			{
				inst->led1=0;
				inst->led2=0;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case SM_ACC_POS:
			{
				inst->led1=0;
				inst->led2=1;
				inst->led3=1;
				inst->led4=1;
				break;
			}
		case SM_DEC_POS:
			{
				inst->led1=0;
				inst->led2=0;
				inst->led3=0;
				inst->led4=1;
				break;
			}
	}
	inst->timer++;
}
