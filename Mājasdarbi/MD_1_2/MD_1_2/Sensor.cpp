//
//  Sensor.cpp
//  MD_1_2
//
//  Created by Eriks Karklins on 16/02/2023.
//

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;


ProximitySensor::ProximitySensor(string SN, bool ST=false) {// serial number, status - "izslēgts = false"
    serial_number = SN;
    state = ST;
}

bool ProximitySensor::GetState(){
    
    return state;
}

bool ProximitySensor::Scan(int area) {
   
    if (area % 2 == 0) {
//        cout<<" Para-";//pāra
//        cout<<area;
        return false;
    }
//    cout<<" Nepara- ";//nepāra
//    cout<<area;
    
return true;
}

void ProximitySensor::PrintSensor() {
    cout<<serial_number<<" " <<state<<endl;
}


