# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 13:05:24 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/11 18:51:06 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft
INCLUDE	=	-I $(LIBDIR) -I inc

LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	$(SRCDIR)/ft_printf.c \
			$(SRCDIR)/ft_format.c \
			$(SRCDIR)/ft_putx.c \
			$(SRCDIR)/ft_putp.c \
			$(SRCDIR)/utils.c

BSRCS	=	$(SRCDIR)/ft_printf_bonus.c \
			$(SRCDIR)/ft_format_bonus.c \
			$(SRCDIR)/ft_putc_bonus.c \
			$(SRCDIR)/ft_putd_bonus.c \
			$(SRCDIR)/ft_putu_bonus.c \
			$(SRCDIR)/ft_puts_bonus.c \
			$(SRCDIR)/ft_putx_bonus.c \
			$(SRCDIR)/ft_putp_bonus.c \
			$(SRCDIR)/utils_bonus.c

OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
BOBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(BSRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	@echo Creating library...
	@cp $(LIBFT) $(NAME)
	@ar -crs $(NAME) $(OBJS)

bonus: .bonus

.bonus: $(LIBFT) $(OBJDIR) $(BOBJS)
	@rm -f $(NAME)
	@echo Creating library with bonuses...
	@cp $(LIBFT) $(NAME)
	@ar -crs $(NAME) $(BOBJS) 
	@touch .bonus

$(LIBFT):
	@make -C $(LIBDIR) --no-print-directory

$(OBJDIR):
	@echo creating objdir...
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean --no-print-directory
	@rm -f $(OBJS)
	@rm -f $(BOBJS)
	@rm -f .bonus

fclean: clean
	@make -C $(LIBDIR) fclean --no-print-directory
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all
