CC := arm-none-linux-gnueabi-gcc
LD := arm-none-linux-gnueabi-gcc
CFLAGS := -g -Wall -Werror
LDFLAGS := -static

OBJECTS := prinfo.o list.o
EXE := test_ptree

all : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXE) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJECTS)
	rm -f $(EXE)

.PHONY: clean
