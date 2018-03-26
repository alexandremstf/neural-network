COMPILER = g++ -std=c++11 -Wall -g
EXEC_PROG = neuralnetwork
BINARIES = $(EXEC_PROG)
SOURCES := $(shell find -name '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC_PROG)
	@echo Neural Network Build Completed

%.o: %.cpp
	$(COMPILER) -c -o $@ $< -w

$(EXEC_PROG): $(OBJECTS)
	$(COMPILER) -o $(EXEC_PROG) $(OBJECTS) 

# prevents make from getting confused
.PHONY : run
run:
	./$(EXEC_PROG)

.PHONY : clean 
clean:
	rm -rf $(EXEC_PROG) $(OBJECTS)