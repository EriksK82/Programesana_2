//
//  Header.h
//  MD_1_2
//
//  Created by Eriks Karklins on 16/02/2023.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>

using namespace std;

class ProximitySensor {
public:
    ProximitySensor(string, bool);
    bool GetState();
    bool Scan(int);
    void PrintSensor();
    //vai vajag private
    string serial_number;
    bool state;
};


class iRobot {
public:
    iRobot(string, string, bool,string, bool);
    void SwitchOnOff();
    void Run(int arr[]);
    void PrintRobot();
    //vai vajag private
    string model_name;
    ProximitySensor LeftSensor;
    ProximitySensor RightSensor;
    string alarm;
    string map[10]={};
};

#endif /* Header_h */
