#ifndef GUN_H
# define GUN_H

# include "tga_reader.h"
# include "definitions.h"
# ifdef __linux__
#  include <SDL2/SDL_mixer.h>
# else
#  include "SDL_mixer.h"
# endif
/*
**************GUN 	DEFINITIONS*****************************************
*/
# define STRUCT_GUN		t_gun
# define GUN			doom->gun
# define GUN_SPRITE		doom->gun.sprite
# define DEFORMATION	doom->gun.deformation
# define GUN_FS			doom->gun.start
# define GUN_FE			doom->gun.end
# define SHOT_SOUND		doom->gun.shot

typedef	struct		s_gun
{
	IMAGE			*sprite;
	Mix_Chunk		*shot;
	U8				ammo;
	U8				frames;
	double			deformation;
	double			start;
	double			end;
}					t_gun;


#endif