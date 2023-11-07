
{REDUND_ERROR} FUNCTION_BLOCK LedStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT;
	END_VAR
	VAR_OUTPUT
		led1 : BOOL;
		led2 : BOOL;
		led3 : BOOL;
		led4 : BOOL;
		timer : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK DoorStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		state : UINT;
		s0 : BOOL;
		s1 : BOOL;
		s2 : BOOL;
		s3 : BOOL;
		direction : BOOL;
	END_VAR
	VAR_OUTPUT
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK DriveStateMachine (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		STATE : UINT;
		ENABLE : BOOL;
	END_VAR
	VAR_OUTPUT
		CMD : UINT;
		speed : INT;
	END_VAR
END_FUNCTION_BLOCK
