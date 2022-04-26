# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
OBJS_DIR		:= obj
LIBS_DIR		:= lib
LIBFTPRINTF_DIR	:= $(LIBS_DIR)/ft_printf

# *********************************** Files ************************************
NAME	:= push_swap
MAIN	:= main.c
SRCS	:= display_actions.c \
			doubly_linked_list.c \
			doubly_linked_list_2.c \
			errors.c \
			free_tab.c \
			ft_create_stack.c \
			ft_split.c \
			ft_stack.c \
			p_push.c \
			p_rev_rotate.c \
			p_rotate.c \
			p_swap.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			push_swap_utils3.c \
			quick_sort.c \
			sorted_array.c \
			sorting.c \
			sorting2.c \
			sorting_3.c
OBJS	:= $(SRCS:.c=.o)
HEADERS	:= push_swap.h
LIBFTPRINTF	:= libftprintf.a

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR)
LIBS		:= -L $(LIBFTPRINTF_DIR) -lftprintf

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(MAIN) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
			$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) \
$(MAIN) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
	@$(MKDIR) $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF):
	@make -C $(LIBFTPRINTF_DIR)

clean:
	@make clean -C $(LIBFTPRINTF_DIR)
	@$(RM) $(OBJS_DIR)

fclean:	clean
	@make fclean -C $(LIBFTPRINTF_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re