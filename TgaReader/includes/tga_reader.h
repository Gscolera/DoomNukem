#ifndef TGA_READER_H
# define TGA_READER_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <SDL2/SDL.h>
# define TGA			t_tga
# define IMAGE			t_image
# define U32			unsigned int
# define U8				unsigned char

typedef struct			s_image
{
	U32					width;
	U32					height;
	U32					length;
	U32					*pixels;
}						t_image;

typedef struct			s_tga
{
	U32					size;
	U8					data_type;
	U8					*data;
	U8					*ptr;
	IMAGE				*image;
}						t_tga;

IMAGE					*read_tga(char *path);
void					free_image(IMAGE *image);
bool					open_error(char *path);
bool					mem_error(TGA *tga);

#endif