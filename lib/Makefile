LIB = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD
AR = ar rcs
RM = rm -rf
LIB_DIR = srcs/
LIB_OBJS = ${LIB_SRCS:.c=.o}

LIB_SRCS = ${LIB_DIR}ft_isalpha.c \
			${LIB_DIR}ft_isdigit.c \
			${LIB_DIR}ft_isalnum.c \
			${LIB_DIR}ft_isascii.c \
			${LIB_DIR}ft_isprint.c \
			${LIB_DIR}ft_strlen.c \
			${LIB_DIR}ft_memset.c \
			${LIB_DIR}ft_bzero.c \
			${LIB_DIR}ft_memcpy.c \
			${LIB_DIR}ft_memmove.c \
			${LIB_DIR}ft_strlcpy.c \
			${LIB_DIR}ft_strlcat.c \
			${LIB_DIR}ft_toupper.c \
			${LIB_DIR}ft_tolower.c \
			${LIB_DIR}ft_strchr.c \
			${LIB_DIR}ft_strrchr.c \
			${LIB_DIR}ft_strncmp.c \
			${LIB_DIR}ft_memchr.c \
			${LIB_DIR}ft_memcmp.c \
			${LIB_DIR}ft_strnstr.c \
			${LIB_DIR}ft_atoi.c \
			${LIB_DIR}ft_calloc.c \
			${LIB_DIR}ft_strdup.c \
			${LIB_DIR}ft_substr.c \
			${LIB_DIR}ft_strjoin.c \
			${LIB_DIR}ft_strtrim.c \
			${LIB_DIR}ft_split.c \
			${LIB_DIR}ft_itoa.c \
			${LIB_DIR}ft_strmapi.c \
			${LIB_DIR}ft_striteri.c \
			${LIB_DIR}ft_putchar_fd.c \
			${LIB_DIR}ft_putstr_fd.c \
			${LIB_DIR}ft_putendl_fd.c \
			${LIB_DIR}ft_putnbr_fd.c \
			${LIB_DIR}word_count.c \
			${LIB_DIR}free_dtab.c \
			${LIB_DIR}ft_strcat.c \
			${LIB_DIR}get_dtab_len.c \
			${LIB_DIR}word_len.c \
			${LIB_DIR}ft_lstnew.c \
			${LIB_DIR}ft_lstadd_front.c \
			${LIB_DIR}ft_lstsize.c \
			${LIB_DIR}ft_lstlast.c \
			${LIB_DIR}ft_lstadd_back.c \
			${LIB_DIR}ft_lstdelone.c \
			${LIB_DIR}ft_lstclear.c \
			${LIB_DIR}ft_lstiter.c \
			${LIB_DIR}ft_lstmap.c \


lib:		${LIB}

${LIB}:	${LIB_OBJS}
	@echo -e "Compiling $@"
	${AR} $@ $^
	@echo "Archive complete"

%.o: %.c
	@echo "Compiling $<"
	${CC} ${CFLAGS} -c $< -o $@

lib_clean:
	@echo "Cleaning library object files"
	${RM} ${LIB_OBJS} $(LIB_OBJS:.o=.d)

lib_fclean:	lib_clean
	@echo "Cleaning library"
	${RM} ${LIB}

re_lib:		fclean all

.PHONY: lib lib_clean lib_fclean re_lib

-include $(LIB_OBJS:.o=.d)