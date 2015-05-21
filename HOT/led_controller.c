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

  do
  {
    printf("\nInforme qual LED deve ser ativado: \n1 - LED 1 \n2 - LED 2 \n3 - LED 3 \n4 - LED 4 \n0 - Sair\n");
	//printf("0 - Desligar. \n1 - Ligar.\n");
	scanf("%d",&led);
    write(serial, &led, 1);
  }
  while(led != 0);

  close(serial);
  return 0;

}
