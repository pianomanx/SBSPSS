/*=========================================================================

	pjlammo.h

	Author:		PKG
	Created:	
	Project:	Spongebob
	Purpose:	

	Copyright (c) 2001 Climax Development Ltd

===========================================================================*/

#ifndef	__PICKUPS_PJLAMMO_H__
#define __PICKUPS_PJLAMMO_H__

/*----------------------------------------------------------------------
	Includes
	-------- */

#ifndef	__PICKUPS_PICKUP_H__
#include "pickups/pickup.h"
#endif


/*	Std Lib
	------- */

/*----------------------------------------------------------------------
	Tyepdefs && Defines
	------------------- */

/*----------------------------------------------------------------------
	Structure defintions
	-------------------- */

class CJellyLauncherAmmoPickup : public CBasePickup
{
public:
	virtual void		init();
	virtual void		shutdown();
	virtual void		think(int _frames);
	virtual void		render();

	virtual void		collect(class CPlayer *_player);

private:
	int					m_rattle;
};


/*----------------------------------------------------------------------
	Globals
	------- */

/*----------------------------------------------------------------------
	Functions
	--------- */

/*---------------------------------------------------------------------- */

#endif	/* __PICKUPS_PJLAMMO_H__ */

/*===========================================================================
 end */
