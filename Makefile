NAME := miniRT

SRCS := src/main.c src/color/color.c src/draw_part/draw_part.c src/print/print.c src/ray/ray.c src/vec3/vec3.c \
src/hit_sphere/hit_sphere.c

OBJS := $(SRCS:.c=.o)

# libft
LIBFT_DIR := ./libft
LIBFT := $(LIBFT_DIR)/libft.a
# minilibx
MINILIBX_URL := https://cdn.intra.42.fr/document/document/23420/minilibx_opengl.tgz
MINILIBX_TAR_GZ := minilibx_opengl.tgz
MINILIBX_DIR := ./minilibx_opengl_20191021
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I./include -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
CFLAGS := -Wall -Wextra -Werror -O2
# CFLAGS := -Wall -Wextra -Werror -O0 -g
LDFLAGS := -L$(LIBFT_DIR) -L$(MINILIBX_DIR)
LIBS=-lm -lmlx

.PHONY: all
all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -j4 -C $(LIBFT_DIR)

$(MINILIBX_TAR_GZ):
	curl -O $(MINILIBX_URL)

$(MINILIBX): $(MINILIBX_TAR_GZ)
	tar xvzf $(MINILIBX_TAR_GZ)
	$(MAKE) -j4 -C $(MINILIBX_DIR)

.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) -r $(MINILIBX_DIR)
	$(RM) $(MINILIBX_TAR_GZ)

.PHONY: re
re: fclean all

# test
# .PHONY: test
# test: unit_test e2e_test

# .PHONY: unit_test
# unit_test: $(READLINE) $(LIBFT)
# 	cd test/unit && \
# 	cmake -S . -B build && cmake --build build &&  cd build && ctest

# .PHONY: e2e_test
# e2e_test: $(NAME) $(e2e_clean)
# 	cd test/e2e && ./run_e2e.sh

# .PHONY: e2e_clean
# e2e_clean:
# 	$(RM) test/e2e/out/*.out
# 	$(RM) test/e2e/out/*.diff

.PHONY: norm
norm:
	norminette libft
	norminette include
	norminette src
