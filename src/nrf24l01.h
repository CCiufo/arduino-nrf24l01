#include <stdlib.h>

#ifndef _NRF24L01_H
#define _NRF24L01_H


typedef struct {
    int pipeNumber;
    uint8_t data[32];
    size_t length;
} nRF24L01Message;

class nRF24L01 {
    
    public:
        nRF24L01(int slaveSelectPin, int chipEnabledPin);
        void begin();
        
        uint8_t sendCommand(uint8_t command, void *data, size_t length);
        
        uint8_t writeRegister(uint8_t regAddress,
            void *data, size_t length);
        uint8_t readRegister(uint8_t regAddress,
            void *data, size_t length);
        
        uint8_t noOp();
        uint8_t updateStatus();
        uint8_t getStatus();
        
        void listen(int pipe, void *address);
        bool dataReceived();
        void readReceivedData(nRF24L01Message *message);        
        
        void transmit(void *address, nRF24L01Message *msg);
        int transmitSuccess();
        
        void clearInterrupts();
        void clearTransmitInterrupts();
        void clearReceiveInterrupt();
        
    private:
        int slaveSelectPin;
        int chipEnabledPin;
        
        uint8_t status;
};

#endif
