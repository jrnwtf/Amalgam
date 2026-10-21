#include "../SDK/SDK.h"

MAKE_HOOK(CPrediction_Update, U::Memory.GetVirtual(I::Prediction, 21), void,
	CPrediction* rcx, bool receivedUpdate, bool validFrame, int incomingAcknowledged, int outgoingCommand)
{
	return CALL_ORIGINAL(rcx, true, validFrame, incomingAcknowledged, outgoingCommand);
}