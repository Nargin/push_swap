SRC = lstfunc.c lstdel.c push_swap.c p.c r.c rr.c s.c main.c utils.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = push_swap

PRINTF = ft_printf/libftprintf.a

all : $(NAME)

$(PRINTF) :
		make -C ft_printf/ all

$(NAME) :	$(OBJS)
				make -C ft_printf/
				gcc -Wall -Werror -Wextra $(OBJS) -I ./ -I ./ft_printf/ -L ./ft_printf -lftprintf -o $(NAME)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -I ./ft_printf/ -c $< -o $(<:.c=.o)

clean :
		$(RM) $(OBJS)
		make -C ft_printf/ clean

fclean :	clean
				$(RM) $(NAME)
				make -C ft_printf/ fclean

re:			fclean all

.PHONY: all clean fclean re