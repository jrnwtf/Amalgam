#include "../SDK/SDK.h"

MAKE_SIGNATURE(CMultiPlayerAnimState_ComputePoseParamAimYaw, "client.dll", "40 53 55 56 57 48 83 EC 78 48 8B 01", 0x0);

MAKE_HOOK(CMultiPlayerAnimState_ComputePoseParamAimYaw, S::CMultiPlayerAnimState_ComputePoseParamAimYaw(), void,
	void* rcx, CStudioHdr* pStudioHdr, CTFPlayer* localPlayer)
{
	CALL_ORIGINAL(rcx, pStudioHdr, localPlayer);

	CMultiPlayerAnimState* const animState = reinterpret_cast<CMultiPlayerAnimState*>(rcx);

	if (!animState)
		return;

	if (!localPlayer)
		return;

	QAngle angle = localPlayer->GetAbsAngles();
	angle.y = animState->m_flCurrentFeetYaw;
	localPlayer->SetAbsAngles(angle);
}