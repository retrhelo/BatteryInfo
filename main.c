/* 
	written by joel
*/

#include <string.h>
#include <stdio.h>

#include "battery.h"

int main(int argc, char **argv) {
	Battery *bat;
	md_t mode = 0;

	if (argc == 1) 
		mode = PERCENTAGE | ON_CHARGE;
	else {
		for (int i = 1; i < argc; i ++) {
			if (strcmp(argv[i], "-p") == 0) 
				mode |= PERCENTAGE;
			if (strcmp(argv[i], "-c") == 0) 
				mode |= ON_CHARGE;
			if (strcmp(argv[i], "-t") == 0) 
				mode |= REMAIN_TIME;
			if (strcmp(argv[i], "-h") == 0) {
				printf("usage: battery [-p|-c|-t|-h]\n");
				printf("-p\tshow percentage of battery\n");
				printf("-c\tshow whether battery is charging\n");
				printf("-t\tshow remaining time\n");
				printf("-h\tshow this help list\n");
				return 0;
			}
		}
	}

	if (bat = get_battery()) 
		show_battery(bat, mode);
	else 
		fprintf(stderr, "battery: programme failed\n");

	return 0;
}
