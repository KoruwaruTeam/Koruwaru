# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/31 00:30:49 by crenault          #+#    #+#              #
#    Updated: 2015/10/27 18:51:24 by tmielcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# submodules
SUBMODULES =

# libraries
LIBRARIES =

INCLUDE_DIR = include/ ../common/libft/includes/ ../common/
INCLUDE = $(addprefix -I, $(INCLUDE_DIR))

LIB_DIR = ../common/libft
LIB_NAME = ft
LIB = $(addprefix -L, $(LIB_DIR)) $(addprefix -l, $(LIB_NAME))

OBJ_DIR = obj/

# compiler
CC = clang
# file type
FT = c
# flags
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Weverything -pedantic-errors -Wno-padded -Wno-sign-conversion -Wno-shorten-64-to-32
# CFLAGS += -O3
CFLAGS += -g
# binary flags (add libraries)
BIN_FLAGS = $(CFLAGS) $(LIB)
# executable
NAME = corewar

# to compile files
SRC = main.c
SRC += create_player.c
SRC += create_process.c
SRC += dump_arena.c
SRC += dup_process.c
SRC += get_file_data.c
SRC += op.c
SRC += get_op.c
SRC += get_program.c
SRC += init_instr.c
SRC += init_params.c
SRC += init_vm.c
SRC += reg.c
SRC += mem.c
SRC += ltob.c
SRC += move_pc.c
SRC += set_pc.c
SRC += get_param_type.c
SRC += param_value.c
SRC += exec_instr.c
SRC += game.c
SRC += get_player.c
SRC += parse_args.c
SRC += args_handlers.c
SRC += print_error.c

SRC += null.c
SRC += live.c
SRC += ld.c
SRC += add.c
SRC += and.c
SRC += or.c
SRC += st.c
SRC += sub.c
SRC += xor.c

SRC += fork.c
SRC += ldi.c
SRC += lld.c
SRC += sti.c
SRC += zjmp.c
SRC += lfork.c
SRC += lldi.c
SRC += aff.c

# check in these directories for c files
vpath %.c src/ ../common/ src/instructs

# header files
HDR = include/vm_types.h
HDR += include/vm_protos.h

# objects files
OBJS = $(SRC:%.$(FT)=$(OBJ_DIR)%.o)

# don't recompile after cleaning
.SECONDARY: $(OBJS)

# main rule
all: $(NAME)

# rebuild your bin
re: fclean all

# reclone submodule and rebuild
rere: ffclean all

$(NAME): $(SUBMODULES) $(LIBRARIES) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(BIN_FLAGS)
	@echo $@ "updated!"

# making o files
$(OBJ_DIR)%.o: %.$(FT) $(HDR) | $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)
	@echo $< "updated!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# submodules
$(SUBMODULES):
	@git submodule init
	@git submodule update
	@echo $@ "updated!"

# ignore files with these names
.PHONY: all re rere clean fclean ffclean cleansubs

# clean o files
clean:
	@rm -rf $(OBJS)

# clean submodules
cleansubs:
	@rm -rf $(PI_RESS_LOCAL_DIR)

# clean exec file and library
fclean: clean
	@rm -rf $(NAME)

# get empty and clean repo (without libs)
ffclean: fclean cleansubs
