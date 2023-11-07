
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
void DriveStateMachine(struct DriveStateMachine* inst)
{
	/*TODO: Add your code here*/
	UINT mask = inst->STATE & 0x6f;
	if(!inst->ENABLE)
	{
		inst->CMD = CMD_SHUTDOWN;
	}
	else
	{
		switch (mask)
		{
			case STATE_DISABLED:			
				inst->CMD = CMD_SHUTDOWN;
				break;
			
			case STATE_READY:
				inst->CMD = CMD_ENABLED;
				break;
			
			case STATE_SWITCHED_ON:
				inst->CMD = CMD_SWITCHED_ON;
				break;
		}
	}
}
