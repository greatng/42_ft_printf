NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC_DIR			=	srcs/
SRC				=	ft_printf ft_printf_util ft_formatter_1 ft_formatter_2
SRCS 			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))

OBJ_DIR			=	obj/
OBJS			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@echo "$(GREEN)Compiling:$(NORMAL)"
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				@cp	$(LIBFT) $(NAME)
					@echo "$(BLUE)Adding to library...$(NORMAL)"
					@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
					@echo "$(GREEN)Successfully added to library!"

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(OBJ_DIR)

fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@echo "$(RED)Removing printflibft.a...$(NORMAL)"
					@$(RM) $(NAME)
					@echo "$(GREEN)Successfully removed libftprintf.a!"

re:					fclean all
bonus:					all

.PHONY:				all clean fclean re libft