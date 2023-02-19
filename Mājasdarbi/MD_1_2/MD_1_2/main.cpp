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

    
    iRobot R1("1.modelis","Left_sen",false, "Right_sen",false);
    
    
    int room[10] = {23, 35, 55, 74, 45, 46, 34, 77, 23, 98};
    
    
    
    R1.Run(room,10);

    
   
    

    
    
    
    

   //R1.PrintSensor();
}
