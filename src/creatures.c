#include "creatures.h"
etype_t player_etype={
	.name="Player",
	.symbol='@',
	.color=LCYAN,
	.hp={50,100},
	.res={5,15},
	.agi={5,15},
	.wis={5,15},
	.str={5,15},
	.flags=PERSISTS|SOLID|MOBILE,
	.spells={
		&heal_self_spell,
		&magic_missile_spell,
		&freeze_spell,
		&thaw_spell,
	},
	.spawn_flags=NONE,
};
etype_t human_etype={
	.name="Human",
	.symbol='U',
	.color=CYAN,
	.hp={50,100},
	.res={5,15},
	.agi={5,15},
	.wis={5,15},
	.str={5,15},
	.flags=PERSISTS|SOLID|MOBILE,
	.loot_table={
		.items={&sword,&gold},
		.amounts={1,10},
		.chances={50,100},
	},
	.spells={
		&heal_self_spell,
	},
	.enemies={
		&monster_etype,
	},
	.spawn_flags=TOWN|INSIDE|OUTSIDE,
	.elev={1,100},
	.quota={5,AREA/128},
};
etype_t monster_etype={
	.name="Monster",
	.symbol='&',
	.color=DGRAY,
	.hp={50,100},
	.res={5,15},
	.agi={5,15},
	.wis={5,10},
	.str={10,15},
	.flags=SOLID|MOBILE,
	.loot_table={
		.items={&gold},
		.amounts={25},
		.chances={50},
	},
	.spells={
		&magic_missile_spell,
	},
	.friends={
		&monster_etype,
	},
	.enemies={
		&player_etype,
		&human_etype,
		&mage_etype,
	},
	.spawn_flags=TOWN|WILDERNESS|DUNGEON|OUTSIDE,
	.elev={1,100},
	.quota={8,AREA/128},
};
etype_t toad_etype={
	.name="Toad",
	.symbol='<',
	.color=GREEN,
	.hp={5,10},
	.res={1,5},
	.agi={15,20},
	.wis={1,2},
	.str={1,5},
	.flags=SOLID|MOBILE,
	.friends={
		&toad_etype,
	},
	.spawn_flags=WILDERNESS|OUTSIDE,
	.elev={51,60},
	.quota={8,AREA/128},
};
etype_t mage_etype={
	.name="Mage",
	.symbol='M',
	.color=PURPLE,
	.hp={50,75},
	.res={5,10},
	.agi={5,15},
	.wis={15,20},
	.str={5,10},
	.flags=PERSISTS|SOLID|MOBILE,
	.loot_table={
		.items={&gold},
		.amounts={20},
		.chances={100},
	},
	.spells={
		&heal_self_spell,
		&magic_missile_spell,
		&raise_dead_spell,
	},
	.friends={
		&mage_etype,
		&player_etype,
	},
	.enemies={
		&monster_etype,
	},
	.spawn_flags=TOWN|INSIDE,
	.elev={1,100},
	.quota={2,AREA/128},
};
etype_t dragon_etype={
	.name="Dragon",
	.symbol='D',
	.color=GREEN,
	.hp={150,200},
	.res={15,20},
	.agi={15,20},
	.wis={15,20},
	.str={15,20},
	.flags=PERSISTS|SOLID|MOBILE,
	.loot_table={
		.items={&gold},
		.amounts={200},
		.chances={100},
	},
	.spells={
		&dragonfire_spell,
	},
	.enemies={
		&player_etype,
		&human_etype,
		&mage_etype,
		&monster_etype,
	},
	.spawn_flags=TOWN|WILDERNESS|OUTSIDE,
	.elev={65,100},
	.quota={0,1},
};
