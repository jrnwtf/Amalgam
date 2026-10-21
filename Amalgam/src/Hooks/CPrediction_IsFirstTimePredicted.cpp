#include "../SDK/SDK.h"

MAKE_SIGNATURE(CPrediction_IsFirstTimePredicted, "client.dll", "84 C0 74 06 FF 87 98 0E 00 00", 0x0);

MAKE_HOOK(CPrediction_IsFirstTimePredicted, U::Memory.GetVirtual(I::Prediction, 15), bool,
	CPrediction* rcx)
{

	if (reinterpret_cast<uintptr_t>(_ReturnAddress()) == S::CPrediction_IsFirstTimePredicted())
		return true;

	return CALL_ORIGINAL(rcx);
}