#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <glib.h>
#include <upower.h>

#include "battery.h"

struct battery {
	gint percentage;
	gboolean charge;
	gint time;
};

static gchar info[1024];	/* store the information of device */
static gboolean _contains(UpDevice *dev, char *str) {
	gchar *p = info;

	strncpy(info, up_device_to_text(dev), 1024);
	while (*p) {
		if (strncmp(p ++, str, strlen(str)) == 0) 
			return 1;
	}

	return 0;
}

/* 
	initialize, meanwhile find the device related to battery
	it stores information about battery in info[]
	return 1 if success, 0 if failure
*/
static gboolean _initialize(void) {
	GPtrArray *gpa;
	UpClient *client;
	gint i;

	if (client = up_client_new()) {
		if (gpa = up_client_get_devices(client)) {
			for (i = 0; i < gpa->len; i ++) 
				if (_contains(g_ptr_array_index(gpa, i), "BAT")) 
					return 1;
		}
	}

	return 0;
}

static Battery *get_bat(void) {
	gchar const *p;
	Battery *bat;

	bat = (Battery*)malloc(sizeof(Battery));
	if (bat) {
		/* load battery percentage */
		p = info;
		while (*p && strncmp(p, "percentage", strlen("percentage"))) 
			p ++;
		if (*p == '\0') 	/* if battery percentage not found */
			bat->percentage = -1;
		else {
			while (!isdigit(*p)) 
				p ++;
			if (isdigit(p[2])) 		/* in this case, battery is full */
				bat->percentage = 100;
			else 
				bat->percentage = (p[0] - '0') * 10 + (p[1] - '0');
		}

		/* load whether battery is charging */
		p = info;
		while (*p && strncmp(p, "state", strlen("state"))) 
			p ++;
		if (*p == '\0') 
			bat->charge = 0;
		else {
			while (*++p != ':')
				;
			while (!isalpha(*p)) 
				p ++;
			if (strncmp(p, "discharging", strlen("discharging")) == 0) 
				bat->charge = 0;
			else 
				bat->charge = 1;
		}

		/* so far we are not ready to load remaining/charging time */
		bat->time = -1;
	}

	return bat;
}

Battery *get_battery(void) {
	if (_initialize()) 
		return get_bat();

	return NULL;
}

#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define RED			"\e[31m"
#define WHITE		"\e[0m"
void show_battery(Battery *bat, md_t mode) {
	if (mode & ON_CHARGE) 		/* display whether it is charging */
		printf("state: %s\n", 
			bat->charge ? "charging" : "discharging");
	if (mode & PERCENTAGE) {	/* display the percentage */
		gint per = bat->percentage / 5;
		/* set color */
		if (per <= 3) 
			printf(RED);
		else if (per <= 10) 
			printf(YELLOW);
		else 
			printf(GREEN);
		for (gint i = 0; i < per; i ++) 
			putchar('#');
		printf(WHITE"\t\t%3d%%\n", bat->percentage);
	}
	if (mode & REMAIN_TIME) {	/* show remaining time */
		if (bat->charge) 
			printf("time to full: ");
		else 
			printf("time to empty: ");
		if (bat->time == -1) 
			printf("unkonwn\n");
		else 
			printf("%02d:%02d\n", bat->time / 60, bat->time % 60);
	}
}
