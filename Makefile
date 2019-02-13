# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:02:56 by ldedier           #+#    #+#              #
#    Updated: 2019/02/10 16:03:29 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER_NAME	= checker

CC      = gcc -g3

PWD = $(shell pwd)

DEBUG ?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -DDEBUG -fsanitize=address
endif

SRCDIR   = srcs

PUSH_SWAP_SRCDIR  	= push_swap
CHECKER_SRCDIR  	= checker

OBJDIR   = objs

PUSH_SWAP_OBJDIR  	= push_swap
CHECKER_OBJDIR  	= checker

BINDIR   = .
INCLUDESDIR = includes

LIBFTDIR = libft
LIBFT_INCLUDEDIR = includes
LIBFT = $(LIBFTDIR)/libft.a

OK_COLOR = \x1b[32;01m
EOC = \033[0m

COMMON_SRCS_NO_PREFIX =		parse_args.c print.c instructions.c is_solved.c\
							free.c process_instruction.c

SRCS_NO_PREFIX =			main.c

CHECKER_SRCS_NO_PREFIX =	main.c parse_instructions.c parse_flags.c

INCLUDES_NO_PREFIX = push_swap.h
CINCLUDES_NO_PREFIX = push_swap.h checker.h

SOURCES = $(addprefix $(SRCDIR)/$(PUSH_SWAP_SRCDIR)/, $(SRCS_NO_PREFIX))
CSOURCES = $(addprefix $(SRCDIR)/$(CHECKER_SRCDIR)/, $(CHECKER_SRCS_NO_PREFIX))

COMMON_OBJECTS = $(addprefix $(OBJDIR)/, $(COMMON_SRCS_NO_PREFIX:%.c=%.o))
OBJECTS = $(addprefix $(OBJDIR)/$(PUSH_SWAP_OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
COBJECTS = $(addprefix $(OBJDIR)/$(CHECKER_OBJDIR)/, $(CHECKER_SRCS_NO_PREFIX:%.c=%.o))

OBJECTS += $(COMMON_OBJECTS)
COBJECTS += $(COMMON_OBJECTS)

INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))
CINCLUDES = $(addprefix $(INCLUDESDIR)/, $(CINCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR) \
	  -I $(FRAMEWORKSDIR)/SDL2


LFLAGS = -L $(LIBFTDIR) -lft 

ifeq ($(DEBUG), 1)
	LFLAGS += -fsanitize=address
endif

SRCDIR   = srcs

PUSH_SWAP_SRCDIR  	= push_swap
CHECKER_SRCDIR  	= checker

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

$(BINDIR)/$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(BINDIR)/$(CHECKER_NAME): $(COBJECTS) $(LIBFT)
	@$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS) -F $(FRAMEWORKSDIR)
	@echo "$(OK_COLOR)$(CHECKER_NAME) linked with success !$(EOC)"\

$(OBJDIR)/$(PUSH_SWAP_OBJDIR)/%.o : $(SRCDIR)/$(PUSH_SWAP_SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)/$(PUSH_SWAP_OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(OBJDIR)/$(CHECKER_OBJDIR)/%.o : $(SRCDIR)/$(CHECKER_SRCDIR)/%.c $(CINCLUDES)
	@mkdir -p $(OBJDIR)/$(CHECKER_OBJDIR)
	$(CC) -c $< -o $@ -F $(FRAMEWORKSDIR) $(CFLAGS) 

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS) 


clean:
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJECTS)
	@rm -f $(COBJECTS)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)
	@rm -f $(BINDIR)/$(CHECKER_NAME)

re: fclean opti

.PHONY: all clean fclean re
