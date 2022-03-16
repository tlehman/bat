
// bat.c displays the battery capacity (assumes two batteries)
#include <stdio.h>

int capacity(int battery_number) {
	char filename[50];
	sprintf(filename, "/sys/class/power_supply/BAT%d/capacity", battery_number);
	int cap = 0;
	// 0-100 with a newline at the end (max 4 chars)
	char capacity_str[4];
	FILE *fp = fopen(filename, "r");
	if(fp) {
		fscanf(fp ,"%d", &cap);
		fclose(fp);
	}	
	return cap;
}

void printcap(int idx, int cap) {
	printf("Battery #%d (%d)%%: [", idx, cap);
	for(int i = 0; i < cap; i++) {
	  printf("#");
	}
	for(int i = 0; i < 100-cap; i++) {
	  printf("-");
	}
	
	printf("]\n");
}

int main(int argc, char *argv[]) {
	int capacity1 = capacity(0);
	int capacity2 = capacity(1);
	printcap(1, capacity1);
	printcap(2, capacity2);
	return 0;
}

