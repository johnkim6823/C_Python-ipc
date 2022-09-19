GCC =g++
OBJ = main_receiver.o
TARGET = receiver


%.o: %.cpp
	$(GCC) -c -o $@ $<

all: $(OBJ)
	$(GCC) -o receiver main_receiver.o

clean:
	rm -f $(OBJ) $(TARGET)
