#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := libft.a
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      ft_strjoin.c \
                          ft_isalnum.c \
                          ft_lstiter.c \
                          ft_itoa.c \
                          ft_strlcpy.c \
                          ft_isprint.c \
                          ft_lstadd_front.c \
                          ft_strmapi.c \
                          ft_isascii.c \
                          ft_strnstr.c \
                          ft_isalpha.c \
                          ft_strrchr.c \
                          ft_putstr_fd.c \
                          ft_split.c \
                          ft_isdigit.c \
                          ft_memset.c \
                          ft_memchr.c \
                          ft_strchr.c \
                          ft_calloc.c \
                          ft_memmove.c \
                          ft_substr.c \
                          ft_lstdelone.c \
                          ft_memcpy.c \
                          ft_lstmap.c \
                          ft_putchar_fd.c \
                          ft_strtrim.c \
                          ft_lstsize.c \
                          get_next_line.c \
                          ft_bzero.c \
                          get_next_line_utils.c \
                          ft_lstlast.c \
                          ft_toupper.c \
                          ft_tolower.c \
                          ft_strlcat.c \
                          ft_lstclear.c \
                          ft_striteri.c \
                          ft_memcmp.c \
                          ft_putendl_fd.c \
                          ft_lstnew.c \
                          ft_lstadd_back.c \
                          ft_strdup.c \
                          ft_atoi.c \
                          ft_strlen.c \
                          ft_strncmp.c \
                          ft_putnbr_fd.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		$(NAME)

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


