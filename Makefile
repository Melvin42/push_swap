## Name of Project

NAME =			push_swap

## Color for compiling (pink)

COLOR =			\0033[1;35m

## List of Directories

INC_DIR =		include
OBJ_DIR = 		obj
SRC_DIR	= 		src

# Add dirs here

LIBS =			-L/usr/include

## Compiling Utilities

#FAST =			-Ofast

SANITIZE =		-fsanitize=address

DEBUG =			-g3 #${SANITIZE}

FLAGS =			-Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

INC =			-Iinclude

CC =			clang $(FLAGS) $(INC)

#HOW TO LIST .c 
#	ls -l | awk '{print $9}' | grep -E ".c$"| sed "s/\.c/ \\\/g" | sed '$s/\\$//g'

SRC_FT =	\
			cases \
			free \
			lst \
			lst_utils \
			ft_atoi \
			main \
			operations \
			prepare_b \
			ft_check_int_max \
			ft_check_double \
			put_on_top \
			min_max \
			create_chunk \
			push_back_in_a \
			double_operations \
			chunk_utils \
			search_median \
			ft_memset \
			ft_check_already_sort \
			ft_lstcpy \
			search \
			chunk \
			tab \
			utils

## List of Utilities

SRC =			$(SRC_FT:%=$(SRC_DIR)/%.c)

OBJ =			$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS =		$(OBJ_DIR)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC)
	@$(MAKE) -j -s $(OBJ)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(CC) $(OBJ) -o $@
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

re:	fclean all

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "             \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                                {"
	@echo "                             {   }"
	@echo "                              }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                           \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                          \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                          \0033[1;34m| -.._____..- |"
	@echo "                          |             ;--."
	@echo "                          |            (__  \ "
	@echo "                          |             | )  )"
	@echo "                          |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                          |             /  / "
	@echo "                          |            (  / "
	@echo "                          \             | "
	@echo "                            -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                    Take Your Coffee"
	$(call print_aligned_coffee)

.PHONY: all clean fclean re coffee
