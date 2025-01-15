# **************************************************************************** #
#                                                                              #
#          ##\     /##      #|  #  /   ####  ####  *  #    ####                #
#          ## \   / ##     # |  # /    #     #     #  #    #                   #
#          ##  \ /  ##    #__|  # \    ###   ####  #  #    ###                 #
#          ##       ##   #   |  #  \   #     #     #  #    #                   #
#          ##       ##  #    |  #   \  ####  #     #  #### ####      <><       #
#                                                                              #
# **************************************************************************** #

############## Defining ANSI colors ###############

RED_BOLD	  := $(shell echo "\033[1;31m")
GREEN_BOLD	:= $(shell echo "\033[1;32m")
PURPLE  := $(shell echo "\033[0;35m")
BLUE	 := $(shell echo "\033[0;34m")
CYAN	:= $(shell echo "\e[0;36m")
CYAN_BOLD	:= $(shell echo "\e[1;36m")
RESET	:= $(shell echo "\033[0m")

############## Functions to printf colors ###############

text = @echo "$(PURPLE)$(1)$(RESET)"
warn = @echo "$(BLUE)$(1)$(RESET)"
error = @echo "$(RED_BOLD)$(1)$(RESET)"
success = @echo "$(GREEN_BOLD)$(1)$(RESET)"
highligth = @echo "$(CYAN)$(1)$(RESET)"
highligth_bold = @echo "$(CYAN_BOLD)$(1)$(RESET)"

#################### Files #####################

NAME= libftprintf.a

#SRC_DIR = $(wildcard *.c)
OBJ_DIR = $(SRC_DIR:.c=.o)

################## Compilation ##################

CC= cc
CFLAGS= -Wall -Wextra -Werror

################### Commands ###################

RM= rm -f

SRC_DIR= ft_printf.c ft_printf_utils.c

################################################

all: $(NAME)

$(NAME): $(OBJ_DIR)
	$(call success, "All files have been compiled ✅")
	$(call text, "Creating library $(NAME) [...]")
	@ar rcs $(NAME) $(OBJ_DIR)
	$(call success, "Build complete: $(NAME) 📚 ✨")

%.o: %.c 
	$(call warn, "Compiling [...] $<")
	@$(CC) $(CFLAGS) -c $< -o $@

################ Clean-up Rules ################

clean:
	$(call text, "Removing object files [...]")
	@$(RM) $(OBJ_DIR)
	$(call success, "Object files cleaned. 💣"); \

fclean: clean
	$(call text, "Removing library file...")
	@$(RM) $(NAME)
	$(call success, "Library file cleaned. 💥")

re: fclean all
	$(call success, "All files have been recompiled ✅")

#################### Manual #####################

manual:
	@echo "$(CYAN_BOLD)\n\t\tFT_PRINTF MANUAL$(RESET)"
	@echo "$(CYAN_BOLD)\t---------------------------------$(RESET)"
	@echo "$(CYAN_BOLD)\t%c$(RESET)	$(CYAN)Print a single character.$(RESET)"
	@echo "$(CYAN_BOLD)\t%s$(RESET)	$(CYAN)Print a string.$(RESET)"
	@echo "$(CYAN_BOLD)\t%p$(RESET)	$(CYAN)The address of a pointer.$(RESET)"
	@echo "$(CYAN_BOLD)\t%d$(RESET)	$(CYAN)Print a decimal (base 10) number.$(RESET)"
	@echo "$(CYAN_BOLD)\t%i$(RESET)	$(CYAN)Print an integer in base 10.$(RESET)"
	@echo "$(CYAN_BOLD)\t%u$(RESET)	$(CYAN)Print an unsigned decimal (base 10) number.$(RESET)"
	@echo "$(CYAN_BOLD)\t%x$(RESET)	$(CYAN)Print a number in hexadecimal (base 16) lowercase format.$(RESET)"
	@echo "$(CYAN_BOLD)\t%X$(RESET)	$(CYAN)Print a number in hexadecimal (base 16) uppercase format.$(RESET)"
	@echo "$(CYAN_BOLD)\t%%$(RESET)	$(CYAN)Print a percent sign.\n$(RESET)"	
	

#################### Help #####################

help:
	@echo "$(CYAN_BOLD)\n\tAVAILABLE OPTIONS:$(RESET)"
	@echo "$(CYAN_BOLD)\t---------------------------------$(RESET)"
	@echo "$(CYAN)\tmake			- Compiles the project and creates the library $(NAME).$(RESET)"
	@echo "$(CYAN)\tmake clean		- Removes object files (.o).$(RESET)"
	@echo "$(CYAN)\tmake fclean	  	- Removes object files and the library $(NAME).$(RESET)"
	@echo "$(CYAN)\tmake re			- Cleans and recompiles the project.$(RESET)"
	@echo "$(CYAN)\tmake help		- Displays this help message.$(RESET)"
	@echo "$(CYAN)\tmake manual		- Displays the ft_printf manual.$(RESET)"



.PHONY: all clean fclean re help manual
