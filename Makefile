NAME		=	bsq
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
IFLAGS		=	-I$(INC_PATH)
RM			=	rm -rf
INC_PATH	=	includes
INC_NAME	=	map.h \
				map_parser.h \
				square.h

SRC_PATH	=	srcs
SRC_NAME	=	main.c \
				map_parser.c \
				square.c \
				square_maths.c \
				struct_assigner.c \

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

.PHONY: 		all fclean clean re
