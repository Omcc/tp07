#include <stdio.h>
#include "tp07.h"
int main()
{

	int sensorCount;

	printf("\n Csv file is being readed");

	FILE* censor_csv = fopen("sensor_locations.csv","r");

	load_sensors(censor_csv);

	//struct Graph *graph = createGraph(2);










}

