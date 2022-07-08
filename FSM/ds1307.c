#include "i2c.h"
#include "ds1307.h"

#define IDLE_STATE		(0U)
#define READ_STATE		(1U)
#define	READ_DONE_STATE	(2U)

char sAddres = 0x44;
char *Time_DataReadBuffer;
char ReadStartAddress;
char ReadDataLength;
unsigned char Time_IsReadRequested;


void Time_ReadData(char memoryAddress,char data[],int n)
{
	Time_DataReadBuffer =&data;
	ReadStartAddress = memoryAddress;
	ReadDataLength = n;
	Time_IsReadRequested = (unsigned char)1;
}

void Time_ManageDataRead(void)
{	
	static unsigned char currentState = IDLE_STATE;

	switch(currentState)
	{
		case IDLE_STATE:
		{
			if(Time_IsReadRequested)
			{
				currentState = READ_STATE;
			}
			
			else
			{
			/*do nothing*/
			}
		}
		break;

		case READ_STATE:
		{
			I2C1_READ(sAddres,ReadStartAddress,Time_DataReadBuffer,ReadDataLength);
			currentState = READ_DONE_STATE;
		}
		break;

		case READ_DONE_STATE: 
		{
			/*call client notification function*/
			/*client_ReadDone();*/
			currentState = IDLE_STATE;
		}
		break;

		default:{}
	}
	
}

