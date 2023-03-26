SRC = cl_func/lstfunc.c cl_func/lstdel.c instructions/p.c instructions/r.c instructions/rr.c instructions/s.c main.c utils.c

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

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

clean :
		$(RM) $(OBJS)
		make -C ft_printf/ clean

fclean :	clean
				$(RM) $(NAME)
				make -C ft_printf/ fclean

re:			fclean all

.PHONY: all clean fclean re