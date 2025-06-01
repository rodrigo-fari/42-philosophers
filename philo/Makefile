MAKEFLAGS			+= -s
NAME				= philo
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/
CC					= cc
CFLAGS				= -pthread -fsanitize=thread -Wall -Werror -Wextra -I$(INC)
RM					= rm -rf
SRCS				= $(wildcard $(SRC_DIR)*.c)
OBJS				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

BOLD				= \033[1m
UNDERLINE			= \033[4m
BLINK				= \033[5m
REVERSE				= \033[7m
RED					= \033[0;31m
HIDDEN				= \033[8m
GREEN				= \033[0;32m
RESET				= \033[0m
BLOOD_RED			= \033[38;5;52m
WHITE				= \033[0;37m
BG_BLOOD_RED		= \033[48;5;124m
BG_WHITE			= \033[47m
UNDERLINE_WHITE		= \033[4;37m
UNDERLINE_BLOOD_RED	= \033[4;38;5;52m

all: 				$(NAME)

$(NAME): 			$(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@clear
					printf "\n"
					printf "\n"
					printf "          ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
					printf "          ┃ ${BOLD}${BLOOD_RED}𝐏 𝐡 𝐢 𝐥 𝐨 ${WHITE}𝐬 𝐨 𝐩 𝐡 𝐞 𝐫 𝐬 ${RESET}┃\n"
					printf "     ┏━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━┓\n"
					printf "     ┃ Program has compiled ${GREEN}${BOLD}${BLINK}SUCCESSFULLY! ${RESET}┃\n"
					printf "     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
					printf "\n"
					printf "\n"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@
					@echo "🔧 Compiling... $<"

clean:
					@$(RM) $(OBJ_DIR)/*
					@clear
					printf "\n"
					printf "\n"
					printf "      ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
					printf "      ┃ ${BOLD}${BLOOD_RED}𝐏 𝐡 𝐢 𝐥 𝐨 ${UNDERLINE}${WHITE}𝐬 𝐨 𝐩 𝐡 𝐞 𝐫 𝐬 ${RESET}┃\n"
					printf "     ┏┻━━━━━━━━━━━━━━━━━━━━━━━━━┻┓\n"
					printf "     ┃ Program has been ${RED}${BOLD}${BLINK}DELETED. ${RESET}┃\n"
					printf "     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"
					printf "\n"
					printf "\n"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(OBJ_DIR)

re: 				fclean all



.PHONY: 			all clean fclean re start
