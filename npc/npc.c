# include "doom_nukem.h"

DN_ERROR		load_npc(ENGINE *doom)
{
	if (!(BOSS.sprite = read_tga("images/npc/boss.tga")))
		return (IMAGE_ERROR);
}

void			free_npc(ENGINE *doom)
{
	if (BOSS.sprite)
	{
		free(BOSS.sprite->pixels);
		free(BOSS.sprite);
	}
}

