MAKEFLAGS			+= -s
NAME				= philo
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/
CC					= cc
CFLAGS				= -pthread -fsanitize=thread -Wall -Werror -Wextra -I$(INC)
RM					= rm -rf
SRCS = \
	main.c \
	$(SRC_DIR)PH1-parsing/input_parsing_manager.c \
	$(SRC_DIR)PH2-main_execution/create.c \
	$(SRC_DIR)PH2-main_execution/dinner_time.c \
	$(SRC_DIR)PH2-main_execution/dinner_time_2.c \
	$(SRC_DIR)PH2-main_execution/monitor_check.c \
	$(SRC_DIR)PH2-main_execution/start_simulation.c \
	$(SRC_DIR)PH2-main_execution/start_structs.c \
	$(SRC_DIR)PH3-cleaner/free_program.c \
	$(SRC_DIR)PHU-utils/PH1_utils_1.c \
	$(SRC_DIR)PHU-utils/PH1_utils_2.c \
	$(SRC_DIR)PHU-utils/PH1_utils_3.c \
	$(SRC_DIR)PHU-utils/PH2_utils_1.c
OBJS = \
	$(OBJ_DIR)main.o \
	$(OBJ_DIR)PH1-parsing/input_parsing_manager.o \
	$(OBJ_DIR)PH2-main_execution/create.o \
	$(OBJ_DIR)PH2-main_execution/dinner_time.o \
	$(OBJ_DIR)PH2-main_execution/dinner_time_2.o \
	$(OBJ_DIR)PH2-main_execution/monitor_check.o \
	$(OBJ_DIR)PH2-main_execution/start_simulation.o \
	$(OBJ_DIR)PH2-main_execution/start_structs.o \
	$(OBJ_DIR)PH3-cleaner/free_program.o \
	$(OBJ_DIR)PHU-utils/PH1_utils_1.o \
	$(OBJ_DIR)PHU-utils/PH1_utils_2.o \
	$(OBJ_DIR)PHU-utils/PH1_utils_3.o \
	$(OBJ_DIR)PHU-utils/PH2_utils_1.o

BOLD				= \033[1m
UNDERLINE			= \033[4m
BLINK				= \033[5m
REVERSE				= \033[7m
RED					= \033[0;31m
HIDDEN				= \033[8m
GREEN				= \033[0;32m
RESET				= \033[0m
BLOOD_RED			= \033[38;5;52m
WHITE				= \033[1;37m
BG_BLOOD_RED		= \033[48;5;124m
BG_WHITE			= \033[47m
UNDERLINE_WHITE		= \033[4;37m
UNDERLINE_BLOOD_RED	= \033[4;38;5;52m
BYELLOW				= \033[1;33m

all: 				$(NAME)

$(NAME): 			$(OBJS) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@clear
					printf "\n"
					printf "\n"
					printf "          ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"
					printf "━━━━━━━━━━┫ ${BOLD}${BLOOD_RED}𝐏 𝐡 𝐢 𝐥 𝐨 ${RESET}"
					printf "${WHITE}𝐬 𝐨 𝐩 𝐡 𝐞 𝐫 𝐬${RESET} ┃\n"
					printf "     ┏━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━┓\n"
					printf "━━━━━┫ Program has compiled ${GREEN}${BOLD}SUCCESSFULLY! ${RESET}┃\n"
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

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(OBJ_DIR)

re: 				fclean all



.PHONY: 			all clean fclean re start
