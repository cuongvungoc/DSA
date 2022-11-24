CC:= gcc
CFLAGS:= -Wall
DEPS:= DoubleLinkedList/dll.h
REVERSE_OBJ:= DoubleLinkedList/reverse.o DoubleLinkedList/lib/dll.o
REVERSE_TARGET:= reverse 
RM_FRIEND_OBJ:= SinglyLinkedlist/lib/linkedlist.o SinglyLinkedlist/remove_friend.o
RM_FRIEND_TARGET:= remove_friend

# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

all: $(REVERSE_TARGET) $(RM_FRIEND_TARGET)

$(REVERSE_TARGET): $(REVERSE_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(RM_FRIEND_TARGET): $(RM_FRIEND_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(REVERSE_OBJ) $(REVERSE_TARGET) $(RM_FRIEND_TARGET) $(RM_FRIEND_OBJ)