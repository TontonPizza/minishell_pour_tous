NAME = minishell


SRCS	=	minishell.c \
        	./libft/libft.a \


all: $(NAME)

./libft/libft.a:
					make -C ./libft/


$(NAME): $(SRCS) minishell.h
		gcc $(SRCS) ./libft/libft.a -o minishell
		make clean -C ./libft

clear:	$(NAME)
		clear