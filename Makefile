# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 14:32:18 by irozhkov          #+#    #+#              #
#    Updated: 2024/09/23 15:27:30 by irozhkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

# ═══ COMPILATE ═══════════════════════════════════════════════════════════════#
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIB_FLAG = -L./Libft -lft
MLX_FLAG = -L./minilibx-linux -lmlx -lX11 -lXext -lm -lz
DEP_FLAG = -MMD -MP
INCLUDE = -I./Libft/ -I./minilibx-linux/ -I./inc/
MKDIR = mkdir -p
RMF = rm -f
RMD = rm -rf

# ═══ DIRECTORIES ═════════════════════════════════════════════════════════════#
CHECK_DIR = check/
INC_DIR = inc/
INIT_DIR = init/
LIBFT_DIR = Libft/
MLX_DIR = minilibx-linux/
OBJ_DIR = obj/
PARS_DIR = parser/
REND_DIR = render/
SRC_DIR = src/
UTILS_DIR = utils/

# ═══ SOURCES ═════════════════════════════════════════════════════════════════#
MAIN = main
CHECK_FILES = checker_ambient checker checker_camera checker_cylinder \
			  checker_plane checker_sphere checker_spot check_limits
INIT_FILES = init_all init_figures init_unique
PARS_FILES = parsing_scene parsing_table
REND_FILES = render_init
UTILS_FILES = ft_atof utils_add utils_exit utils_free utils_parsing utils_str

SRC_FILES+=$(MAIN)
SRC_FILES+=$(addprefix $(CHECK_DIR),$(CHECK_FILES))
SRC_FILES+=$(addprefix $(INIT_DIR),$(INIT_FILES))
SRC_FILES+=$(addprefix $(PARS_DIR),$(PARS_FILES))
SRC_FILES+=$(addprefix $(REND_DIR),$(REND_FILES))
SRC_FILES+=$(addprefix $(UTILS_DIR),$(UTILS_FILES))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

# ═══ RULES ═══════════════════════════════════════════════════════════════════#

all: $(NAME)

$(NAME): $(LIBFT_DIR)libft.a $(MLX_DIR)libmlx.a $(OBJS) Makefile
		$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAG) $(MLX_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		$(MKDIR) $(dir $@)
		$(CC) $(CFLAGS) $(DEP_FLAG) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)libft.a:
		make -C $(LIBFT_DIR) all

$(MLX_DIR)libmlx.a:
		make -sC $(MLX_DIR) all &> /dev/null

clean:
		$(RMD) $(OBJ_DIR)
		make clean -C $(LIBFT_DIR)
		make clean -sC $(MLX_DIR)

fclean:	clean
		$(RMF) $(NAME)
		$(RMF) $(LIBFT_DIR)libft.a
		$(RMF) $(MLX_DIR)libmlx.a
		$(RMF) $(MLX_DIR)libmlx_Linux.a


re:	fclean all

-include $(DEPS)
.PHONY: all clean fclean re
