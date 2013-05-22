#pragma once

//#include "iocport.h"
#include "MagicProcess.h"

#include "extern.h"
#include "../shared/STLMap.h"

class MAP;
class CUser  
{
public:
	CMagicProcess m_MagicProcess;

	char m_strUserID[MAX_ID_SIZE+1];	// 캐릭터의 이름
	short	m_iUserId;					// User의 번호
	uint8	m_bLive;					// 죽었니? 살았니?

	float			m_curx;				// 현재 X 좌표
	float			m_cury;				// 현재 Y 좌표
	float			m_curz;				// 현재 Z 좌표
	float			m_fWill_x;			// 다음 X 좌표
	float			m_fWill_y;			// 다음 Y 좌표
	float			m_fWill_z;			// 다음 Z 좌표
	short			m_sSpeed;			// 유저의 스피드	
	uint8 			m_curZone;			// 현재 존
	MAP *			m_pMap;

	uint8	m_bNation;						// 소속국가
	uint8	m_bLevel;						// 레벨

	short	m_sHP;							// HP
	short	m_sMP;							// MP
	short	m_sMaxHP;						// HP
	short	m_sMaxMP;						// MP

	uint8	m_state;						// User의 상태

	short	m_sRegionX;						// 현재 영역 X 좌표
	short	m_sRegionZ;						// 현재 영역 Z 좌표
	short	m_sOldRegionX;					// 이전 영역 X 좌표
	short	m_sOldRegionZ;					// 이전 영역 Z 좌표

	uint8	m_bResHp;						// 회복량
	uint8	m_bResMp;
	uint8	m_bResSta;

	uint8    m_byNowParty;				// 파티중이면 1, 부대중이면 2, 둘다 아니면 0
	uint8	m_byPartyTotalMan;			// 파티 맺은 총 구성 인원수 
	short   m_sPartyTotalLevel;			// 파티 맺은 사람의 총 레벨
	short	m_sPartyNumber;				// 파티 번호

	short	m_sHitDamage;				// Hit
	float	m_fHitrate;					// 공격 민첩률
	float	m_fAvoidrate;				// 방어 민첩률
	short	m_sAC;						// 방어율
	short   m_sItemAC;                  // 아이템 방어률
	

	short  m_sSurroundNpcNumber[8];		// Npc 다굴~

	uint8   m_byIsOP;					// 운영자인지를 판단..
	uint8	m_bInvisibilityType;

	long   m_lUsed;						// 포인터 사용유무.. (1:사용중.. 접근 허락치 않음. 0:사용해도 무방)

	bool		m_bLogOut;				// Logout 중인가?

	uint8    m_bMagicTypeLeftHand;			// The type of magic item in user's left hand  
	uint8    m_bMagicTypeRightHand;			// The type of magic item in user's right hand
	short   m_sMagicAmountLeftHand;         // The amount of magic item in user's left hand
	short	m_sMagicAmountRightHand;        // The amount of magic item in user's left hand

public:
	short GetMagicDamage(int damage, short tid);
	void Initialize();
	void InitNpcAttack();
	void Attack(int sid, int tid);	// ATTACK
	void SetDamage(int damage, int tid);				// user damage
	void Dead(int tid, int nDamage);					// user dead
	void SetExp(int iNpcExp, int iLoyalty, int iLevel);		// user exp
	void SetPartyExp(int iNpcExp, int iLoyalty, int iPartyLevel, int iMan);		// user exp
	short GetDamage(int tid, int magicid=0);
	uint8 GetHitRate(float rate);
	int IsSurroundCheck(float fX, float fY, float fZ, int NpcID);
	void HealMagic();
	void HealAreaCheck(int rx, int rz);

	void SendAttackSuccess(short tid, uint8 result, short sDamage, int nHP=0, short sAttack_type=1, uint8 type = 1, short sid = -1);
	void SendHP();												// user의 HP
	void SendExp(int iExp, int iLoyalty, int tType = 1);

	INLINE MAP * GetMap() { return m_pMap; };

	CUser();
	virtual ~CUser();
};
