# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 13:05:24 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/06 11:43:05 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCDIR	=	src/main
OBJDIR	=	obj/main
BONUSSD	=	src/bonus
BONUSOD	=	obj/bonus
LIBDIR	=	lib
INCLUDE	=	-I $(LIBDIR) -I inc

LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	$(SRCDIR)/ft_printf.c \
			$(SRCDIR)/ft_format.c \
			$(SRCDIR)/ft_putx.c \
			$(SRCDIR)/ft_putp.c \
			$(SRCDIR)/utils.c

BONUSS	=	$(BONUSSD)/ft_printf_bonus.c \
			$(BONUSSD)/ft_format_bonus.c \
			$(BONUSSD)/ft_putc_bonus.c \
			$(BONUSSD)/ft_putd_bonus.c \
			$(BONUSSD)/ft_putu_bonus.c \
			$(BONUSSD)/ft_puts_bonus.c \
			$(BONUSSD)/ft_putx_bonus.c \
			$(BONUSSD)/ft_putp_bonus.c \
			$(BONUSSD)/utils_bonus.c

OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BONUSO	=	$(patsubst $(BONUSSD)/%.c, $(BONUSOD)/%.o, $(BONUSS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	@echo Creating library...
	@mkdir -p tmp
	@cp $(LIBFT) tmp/
	@cd tmp; ar -x libft.a
	@ar -crs $(NAME) $(OBJS) tmp/*.o
	@rm -rf tmp

bonus: .bonus

.bonus: $(LIBFT) $(BONUSOD) $(BONUSO)
	@rm -f $(NAME)
	@echo Creating library with bonuses...
	@mkdir -p tmp
	@cp $(LIBFT) tmp/
	@cd tmp; ar -x libft.a
	@ar -crs $(NAME) $(BONUSO) tmp/*.o
	@touch .bonus
	@rm -rf tmp

$(LIBFT):
	@make -C $(LIBDIR)/libft --no-print-directory

$(OBJDIR):
	@echo creating objdir...
	@mkdir -p $(OBJDIR)

$(BONUSOD):
	@echo creating bonus objdir...
	@mkdir -p $(BONUSOD)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUSOD)/%.o: $(BONUSSD)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make -C $(LIBDIR)/libft clean --no-print-directory
	@rm -f $(OBJS)
	@rm -f $(BONUSO)
	@rm -f .bonus

fclean: clean
	@make -C $(LIBDIR)/libft fclean --no-print-directory
	@rm -rf obj
	@rm -f $(NAME)

re: fclean all
