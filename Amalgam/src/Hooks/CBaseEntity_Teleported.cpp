#include "../SDK/SDK.h"

MAKE_SIGNATURE(CBaseEntity_Teleported, "client.dll", "48 89 5C 24 08 44 8B 81", 0x0);
MAKE_SIGNATURE(CBaseEntity_TeleportedCall, "client.dll", "84 C0 75 18 41 0F B6 86 AC 00 00 00", 0x0);

MAKE_HOOK(CBaseEntity_Teleported, S::CBaseEntity_Teleported(), bool,
	CBaseEntity* rcx)
{
	if (reinterpret_cast<uintptr_t>(_ReturnAddress()) == S::CBaseEntity_TeleportedCall())
		return true;

	return CALL_ORIGINAL(rcx);
}