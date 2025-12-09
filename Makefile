NAME			=	push_swap
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
INC_DIR			=	include
OBJ_DIR			=	obj
SRC_DIR			=	src

INCLUDES		=	-I $(INC_DIR) -I $(LIBFT_PATH)

SRCS_ROOT		=	main.c

SRCS_SUB		=	check/checker.c \
					check/create_data.c \
					sorting_operations/push_op.c \
					sorting_operations/swap_op.c \
					sorting_operations/rev_rotate_op.c \
					sorting_operations/rotate_op.c \
					sort_number/sort_5.c \
					sort_number/sort.c \
					double_lst_cmd.c \
					error.c \
					push_swap.c \
					indexing.c \
					algo.c \
					utils.c \
					debug.c

SRCS			=	$(SRCS_ROOT) $(addprefix $(SRC_DIR)/, $(SRCS_SUB))
OBJS			=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

GREEN			=	\033[32m
BLUE			=	\033[34m
RESET			=	\033[0m

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)push_swap compiled$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(GREEN)$< compiled$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(BLUE)Objects cleaned$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "$(BLUE)Executable cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
.SILENT: