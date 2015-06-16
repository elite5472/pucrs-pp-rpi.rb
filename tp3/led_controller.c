#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

int config_serial(char * device, unsigned int baudrate){
  struct termios options;
  int fd;

  fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY );
  if (fd < 0)
  {
    /*
        * Could not open the port.
     */

    perror("config_serial: Não pode abrir a serial - ");
    return -1;
  }

  fcntl(fd, F_SETFL, 0);

  /*
    * Get the current options for the port...
   */
  tcgetattr(fd, &options);

  /* sets the terminal to something like the "raw" mode */
  cfmakeraw(&options);

  /*
    * Set the baudrate...
   */
  cfsetispeed(&options, baudrate);
  cfsetospeed(&options, baudrate);

  /*
    * Enable the receiver and set local mode...
   */
  options.c_cflag |= (CLOCAL | CREAD);

  /*
     * No parit, 1 stop bit, size 8
   */
  options.c_cflag &= ~PARENB;
  options.c_cflag &= ~CSTOPB;
  options.c_cflag &= ~CSIZE;
  options.c_cflag |= CS8;


  /*
     * Clear old settings
   */
  options.c_cflag &= ~CRTSCTS;
  options.c_iflag &= ~(IXON | IXOFF | IXANY);

  /* non-caninical mode */
  options.c_lflag &= ~ICANON; 

  /*
    * Set the new options for the port...
   */
  tcsetattr(fd, TCSANOW, &options);

  /* configura a tty para escritas e leituras não bloqueantes */
  //fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK);

  return fd;
}


int main(int argc, char** argv){
  int serial;

  serial = config_serial("/dev/ttyAMA0", B9600); // abre a porta 
  if(serial<0){                                  // serial 9600
    return 0;
  }

  int led;
  int command;

  if(argv[1] == "0") command = 0;
  else if (argv[1] == "1") command = 1;
  else if (argv[1] == "2") command = 2;
  else if (argv[1] == "3") command = 3;
  else if (argv[1] == "4") command = 4;
  else if (argv[1] == "5") command = 5;

  write(serial, &command, 1);

  close(serial);
  return 0;

}
