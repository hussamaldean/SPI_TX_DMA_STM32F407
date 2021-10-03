#include "debug.h"

struct __FILE {int handle;};

FILE __stdout;
FILE __stdin;

	/*
	* @brief redirect printf function to SWO port 
  * @param  int ch for character input
	* @param  pointer to __FILE of the struct 	
  * @retval returns the passed character 
		
*/
int fputc(int ch, FILE *f)
{
  ITM_SendChar(ch);
  return(ch);
}
