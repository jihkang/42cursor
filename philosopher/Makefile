CC = cc
NAME = philo

SRC_INC = src/
HDR_INC = inc/

CFLAG = -Wall -Wextra -Werror

SRC = main \
	action \
	argue \
	utils

HDR = *.h

SRCS = $(addprefix $(SRC_INC), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(SRC_INC), $(addsuffix .o, $(SRC)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME) -I$(HDR) -pthread


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
