PREFIX_XENO :=  
EXECUTABLE := exec
LIBDIR := ./lib
LIBS := antlr4-runtime
INCLUDES := ./Antlr4 ./dataparser ./codeparser ./utility
SRCDIR := ./dataparser ./codeparser ./utility

CC = gcc
CXX = g++
CFLAGS := -std=c++11 -g -w

CPPFLAGS += $(CFLAGS) $(addprefix -I,$(INCLUDES))

RM-F := rm -f

SRCS := $(wildcard *.cpp) $(wildcard $(addsuffix /*.cpp, $(SRCDIR)))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY : all clean rebuild

all: $(EXECUTABLE)

clean:
	@$(RM-F) ${OBJS}

rebuild: clean all

$(EXECUTABLE) : $(OBJS)
	$(CXX) -o $(EXECUTABLE) $(OBJS) $(addprefix -L,$(LIBDIR)) $(addprefix -l,$(LIBS))
