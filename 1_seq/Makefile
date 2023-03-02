CXX=g++
CFLAGS=-g -Wall

SRC=$(wildcard *.cc)
HDR=$(wildcard *.h)
OBJ=$(SRC:%.cc=%.o)
EXE=seq

.PHONY: default clean

default: $(EXE)
	./$(EXE) 1>output.log
	cat output.log

%.o: %.cc $(HDR)
	$(CXX) $(CFLAGS) -o $@ -c $<

$(EXE): $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXE)