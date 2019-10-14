#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
using namespace std;

int main() {
	struct termios serial;

	string device_path = "/dev/serial0";
    //int fd = open(device_path, O_RDWR | O_NOCTTY | O_NDELAY);
	int fd = 0;
	if(fd != -1) {
		// Set up Serial Configuration
		    serial.c_iflag = 0;
		    serial.c_oflag = 0;
		    serial.c_lflag = 0;
		    serial.c_cflag = 0;

		    serial.c_cc[VMIN] = 0;
		    serial.c_cc[VTIME] = 0;

		    serial.c_cflag = B115200 | CS8 | CREAD;

		    tcsetattr(fd, TCSANOW, &serial); // Apply configuration
		    string q;
		    cout << "q = ";
		    cin >> q;
		    cout << endl;
		    while (q > 0) {
		    	q--;
		    	 printf("Sending: %s\n", str);

		    	    int wcount = write(fd, str, strlen(str));
		    	    if (wcount < 0) {
		    	        perror("Write");
		    	        return -1;
		    	    }
		    	    int rcount = read(fd, buffer, sizeof(buffer));
		    	    else {
		    	        printf("Received %d characters\n", rcount);
		    	    }

		    	    buffer[rcount] = '\0';

		    	    printf("Received: %s\n", buffer);
		    }


	}
	return 0;
}
