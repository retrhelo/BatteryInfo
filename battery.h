/* 
	device.h: 
	This header file is the interface for device.c. It includes some
	functions to get device information. 

	written by joel
*/

#ifndef __BATTERY_H
#define __BATTERY_H

/* 
	struct battery contains the information that 
	the user may want to see
*/
struct battery;
typedef struct battery Battery;

/* 
	mode_t type is used to indicate show_battery() about 
	which information about the battery is to be shown
*/
typedef unsigned char md_t;
#define PERCENTAGE	0x01	/* the percentage of the battery */
#define ON_CHARGE	0x02	/* whether the battery is been charging */
#define REMAIN_TIME	0x04	/* the remaining time of battery */

/* 
	get the information of the battery
*/
Battery *get_battery(void);

/* 
	display the information of the battery
*/
void show_battery(Battery *bat, md_t mode);

#endif
