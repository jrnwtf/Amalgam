#include "../SDK/SDK.h"

MAKE_SIGNATURE(CClientState_GetTime, "engine.dll", "E8 ? ? ? ? 8B 43 30", 0x0);
MAKE_SIGNATURE(CClientState_GetTimeCall, "engine.dll", "E8 ? ? ? ? 0F 2F 45 04 0F 82 ? ? ? ?", 0x5);

MAKE_HOOK(CClientState_GetTime, S::CClientState_GetTime(), float,
	void* rcx)
{
	if (reinterpret_cast<uintptr_t>(_ReturnAddress()) == S::CClientState_GetTimeCall())
		return FLT_MAX;

	return CALL_ORIGINAL(rcx);
}