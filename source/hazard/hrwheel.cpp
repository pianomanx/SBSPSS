/*=========================================================================

	hrwheel.cpp

	Author:		CRB
	Created: 
	Project:	Spongebob
	Purpose: 

	Copyright (c) 2001 Climax Development Ltd

===========================================================================*/

#ifndef __HAZARD_HRWHEEL_H__
#include "hazard\hrwheel.h"
#endif

#ifndef	__UTILS_HEADER__
#include	"utils\utils.h"
#endif

#ifndef	__PLAYER_PLAYER_H__
#include	"player\player.h"
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CNpcRisingWeightWheelHazard::init()
{
	CNpcHazard::init();

	m_rotation = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CNpcRisingWeightWheelHazard::setWaypoints( sThingHazard *ThisHazard )
{
	u16	*PntList=(u16*)MakePtr(ThisHazard,sizeof(sThingHazard));

	u16 newXPos, newYPos;

	// get init pos

	newXPos = (u16) *PntList;
	PntList++;
	newYPos = (u16) *PntList;
	PntList++;

	DVECTOR startPos;
	startPos.vx = newXPos << 4;
	startPos.vy = newYPos << 4;

	Pos = startPos;
	m_base = Pos;

	m_wheelPos.vx = newXPos;
	m_wheelPos.vy = newYPos;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CNpcRisingWeightWheelHazard::collidedWith( CThing *_thisThing )
{
	if ( m_isActive )
	{
		switch(_thisThing->getThingType())
		{
			case TYPE_PLAYER:
			{
				CPlayer *player = (CPlayer *) _thisThing;

				ATTACK_STATE playerState = player->getAttackState();

				if ( playerState == ATTACK_STATE__BUTT_BOUNCE )
				{
					m_weight->setTriggered();

					m_rotation += 128;
					m_rotation &= 4095;
				}

				break;
			}

			default:
				ASSERT(0);
				break;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CNpcRisingWeightWheelHazard::render()
{
	CHazardThing::render();

	if (canRender())
	{
		DVECTOR &renderPos=getRenderPos();

		SVECTOR rotation;
		rotation.vx = 0;
		rotation.vy = 0;
		rotation.vz = m_rotation;

		VECTOR scale;
		scale.vx = ONE;
		scale.vy = ONE;
		scale.vz = ONE;

		m_modelGfx->Render(renderPos,&rotation,&scale);
	}
}
