############## COLOUR CODES ##########

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

############## CONSTANTS #############

NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror

############### SOURCES ##############

SOURCES 	:=	main.c\
				list_manip.c\
				parser.c\
				push_swap.c\
				swap.c\
				rotate.c\
				r_rotate.c\
				push.c\
				basic_algos.c\
				utils.c\

LIBRARIES	:=	./libraries/libft/libft.a\
				
HEADERS		:=	-I ./includes -I $(LIBFT)/includes			
SOURCE_DIR 	:=	./sources
INCLUDE_DIR	:= 	./includes
OBJECT_DIR	:=	./objects
LIBFT		:=	./libraries/libft
OBJECTS 	:= 	$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

############### MESSAGES ########

MESSAGE		:=	"Making $(NAME)"
MESSAGE_FIN	:=	"MAKE COMPLETE, NO ERRORS"
MESSAGE_RM	:=	"OBJECTS CLEANED"
MESSAGE_FRM	:=	"EVERYTHING CLEANED"
MESSAGE_LIB	:=	"LIBRARIES READY"

############### RUNNING ##############

all: libraries $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(LIBRARIES) -o $@ $^ $(HEADERS) -g
	@echo "$(GREEN)$(BOLD)$(MESSAGE_FIN)$(RESET)"

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@ $< -O3

run:
	make && ./$(NAME)

clean:
	@rm -f $(OBJECTS)
	@$(MAKE) fclean -C $(LIBFT)
	@echo "$(RED)$(MESSAGE_RM)$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@if [ -d "$(OBJECT_DIR)" ]; then rm -d $(OBJECT_DIR); fi
	@echo "$(RED)$(MESSAGE_FRM)$(RESET)"

libraries:
	@$(MAKE) -s -C $(LIBFT)
	@echo "$(GREEN)$(MESSAGE_LIB)$(RESET)"

re: fclean all

.PHONY: all clean fclean re libraries
