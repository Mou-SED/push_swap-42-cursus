# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
OBJS_DIR		:= obj
LIBS_DIR		:= lib
LIBFTPRINTF_DIR	:= $(LIBS_DIR)/ft_printf

# *********************************** Files ************************************
NAME		:= push_swap
MAIN		:= main.c
SRCS		:= display_actions.c \
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
			sorting_three_numbers.c \
			sorting_five_numbers.c \
			sorting3.c \
			sorting_four_numbers.c
OBJS		:= $(SRCS:.c=.o)
HEADERS		:= push_swap.h

BNAME		:= checker
BMAIN		:= checker.c
GNLSRCS		:= get_next_line.c get_next_line_utils.c
GNLOBJS		:= $(GNLSRCS:.c=.o)

LIBFTPRINTF	:= libftprintf.a

# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
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

bonus: $(BNAME)

$(BNAME): $(addprefix $(OBJS_DIR)/, $(OBJS)) $(BMAIN) \
			$(addprefix $(OBJS_DIR)/, $(GNLOBJS)) \
			$(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
			$(LIBFTPRINTF_DIR)/$(LIBFTPRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(addprefix $(OBJS_DIR)/, $(OBJS)) \
$(addprefix $(OBJS_DIR)/, $(GNLOBJS)) $(BMAIN) -o $(BNAME)

$(OBJS_DIR)/%.o: ./lib/get_next_line/%.c ./lib/get_next_line/get_next_line.h
	@$(MKDIR) $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make clean -C $(LIBFTPRINTF_DIR)
	@$(RM) $(OBJS_DIR) $(BOBJS) $(GNLOBJS)

fclean:	clean
	@make fclean -C $(LIBFTPRINTF_DIR)
	@$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus
