NAME		=	BSQ
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
IFLAGS		=	-I$(INC_PATH)
RM			=	rm -rf
INC_PATH	=	includes
INC_NAME	=	bsq.h \
				get_next_line.h

SRC_PATH	=	srcs
SRC_NAME	=	main.c \
				map_parser.c \
				square.c \
				map_utils.c \
				get_next_line.c \
				get_next_line_utils.c

INC			=	$(addprefix $(INC_PATH)/, $(INC_NAME))
SRC			=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ			=	$(SRC:.c=.o)
.SUFFIXES:		.c .o .h

all			:	$(NAME)

$(NAME)		: 	$(OBJ) $(INC)
				$(CC) -o $(NAME) $(IFLAGS) $(OBJ)

%.o: 			%.c
				$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			: 	fclean all

PHONY: 		all fclean clean re
