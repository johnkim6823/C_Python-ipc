GCC =g++
OBJ = main_receiver.o, main_sender.o
TARGET = receiver, sender


%.o: %.cpp
	$(GCC) -c -o $@ $<

all: $(OBJ)
	$(GCC) -o receiver main_receiver.o
	$(GCC) -o sender main_sender.o

clean:
	rm -f $(OBJ) $(TARGET)
