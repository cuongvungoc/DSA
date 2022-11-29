CC:= gcc
CFLAGS:= -Wall
BALANCE_OBJ:= lib/sorting.o balenced_partition.o
BALANCE_TARGET:= balance
SORT_OBJ:= lib/sorting.o sortAlgorithms.o
SORT_TARGET:= sort

all: $(BALANCE_TARGET) $(SORT_TARGET)

$(BALANCE_TARGET): $(BALANCE_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(SORT_TARGET): $(SORT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BALANCE_TARGET) $(BALANCE_OBJ) $(SORT_TARGET) $(SORT_OBJ)