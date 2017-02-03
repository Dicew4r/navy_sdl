##
## Makefile for makefile in /home/Bernard/Piscine/CPool_Day10
## 
## Made by Erwan Bernard
## Login   <Bernard@epitech.net>
## 
## Started on  Fri Oct 14 15:43:56 2016 Erwan Bernard
## Last update Fri Feb 03 01:51:44 2017 Erwan Bernard
##

NAME		= navy

SRCS		= src/main.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -rf

GCC		= gcc -o

CFLAGS = -Iincludes/ -Wall -Wextra `sdl-config --cflags --libs`

all : $(NAME) coffee

$(NAME):$(OBJS)
	$(GCC) $(NAME) $(OBJS) `sdl-config --cflags --libs` -lSDL_ttf

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re : fclean all

coffee :
	@echo "     ______________________"
	@echo "    (___________           |"
	@echo "      [XXXXX]   |          |"
	@echo " __  /~~~~~~~\  |          |"
	@echo "/  \|@@@@@@@@@\ |          |"
	@echo "\   |@@@@@@@@@@||          |"
	@echo "    \@@@@@@@@@@||  ______  |"
	@echo "     \@@@@@@@@/ | |on|off| |"
	@echo "    __\@@@@@@/__|  ~~~~~~  |"
	@echo "   (____________|__________|"
	@echo "   |_______________________|"

.PHONY: all clean fclean re
.SILENT: all clean fclean re
