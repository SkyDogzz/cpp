NAME	:= bsp
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS	:= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJDIR	:= obj
BINDIR	:= bin
OBJS 	:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "✅ Build complete: $(NAME)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "🛠️ Compiled: $<"

-include $(OBJS:.o=.d)

clean:
	rm -rf $(OBJDIR)
	@echo "🧹 Cleaned object files"

fclean: clean
	rm -rf $(BINDIR)
	@echo "🧹 Fully cleaned (bin + obj)"

re: fclean all

.PHONY:
	all clean fclean re
