TARGET=battery
INSTALL_DIR=/usr/local/bin

CC=gcc
LD=gcc

# source files
SRC=main.c \
	battery.c
# object files
OBJ=$(addsuffix .o, $(basename $(SRC)))


# C compiling arguments
CFLAGS=`pkg-config --cflags glib-2.0 upower-glib`

# C linking arguments
LFLAGS=-lglib-2.0 -lupower-glib

.PHONY: build clean

build: $(OBJ)
	$(LD) $(LFLAGS) -o $(TARGET) $^

clean: 
	rm *.o $(TARGET)

