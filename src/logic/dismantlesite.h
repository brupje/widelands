/*
 * Copyright (C) 2002-2004, 2006-2009, 2011 by the Widelands Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef DISMANTLESITE_H
#define DISMANTLESITE_H

#include "building.h"
#include "player.h"

#include "partially_finished_building.h"

namespace Widelands {

class Building;

/*
DismantleSite
-------------
The dismantlesite is a way to get some resources back when destroying buildings.
It has a builder as worker and will show the idle image of the original
building which gets smaller and smaller.

Every tribe has exactly one DismantleSite_Descr.
The DismantleSite_Descr's idling animation is remaining graphic that is shown under
the destructed building.
*/
struct DismantleSite_Descr : public Building_Descr {
	DismantleSite_Descr
		(char const * name, char const * descname,
		 std::string const & directory, Profile &, Section & global_s,
		 Tribe_Descr const & tribe);

	virtual Building & create_object() const;
};

class DismantleSite : public Partially_Finished_Building {
	friend struct Map_Buildingdata_Data_Packet;

	MO_DESCR(DismantleSite_Descr);

public:
	DismantleSite(const DismantleSite_Descr & descr);

	char const * type_name() const throw () {return "dismantlesite";}
	virtual int32_t get_size() const throw ();
	virtual uint32_t get_playercaps() const throw ();
	virtual uint32_t get_ui_anim() const;
	virtual std::string get_statistics_string();
	uint32_t get_built_per64k() const;

	virtual bool burn_on_destroy();
	virtual void init   (Editor_Game_Base &);


	virtual bool get_building_work(Game &, Worker &, bool success);

protected:
	virtual void create_options_window
		(Interactive_GameBase &, UI::Window * & registry);

	virtual void draw(Editor_Game_Base const &, RenderTarget &, FCoords, Point);

private:
	// SirVer TODO: this is in some form needed
	//SirVer Player::Constructionsite_Information * m_info; // player point of view for the gameview
};

}

#endif
