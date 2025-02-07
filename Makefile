NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADERS = push_swap.h

SRC = code/utils.c code/actions1.c code/actions2.c code/sorting_algo.c \
			  code/extra_utils.c code/super_actions.c code/error_utils.c src/ft_lstsize.c \
			  src/ft_split.c src/ft_atoi.c src/ft_substr.c src/ft_strlen.c \
			  src/ft_strdup.c src/ft_strcmp.c src/ft_memcpy.c \
			  bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

PUSH_SWAP_SRCS = code/push_swap.c
CHECKER_SRCS = bonus/checker_bonus.c

COMMON_OBJS = $(SRC:.c=.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(COMMON_OBJS) $(PUSH_SWAP_OBJS)

bonus: $(CHECKER)

$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $(CHECKER) $(COMMON_OBJS) $(CHECKER_OBJS)

clean:
	rm -f $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re