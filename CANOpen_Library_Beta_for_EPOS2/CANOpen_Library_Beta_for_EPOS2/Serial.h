/*
README
*/

#define BUFFER_SIZE 255

//**FUNCTIONS DECLARATION
void PC_SEND(const char* msg);
void PC_SEND(const char* msg, int32_t value);
void PC_SEND(const char* msg, uint32_t value);
void SERIAL_SETUP(int baud);
void Rx_interrupt();
