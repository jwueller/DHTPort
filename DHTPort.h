#ifndef DHTPORT_H
#define DHTPORT_H

#include <JeeLib/Ports.h>

#include <DHTlib/dht.h>

#define DHTPORT_VERSION "1.0.0"

class DHTPort : private Port {
public:
    virtual int read() = 0;

    inline double humidity() const {
        return m_dht.humidity;
    }

    inline double temperature() const {
        return m_dht.temperature;
    }

protected:
    dht m_dht;

    inline DHTPort(uint8_t num) : Port(num) {}

    inline uint8_t pin() const {
        return digiPin();
    }
};

class DHT11Port : public DHTPort {
public:
    inline DHT11Port(uint8_t num) : DHTPort(num) {}

    inline virtual int read() { 
        return m_dht.read11(pin());
    }
};

class DHT21Port : public DHTPort {
public:
    inline DHT21Port(uint8_t num) : DHTPort(num) {}
    
    inline virtual int read() { 
        return m_dht.read21(pin());
    }
};

class DHT22Port : public DHTPort {
public:
    inline DHT22Port(uint8_t num) : DHTPort(num) {}
    
    inline virtual int read() { 
        return m_dht.read22(pin());
    }
};

class DHT33Port : public DHTPort {
public:
    inline DHT33Port(uint8_t num) : DHTPort(num) {}
    
    inline virtual int read() { 
        return m_dht.read33(pin());
    }
};

class DHT44Port : public DHTPort {
public:
    inline DHT44Port(uint8_t num) : DHTPort(num) {}
    
    inline virtual int read() { 
        return m_dht.read44(pin());
    }
};

#endif /* DHTPORT_H */
