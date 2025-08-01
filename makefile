NAME = push_swap

LIB = lib/libft.a

SRCS = main.c \
		sort/tiny_sort.c \
		sort/sort_utils.c \
		sort/sort.c \
		utils/linked_list_utils.c \
		utils/parsing_utils.c \
		utils/init_utils.c \
		utils/instructions/push_instructions.c \
		utils/instructions/swap_instructions.c \
		utils/instructions/rotate_instructions.c \
		utils/instructions/reverse_rotate_instructions.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIB} 
	@echo -e "Compiling $@"
	${CC} ${CFLAGS} -o $@ $^
	@echo "Build complete"

${LIB}:
	$(MAKE) -C lib lib

%.o: %.c
	@echo "Compiling $<"
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "Cleaning object files"
	${RM} ${OBJS} ${OBJS:.o=.d}
	$(MAKE) -C lib lib_clean

fclean: clean
	@echo "Cleaning executable"
	${RM} ${NAME}
	$(MAKE) -C lib lib_fclean

re: fclean all

.PHONY: all clean fclean re

-include ${OBJS:.o=.d}

include lib/Makefile