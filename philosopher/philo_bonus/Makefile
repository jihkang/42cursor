CC = cc
NAME = philo

SRC_INC = src/
HDR_INC = inc/

CFLAG = -Wall -Wextra -Werror

DFLAG = -fsanitize=thread
HFLAG = -fsanitize=address

SRC = main \
	action \
	argue \
	utils

HDR = *.h

SRCS = $(addprefix $(SRC_INC), $(addsuffix .c, $(SRC)))

OBJS = $(addprefix $(SRC_INC), $(addsuffix .o, $(SRC)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(SRCS) -o $(NAME) -I$(HDR) -lpthread

thd	:
	$(CC) $(CFLAG) $(DFLAG) $(SRCS) -o $(NAME) -I$(HDR) -pthread

heap :
	$(CC) $(CFLAG) $(HFLAG) $(SRCS) -o $(NAME) -I$(HDR) -pthread

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all, clean, fclean, re
