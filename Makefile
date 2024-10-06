CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
AR = ar rcs
NAME = pipex
LIBFT = libft
HEADERS := -I ./include

SRCS = src/pipex.c src/utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

allc: all clean
	@echo "Making all and cleaning up"

$(NAME): $(OBJS)
	make -C $(LIBFT)
	@$(CC) $(OBJS) $(HEADERS) libft/libft.a -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	make clean -C $(LIBFT)
	${RM} ${OBJS}
	@echo "Removing everything but library and source files"

fclean: clean
	make fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all clean
	make clean -C $(LIBFT)
	@echo "Cleaning up and redoing all"

lib:
	make -C $(LIBFT)

.PHONY: all clean fclean re allc lib
