##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_hunter
##

SRC		=	src/my_defender.c		\
			src/lib_graphic.c		\
			src/lib_graphic2.c		\
			src/init.c			\
			src/title.c			\
			src/display.c			\
			src/display2.c			\
			src/display3.c			\
			src/display4.c			\
			src/event.c			\
			src/slider.c			\
			src/play.c			\
			src/waves.c			\
			src/life.c			\
			src/waves2.c			\
			src/tower.c			\
			src/animated_sprite.c		\
			src/endgame.c			\
			src/lib_graphic3.c		\
			src/pause.c			\
			src/music.c			\
			src/best_score.c		\
			src/init2.c			\
			src/init_pos.c			\
			src/init_tex.c			\
			src/init_counter.c		\
			src/best_score2.c		\
			src/waves1.c			\
			src/waves1_1.c			\
			src/waves2_1.c			\

CPPFLAGS	=	-I ./include

LDFLAGS		=	-L ./lib -lmy

GRAPHICAL	=	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window

OBJ		=	$(SRC:.c=.o)

NAME		=	my_defender

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LDFLAGS) $(GRAPHICAL)

clean:
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./lib/my
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
