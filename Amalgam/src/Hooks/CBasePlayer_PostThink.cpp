#include "../SDK/SDK.h"
#include "../Features/EnginePrediction/EnginePrediction.h"

MAKE_SIGNATURE(CBasePlayer_PostThink, "client.dll", "E8 ? ? ? ? 41 8B 86 ? ? ? ? 49 8B CF", 0x0);

MAKE_HOOK(CBasePlayer_PostThink, S::CBasePlayer_PostThink(), void,
	CBasePlayer* rcx)
{
	if (F::EnginePrediction.m_bInPrediction)
		return;

	return CALL_ORIGINAL(rcx);
}