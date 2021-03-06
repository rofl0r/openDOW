#ifndef WEAPON_H
#define WEAPON_H

#include <stdint.h>
#include "wavesounds.h"

enum __attribute__((__packed__)) ammo_id {
	AMMO_45ACP = 0,
	AMMO_9MMPARABELLUM,
	AMMO_556,
	AMMO_762,
	AMMO_10MM,
	AMMO_ROCKET83MM,
	AMMO_ROCKET40MM,
	AMMO_K200GRENADE40MM,
	AMMO_GAS,
	AMMO_GRENADE,
	AMMO_MAX,
	AMMO_INVALID = AMMO_MAX
};

struct ammo {
	int mm;
	int rounds;
	int price;
};

enum weapon_flags {
	WF_AUTOMATIC = 1,
	WF_MUZZLEFLASH = 2,
};

enum __attribute__((__packed__)) shot_type {
	ST_BULLET = 0,
	ST_GRENADE,
	ST_LAUNCHER,
	ST_FLAMES,
};

struct weapon {
	float bullet_speed;
	uint16_t rpm;
	uint16_t price;
	enum ammo_id ammo;
	enum wavesound_id sound;
	enum shot_type shot;
	uint8_t flags;
	uint8_t range;
};

enum __attribute__((__packed__)) weapon_id {
	WP_COLT45 = 0,
	WP_BROWNING,
	WP_SA80,
	WP_MP5,
	WP_UZI,
	WP_STEYR,
	WP_AK47,
	WP_M16A2,
	WP_M203,
	WP_RPK,
	WP_L7A2,
	WP_HK21,
	WP_M60,
	WP_MG42,
	WP_M134,
	WP_RPG7,
	WP_LAW,
	WP_MAW,
	WP_ABC,
	WP_GRENADES,
	WP_MAX,
	WP_INVALID = WP_MAX
};

extern const struct weapon weapons[];
extern const struct ammo ammunition[];
const char* weapon_name(enum weapon_id id);
const char* ammo_name(enum ammo_id id);

#pragma RcB2 DEP "weapon.c"

#endif
