GCC = g++

OBJS = pa2Functions.o

default: Q1

HelloWorld: $(OBJS)
	$(GCC) -o Q1 $(OBJS)

pa2Functions.o: pa2Functions.cpp pa2Functions.h
	$(GCC) -c pa2Functions.cpp -o pa2Functions.o

clean: 
	rm $(OBJS) Q1