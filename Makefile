battery: battery.o main.o
	cc battery.o main.o -o battery -lglib-2.0 -lupower-glib
install: battery
	# root permission required!
	mv battery /usr/local/bin
clean: battery.o main.o battery
	rm battery.o main.o battery

battery.o: battery.c
	cc -c battery.c `pkg-config --cflags glib-2.0 upower-glib`
main.o: main.c
	cc -c main.c
