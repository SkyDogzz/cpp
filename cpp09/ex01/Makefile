NAME	:= RPN
CXX		:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS	:= main.cpp RPN.cpp
OBJDIR	:= obj
BINDIR	:= bin
OBJS 	:= $(SRCS:%.cpp=$(OBJDIR)/%.o)

ifeq ($(DEBUG), 0)
	CXXFLAGS += -DVERBOSE=0
else
	CXXFLAGS += -DVERBOSE=1 -g3
endif

all: $(BINDIR)/$(NAME)

$(BINDIR)/$(NAME): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✅ Build complete: $(NAME)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
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
