# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 13:05:24 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/14 10:16:49 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft
INCLUDE	=	-I $(LIBDIR) -I inc

LIBFT	=	$(LIBDIR)/libft.a
LFTSRCS	=	$(LIBDIR)/ft_atoi.c \
			$(LIBDIR)/ft_bzero.c \
			$(LIBDIR)/ft_calloc.c \
			$(LIBDIR)/ft_isalnum.c \
			$(LIBDIR)/ft_isalpha.c \
			$(LIBDIR)/ft_isascii.c \
			$(LIBDIR)/ft_isdigit.c \
			$(LIBDIR)/ft_isprint.c \
			$(LIBDIR)/ft_itoa.c \
			$(LIBDIR)/ft_uitoa.c \
			$(LIBDIR)/ft_intlen.c \
			$(LIBDIR)/ft_uintlen.c \
			$(LIBDIR)/ft_memset.c \
			$(LIBDIR)/ft_memchr.c \
			$(LIBDIR)/ft_memcmp.c \
			$(LIBDIR)/ft_memcpy.c \
			$(LIBDIR)/ft_memmove.c \
			$(LIBDIR)/ft_putnbr_fd.c \
			$(LIBDIR)/ft_putunbr_fd.c \
			$(LIBDIR)/ft_putxnbr_fd.c \
			$(LIBDIR)/ft_putchar_fd.c \
			$(LIBDIR)/ft_putendl_fd.c \
			$(LIBDIR)/ft_putstr_fd.c \
			$(LIBDIR)/ft_split.c \
			$(LIBDIR)/ft_strchr.c \
			$(LIBDIR)/ft_strdup.c \
			$(LIBDIR)/ft_striteri.c \
			$(LIBDIR)/ft_strjoin.c \
			$(LIBDIR)/ft_strlcat.c \
			$(LIBDIR)/ft_strlcpy.c \
			$(LIBDIR)/ft_strlen.c \
			$(LIBDIR)/ft_strmapi.c \
			$(LIBDIR)/ft_strncmp.c \
			$(LIBDIR)/ft_strnstr.c \
			$(LIBDIR)/ft_strrchr.c \
			$(LIBDIR)/ft_strtrim.c \
			$(LIBDIR)/ft_strrev.c \
			$(LIBDIR)/ft_substr.c \
			$(LIBDIR)/ft_tolower.c \
			$(LIBDIR)/ft_toupper.c

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

$(LIBFT): $(LFTSRCS)
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
