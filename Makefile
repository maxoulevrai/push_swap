NAME = push_swap

LIB = lib/libft.a

SRCS = main.c \
		sort/sort_algo.c \
		sort/sort_utils.c \
		sort/tiny_sort.c \
		utils/init_utils.c \
		utils/parsing_utils.c \
		utils/linked_list_utils.c \
		utils/instructions/swap_instructions.c \
		utils/instructions/push_instructions.c \
		utils/instructions/rotate_instructions.c \
		utils/instructions/reverse_rotate_instructions.c

OBJS = $(SRCS:%.c=build/%.o)
DEPS = $(OBJS:.o=.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@echo "\033[32mLinking $@\033[0m"
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "\033[32mBuild complete\033[0m"

$(LIB):
	@$(MAKE) -C lib lib

$(OBJS): | build

build:
	@mkdir -p build

build/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "\033[33mCompiling $<\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[31mCleaning object files\033[0m"
	@rm -rf build
	@$(MAKE) -C lib lib_clean

fclean: clean
	@echo "\033[31mCleaning executable\033[0m"
	@rm -f $(NAME)
	@$(MAKE) -C lib lib_fclean

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
