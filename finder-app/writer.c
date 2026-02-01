#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>
int main(int argc, char*argv[]) 
{
	openlog("Assignment2:", LOG_CONS, LOG_USER);
	int retVal = 0;
	if(argc != 3)
	{
		// Print error
		syslog(LOG_ERR, "Invalid number of arguments");
		retVal = 1;
	}
	else
	{
		FILE * file = fopen(argv[1], "w+");
		if(file == NULL)
		{
			// Error occurred, log error
			syslog(LOG_ERR, "file could not open, errorcode %d",errno);
		}
		else
		{
			// Write data
			int byteswritten = fwrite(argv[2], 1, strlen(argv[2]), file);
			if(byteswritten != strlen(argv[2]))
			{
				// Log error
				syslog(LOG_ERR, "File could not be written, error code %d", errno);
			}
			else
			{
				syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
			}
			fclose(file);
		}
	}
	return retVal;
}
