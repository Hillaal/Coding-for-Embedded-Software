
#include "poller.h"
#include "device.h"
#include "client.h"

int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;

void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		Get_Data();

	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}
