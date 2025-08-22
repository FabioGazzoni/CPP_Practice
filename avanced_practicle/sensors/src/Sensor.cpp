#include "Sensor.h"
#include "SensorTempException.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace std;

Sensor::Sensor(uint8_t id){
    this->id = id;
    temperature = 0.0f;
    
    srand(static_cast<unsigned int>(time(nullptr))); // Inicializa la semilla rand
}

void Sensor::readValue(){
    temperature = MIN_TEMPERATURE + static_cast<float>(rand()) / RAND_MAX * (MAX_TEMPERATURE - MIN_TEMPERATURE) + 5;
    
    if(temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE){
        ostringstream oss;
        oss << "Temperatura "<< temperature << " no permitida"<<endl;
        throw SensorTempException(oss.str().c_str());
    }
}

void Sensor::printValue(){
    cout<<"El sensor "<<int(id)<< " reporta una temperatura: "<<temperature<<endl;
}
