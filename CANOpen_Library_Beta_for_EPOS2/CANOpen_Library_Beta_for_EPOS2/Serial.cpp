#include "robot.h"

Serial          pc(PA_2, PA_3);
char Rx_BUFFER[BUFFER_SIZE] = {0};
int BUFFER_ITER = 0;

void SERIAL_SETUP(int baud)
{
    pc.baud(baud);
    pc.attach(&Rx_interrupt, pc.RxIrq);
}

void PC_SEND(const char* msg)
{
    pc.printf(msg);
}

void PC_SEND(const char* msg, int32_t value)
{
    pc.printf(msg, value);
}

void PC_SEND(const char* msg, uint32_t value)
{
    pc.printf(msg, value);
}

void Rx_interrupt()
{
    char c = 0;
    
    // Note: you need to actually read from the serial to clear the RX interrupt
    if (pc.readable())
    {
       do
       {
            c = pc.getc();
            Rx_BUFFER[BUFFER_ITER] = c;
            BUFFER_ITER ++;
       }
        while (BUFFER_ITER < BUFFER_SIZE && c != '\n');
    }  
     
    pc.printf(Rx_BUFFER);
}