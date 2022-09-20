GCC =g++
OBJ = main_sender.o main_receiver.o
TARGET = sender receiver


%.o: %.cpp
	$(GCC) -c -o $@ $<

all: $(OBJ)
	$(GCC) -o receiver main_receiver.o
	$(GCC) -o sender main_sender.o

clean:
	rm -f $(OBJ) $(TARGET)
