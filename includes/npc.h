#ifndef NPC_H
# define NPC_H

# include "tga_reader.h"

# define NPC	t_npc
# define BOSS	doom->boss

typedef struct	s_npc
{
	U8			health;
	IMAGE		*sprite;
}				t_npc;


#endif