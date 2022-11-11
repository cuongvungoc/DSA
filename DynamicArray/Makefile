CC:= gcc
CFLAGS:= -Wall
DEPS:= lib/list.h
OBJ:= dynamic2.o lib/list.o
TARGET:= dynamic_array

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET) 