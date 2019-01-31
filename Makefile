# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:02:56 by ldedier           #+#    #+#              #
#    Updated: 2019/01/31 19:28:21 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER_NAME	= checker
VISU_NAME		= push_swap_visu

CC      = gcc -g

PWD = $(shell pwd)

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG -fsanitize=address
endif

SRCDIR   = srcs

PUSH_SWAP_SRCDIR  	= push_swap
CHECKER_SRCDIR  	= checker
VISU_SRCDIR  		= push_swap_visu

OBJDIR   = objs

PUSH_SWAP_OBJDIR  	= push_swap
CHECKER_OBJDIR  	= checker
VISU_OBJDIR  		= push_swap_visu

BINDIR   = .
INCLUDESDIR = includes

LIBFTDIR = libft
LIBFT_INCLUDEDIR = includes
LIBFT = $(LIBFTDIR)/libft.a

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX =			main.c

CHECKER_SRCS_NO_PREFIX =	main.c

VISU_SRCS_NO_PREFIX =		main.c

INCLUDES_NO_PREFIX = push_swap.h
CINCLUDES_NO_PREFIX = visu.h
VINCLUDES_NO_PREFIX = checker.h

SOURCES = $(addprefix $(SRCDIR)/$(PUSH_SWAP_SRCDIR)/, $(SRCS_NO_PREFIX))
CSOURCES = $(addprefix $(SRCDIR)/$(CHECKER_SRCDIR)/, $(CHECKER_SRCS_NO_PREFIX))
VSOURCES = $(addprefix $(SRCDIR)/$(VISU_SRCDIR)/, $(VISU_SRCS_NO_PREFIX))

OBJECTS = $(addprefix $(OBJDIR)/$(PUSH_SWAP_OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
COBJECTS = $(addprefix $(OBJDIR)/$(CHECKER_OBJDIR)/, $(CHECKER_SRCS_NO_PREFIX:%.c=%.o))
VOBJECTS = $(addprefix $(OBJDIR)/$(VISU_OBJDIR)/, $(VISU_SRCS_NO_PREFIX:%.c=%.o))

INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))
CINCLUDES = $(addprefix $(INCLUDESDIR)/, $(CINCLUDES_NO_PREFIX))
VINCLUDES = $(addprefix $(INCLUDESDIR)/, $(VINCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR) \
	  -I $(FRAMEWORKSDIR)/SDL2


LFLAGS = -L $(LIBFTDIR) -lft 

CFLAGS = -DPATH=\"$(PWD)\" -Wall -Wextra -Werror $(INC)

FRAMEWORKSDIR = $(PWD)/frameworks

SDL2_FRAMEWORKS =   -framework SDL2 -framework SDL2_image \
					-framework SDL2_mixer -framework SDL2_ttf \

opti:
	@make all -j8

debug:
	@make opti DEBUG=1

all:
	@make -C $(LIBFTDIR) all
	@make $(BINDIR)/$(NAME)
	@make $(BINDIR)/$(CHECKER_NAME) 
	@make $(BINDIR)/$(VISU_NAME) 

$(BINDIR)/$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(BINDIR)/$(CHECKER_NAME): $(COBJECTS) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS) -F $(FRAMEWORKSDIR)
	@echo "$(OK_COLOR)$(CHECKER_NAME) linked with success !$(EOC)"\

$(BINDIR)/$(VISU_NAME): $(VOBJECTS) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS) -Wl,-rpath $(FRAMEWORKSDIR)
	@echo "$(OK_COLOR)$(VISU_NAME) linked with success !$(EOC)"

$(OBJDIR)/$(PUSH_SWAP_OBJDIR)/%.o : $(SRCDIR)/$(PUSH_SWAP_SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/$(PUSH_SWAP_OBJDIR)
	@mkdir -p $(OBJDIR)/$(CHECKER_OBJDIR)
	@mkdir -p $(OBJDIR)/$(VISU_OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(OBJDIR)/$(CHECKER_OBJDIR)/%.o : $(SRCDIR)/$(CHECKER_SRCDIR)/%.c $(CINCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(OBJDIR)/$(VISU_OBJDIR)/%.o : $(SRCDIR)/$(VISU_SRCDIR)/%.c $(VINCLUDES)
	$(CC) -c $< -o $@ -F $(FRAMEWORKSDIR) $(CFLAGS) 

clean:
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJECTS)
	@rm -f $(VOBJECTS)
	@rm -f $(CVOBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)
	@rm -f $(BINDIR)/$(CHECKER_NAME)
	@rm -f $(BINDIR)/$(VISU_NAME)

re: fclean opti

.PHONY: all clean fclean re
