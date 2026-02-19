
# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source file
SRC = megaphone.cpp

# Output executable
NAME = megaphone

# Default target
all: $(NAME)

# Compile
$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

# Clean compiled files (not needed here but common practice)
clean:
	@rm -f $(NAME)

# Rebuild everything
fclean: clean

re: fclean all

.PHONY: all clean fclean re