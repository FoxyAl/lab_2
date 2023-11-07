
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{

	DoorStateMachine(&DoorSM);
	driveSM.speed = DoorSM.speed;
	DriveStateMachine(&driveSM);
	ledSM.state = DoorSM.state;
	LedStateMachine(&ledSM);
}
