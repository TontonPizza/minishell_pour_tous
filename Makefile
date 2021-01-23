NAME = minishell


SRCS	=	minishell.c \
			./srcs/environnement/env_manipulation.c \
			./srcs/environnement/env_manipulation_2.c \
        	./libft/libft.a \


all: $(NAME)

./libft/libft.a:
					make -C ./libft/
					make clean -C ./libft

$(NAME): $(SRCS) minishell.h
		clang $(SRCS) ./libft/libft.a -o minishell


clear:	$(NAME)
		clear