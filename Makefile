SRC = ft_lst/lstfunc.c ft_lst/lstdel.c instructions.c main.c utils.c find_num.c algorithm.c

SRC_TESTER = tester/tester.c tester/bonus_instrucs.c tester/get_next_line.c tester/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

RM = rm -f

TESTER = checker_linux

NAME = push_swap

PRINTF = ft_printf/libftprintf.a

all : $(NAME)

bonus : $(NAME) $(TESTER)

$(PRINTF) :
		make -C ft_printf/ all

$(NAME) :	$(OBJS)
				make -C ft_printf/
				gcc -Wall -Werror -Wextra $(OBJS) -I ./ -I ./ft_printf/ -L ./ft_printf -lftprintf -o $(NAME)

$(TESTER) :	$(SRC_TESTER)
				gcc -Wall -Werror -Wextra $(SRC_TESTER) -I ./ -I ./ft_printf/ -L ./ft_printf -lftprintf -o $(TESTER)

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
