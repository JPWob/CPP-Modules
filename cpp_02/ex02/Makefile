# Compiler
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# Files
SRCS = main.cpp Fixed.cpp
NAME = Now_we_are_talking

# Object files go into .o/ folder
OBJDIR = .obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

# Compile each .cpp into .obj/ folder
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Create .o folder if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re