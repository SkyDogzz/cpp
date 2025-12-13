NAME	:= easy_find
CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS	:= Span.cpp main.cpp
OBJDIR	:= obj
BINDIR	:= bin
OBJS 	:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

ifeq ($(DEBUG), 0)
	CFLAGS += -DVERBOSE=0
else
	CFLAGS += -DVERBOSE=1 -g3
endif

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
