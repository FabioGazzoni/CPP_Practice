#include "LED.h"
#include "Sensor.h"
#include "Buzzer.h"
#include "DevicesException.h"
#include "SensorTempException.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main(void){
    // LED *led_1 = new LED();
    // led_1->turnOn();
    // led_1->status();
    // led_1->toggle();
    // led_1->status();
    
    // delete led_1;
    
    vector<unique_ptr<Sensor>> sensors;

    for(int i = 0; i<5; i++){
        sensors.push_back(make_unique<Sensor>(i));
    }

    for(auto& s : sensors){
        try{
            s->readValue();
        }catch(SensorTempException& e){
            cerr<<"Error en t:"<<e.what()<<endl;
            exit(1);
        }
        s->printValue();
    }

    vector<unique_ptr<Device>> devices;

    try{
        devices.push_back(make_unique<Buzzer>(3));
        devices.push_back(make_unique<LED>(2));
    }catch(const DevicesException& e){
        cerr<<"Error: "<<e.what()<<endl;
        exit(1);
    }catch(...){
        cerr<<"Other error catched"<<endl;
        exit(1);
    }
    

    for(auto& d : devices){
        d->turnOn();
        d->status();
    }

    return 0;
}