TARGET=battery
INSTALL_DIR=/usr/local/bin

CC=gcc

# source files
SRC=main.c \
	battery.c
# object files
OBJ=$(SRC:.c=.o)


# C compiling arguments
C_ARGS=`pkg-config --cflags glib-2.0 upower-glib`

# C linking arguments
C_LINK=-lglib-2.0 -lupower-glib

build: $(OBJ)
	$(CC) $(C_LINK) -o $(TARGET) $^

# root permission required!
install: $(TARGET)
	mv $(TARGET) $(INSTALL_DIR)

%.o: %.c
	$(CC) $(C_ARGS) -c $<

clean: 
	rm $(OBJ) $(TARGET)
