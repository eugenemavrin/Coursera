#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <termios.h>    // POSIX terminal control definitions
using namespace std;
// https://stackoverflow.com/questions/18108932/reading-and-writing-to-serial-port-in-c-on-linux
// http://programming-lang.com/ru/comp_programming/metyu/0/j174.html
int main() {
	struct termios serial;
	int USB = open( "/dev/cu.usbserial-14120", O_RDWR| O_NOCTTY | O_NDELAY );
	if ( USB > 0 ) {
		serial.c_iflag = 0;
		serial.c_cflag &=  ~PARENB;        	// Make 8n1
		serial.c_cflag &=  ~CSTOPB;
		serial.c_cflag |=  CS8;
		serial.c_cflag &=  ~CRTSCTS;       	// no flow control
		serial.c_lflag =   0;          		// no signaling chars, no echo, no canonical processing
		serial.c_oflag =   0;               // no remapping, no delays
		//serial.c_cflag = 0;

		serial.c_cc[VMIN] = 0;
		serial.c_cc[VTIME] = 5;

		serial.c_cflag = B9600 | CS8 | CREAD;

		tcsetattr(USB, TCSANOW, &serial);
		//it works
		char str[100] = "TestMac";
		int wcount = write(USB, str, strlen(str));
		if(wcount > -1)
			 cout << wcount << " symbols was transmitted successfully" << endl;
		close(USB);
	}

	return 0;
}
