//
//  main.cpp
//  MD_1_2
//
//  Created by Eriks Karklins on 16/02/2023.
//

#include <iostream>
#include <string>
#include "Header.h"


using namespace std;

int main() {

    
    iRobot R1("1.modelis","Left_sen",false, "Right_sen",false);// 1.robota nosaukums, kreisā sensora stāvoklis, labā sensorastāvoklis
    int room_R1[10] = {23, 35, 55, 74, 41, 43, 34, 77, 23, 98};// 1.robota room
    
    iRobot R2("2.modelis","Left_sen",false, "Right_sen",false);
    int room_R2[10] = {23, 35, 55, 74, 44, 47, 34, 77, 23, 98};
    
    
    R1.SwitchOnOff();// ieslēdzam sensorus ja izslēgti state false mainam uz true
    R1.Run(room_R1);// laižam pa room
    
    R2.SwitchOnOff();
    R2.Run(room_R2);
    
    R1.PrintRobot();// izvadam informāciju par robotu
    R2.PrintRobot();

    
    

}
