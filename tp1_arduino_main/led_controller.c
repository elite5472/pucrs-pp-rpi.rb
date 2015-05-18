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
        int fd;
        char a;


        fd = config_serial("/dev/ttyAMA0", B9600);
        if(fd<0){
                return 0;
        }

        int ledID = 0;
        int command = 0;
        uint8_t data = 0;

        do
        {
                printf("Informe qual led deve ser ativado (1, 2, 3 ou 4) \n ou digite 0 para sair.");
                scanf("%d", &ledID);

		printf("\nInforme o comando a ser enviado ao led:\n");
		printf("0 - Desligar led.");
		printf("1 - Ligar led.");
		scanf("%d", &command);

		data = 9;
		write(fd, &data, 1); 				// Begining of message

		data = -1;
		write(fd, &data, 1); 				// NOP

		data = 1;
		write(fd, &data, 1); 				// Operation: command to the leds

		if(ledID == 1){					// led 1
			if(command == 0 || command == 1){
				write(fd, &command, 1);		// Turn Off or Turn On
			}
		}
		else{
			data = 2;
			write(fd, &data, 1);			// Keep as it is
		}

		if(ledID == 2){					// led 2
			if(command == 0 || command == 1){
				write(fd, &command, 1);		// Turn Off or Turn On
			}
		}
		else{
			data = 2;
			write(fd, &data, 1);			// Keep as it is
		}

		if(ledID == 3){					// led 3
			if(command == 0 || command == 1){
				write(fd, &command, 1);		// Turn Off or Turn On
			}
		}
		else{
			data = 2;				// Keep as it is
			write(fd, &data, 1);
		} 

		if(ledID == 4){					// led 4
			if(command == 0 || command == 1){
				write(fd, &command, 1);		// Turn Off or Turn On
			}
		}
		else{
			data = 2;				// Keep as it is
			write(fd, &data, 1);
		}

		data = 8;
		write(fd, &data, 1);				// End of message

                /*
		data = (led<<1) | op ;
                printf("%d\n", data);
                write(fd, &data, 1);

                read(fd, &data, 1);
                printf("%d\n", data);
                printf("%x %x \n", data >> 1, data & 1);
		*/
        }
        while(ledID != 0);

        close(fd);

        return 0;
}

