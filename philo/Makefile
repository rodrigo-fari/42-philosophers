# Makeflag
MAKEFLAGS += -s

# Nome do executável
NAME				= philo

# Diretórios
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compilador e flags
CC					= cc
CFLAGS				= -pthread -fsanitize=thread -Wall -Werror -Wextra -I$(INC)
RM					= rm -rf

# Arquivos-fonte
SRCS				= $(wildcard $(SRC_DIR)*.c)


# Arquivos-objeto
OBJS				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Regras principais
all: 				$(NAME)

# Regra para criar o executável
$(NAME): 			$(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
					@clear
					@echo " "
					@echo " "
					@echo "        ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄  "
					@echo "       ███    ███   ███    ███   ███  ███       ███    ███ "
					@echo "       ███    ███   ███    ███   ███▌ ███       ███    ███ "
					@echo "       ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███ "
					@echo "     ▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███ "
					@echo "       ███          ███    ███   ███  ███       ███    ███ "
					@echo "       ███          ███    ███   ███  ███▌    ▄ ███    ███ "
					@echo "      ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀  "
					@echo "                                      ▀                    "
					@echo " "
					@echo " "
					@sleep 1

# Regra para compilar objetos
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "🔧 Compiling... $<"

# Compilação da libft
$(LIBFT):
					@make -C ./libft

# Limpeza
clean:
					@$(RM) $(OBJ_DIR)/*
					@make clean -C ./libft
					clear
					@echo " "
					@echo "🗑️ All objects removed."
					@echo " "

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(OBJ_DIR)
					@make fclean -C ./libft
					@clear
					@echo " "
					@echo " "
					@echo "        ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄  "
					@echo "       ███    ███   ███    ███   ███  ███       ███    ███ "
					@echo "       ███    ███   ███    ███   ███▌ ███       ███    ███ "
					@echo "       ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███ "
					@echo "     ▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███ "
					@echo "       ███          ███    ███   ███  ███       ███    ███ "
					@echo "       ███          ███    ███   ███  ███▌    ▄ ███    ███ "
					@echo "      ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀  "
					@echo "                                      ▀                    "
					@echo " "
					@echo " "
					@echo "🗑️ All clean."
					@echo " "

re: 				fclean all

# Targets auxiliares
start:				
					@make all

# Marcar alvos como phony
.PHONY: 			all clean fclean re start
