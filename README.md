DHTPort
=======

Fetch DHT sensor readings through JeeNode/JeeLib Ports.

This library adapts the [DHTlib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) interface for use with [JeeLib](https://github.com/jcw/jeelib) Ports. Both of these libraries are dependencies of this adapter.



Usage
-----

This library expects the DHT data line to be connected to the digital pin of the specified JeeLib Port.

    #include <Ports.h>
    #include <dht.h>
    #include <DHTPort.h>

    #define DHT22_PORT 4 // JeeLib Port number
    DHT22Port dhtSensor(DHT22_PORT);

    int chk = dhtSensor.read();

    // handle 'chk' according to the DHTlib documentation
    if (chk == DHTLIB_OK) {
        Serial.print("humidity: ");
        Serial.println(dhtSensor.humidity(), 1);
        Serial.print("temperature: ");
        Serial.println(dhtSensor.temperature(), 1);
    }
