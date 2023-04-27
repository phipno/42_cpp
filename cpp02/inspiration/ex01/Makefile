NAME := fixedPoint
SHELL = bash
CPP := c++
CPPFLAGS := -std=c++98 -Wall -Wextra -Werror
INCREMENT := 10
BAR := "\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#\#"
SPACES := "                    "
END := 20


SRC := main.cpp Fixed.cpp
OBJ := $(SRC:.cpp=.o)

DEPS := Fixed.hpp

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo
	@clear
	@printf "\033[32;1mCompilation Completed\033[0m\n"
	@printf "\033[32;3mProgram name: $(NAME)\033[0m\n"

%.o: %.cpp $(DEPS)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@make progress_bar

progress_bar:
	@limit=0; \
	files="$(OBJ)"; \
	for i in $$files; do \
		if [ -e $$i ]; then \
          limit=$$((limit+$(INCREMENT))); \
        fi;\
	done;\
	printf "\033[32m"; \
	bar=$(BAR); \
	spaces=$(SPACES); \
	echo -ne "\r$${bar:0:$$limit}$${spaces:0:$$(($(END)-limit))}|"; \
	printf "\033[0m"; \

clean:
	@rm -rf $(OBJ)
	@clear
	@printf "\033[31mObject files cleaned\033[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "\033[31mExecutable cleaned\033[0m\n"

re: fclean all
