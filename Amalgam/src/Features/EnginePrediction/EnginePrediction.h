#pragma once
#include "../../SDK/SDK.h"

struct DatamapRestore_t
{
	byte* m_pData = nullptr;
	size_t m_iSize = 0;
};

struct RestoreInfo_t
{
	Vec3 m_vOrigin = {};
	Vec3 m_vMins = {};
	Vec3 m_vMaxs = {};
};

class CEnginePrediction
{
private:
	void Simulate(CTFPlayer* pLocal, CUserCmd* pCmd);

	CMoveData m_tMoveData = {};
	DatamapRestore_t m_tLocal = {};
	std::unordered_map<CTFPlayer*, RestoreInfo_t> m_mRestore = {};
	int m_nSeedCommandNumber = -1;
	int m_iSeed = -1;
	int m_iBatchDepth = 0;
	bool m_bBatchAdjusted = false;

public:
	void Start(CTFPlayer* pLocal, CUserCmd* pCmd);
	void End(CTFPlayer* pLocal, CUserCmd* pCmd);

	void Unload();

	void AdjustPlayers(CBaseEntity* pLocal);
	void RestorePlayers();

	float GetTargetPredictZVelocity() const;
	bool IsTargetPredictZVelocity(float flVz, float flEpsilon = 0.1f) const;

	void BeginBatch() 
	{
		m_iBatchDepth++; 
	}

	void EndBatch()
	{
		if (--m_iBatchDepth <= 0)
		{
			m_iBatchDepth = 0;
			if (m_bBatchAdjusted)
			{
				RestorePlayers();
				m_bBatchAdjusted = false;
			}
		}
	}

	bool m_bInPrediction = false;

	int m_nOldTickCount = 0;
	float m_flOldCurrentTime = 0.f;
	float m_flOldFrameTime = 0.f;

	Vec3 m_vOrigin = {};
	Vec3 m_vVelocity = {};
	Vec3 m_vDirection = {};
	Vec3 m_vAngles = {};
};

ADD_FEATURE(CEnginePrediction, EnginePrediction);