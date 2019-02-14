NAME = doom-nukem
SRC = src/*.c TgaReader/*.c src/menu/*.c
OBJ = $(SRC:.c = .o)
MATH = -lm 
ifeq ($(shell uname -s), Linux)
INC = -I includes -I TgaReader/includes -I src/menu/includes
SDL = -lSDL2 -lSDL2_mixer
else
INC = -I includes -I TgaReader/includes -I frameworks/SDL2_mixer.framework/Versions/A/Headers \
		-I frameworks/SDL2.framework/Versions/A/Headers
SDL = -F frameworks/ -framework SDL2 -F frameworks/ -framework SDL2_mixer
endif
CC = gcc
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(INC) $(MATH) $(SDL) -o $(NAME)
all: $(NAME)

fclean:
	/bim/rm -f $(NAME)

re: fclean all