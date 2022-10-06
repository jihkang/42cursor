CC = cc
NAME = GNL

SRC_INC = src/
HDR_INC = inc/

CFLAG = -Wall -Wextra -Werror

HFLAG = -fsanitize=address -g

SRC = gnl_utils \
	gnl 

HDR = ./inc

SRCS = $(addprefix $(SRC_INC), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(SRC_INC), $(addsuffix .o, $(SRC)))

all : $(NAME)

%o : %c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME) -I$(HDR_INC)

heap :
	$(CC) $(CFLAG) $(HFLAG) $(SRCS) -o $(NAME) -I$(HDR_INC)

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all, clean, fclean, re
