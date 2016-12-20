PREFIX_XENO :=  
EXECUTABLE := exec
LIBDIR := ./Lib
LIBS := antlr4-runtime
INCLUDES := ./Antlr4 ./dataparser ./codeparser ./utility ./rcinterpreter
SRCDIR := ./dataparser ./codeparser ./utility ./rcinterpreter

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
