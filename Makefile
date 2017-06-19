NAME = fillit

SRCDIR = srcs

OBJDIR = objs

SRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(OBJS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@gcc -Wall -Wextra -Werror -c $< -I libft/includes -I includes -o $@

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(OBJS) -L libft -lft -o $(NAME)

.PHONY: clean
clean:
	@make clean -C libft
	@rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

.PHONY: re
re: fclean all
