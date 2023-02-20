//
//  robot.cpp
//  MD_1_2
//
//  Created by Eriks Karklins on 16/02/2023.
//

#include <iostream>
#include <string>

#include "Header.h"

using namespace std;

iRobot::iRobot(string m_Name , string SN_R, bool S_R, string SN_L,  bool SL)
:   RightSensor(SN_R,S_R),
    LeftSensor(SN_L,SL)
{
    model_name = m_Name;
    
}

void iRobot:: SwitchOnOff(){
    
    int R = RightSensor.GetState();
    int L = LeftSensor.GetState();
    
    if (R== false && L == false) {
        //cout<<"ieslegt 1";
        RightSensor.state = true;
        LeftSensor.state = true;
        
    } else if (R== true && L == false){
        //cout<<"ieslegt 2";
        RightSensor.state = true;
        LeftSensor.state = true;
        
    } else if ((R== false && L == true)){
        //cout<<"ieslegt 3";
        RightSensor.state = true;
        LeftSensor.state = true;
        
    } //else
        //cout<<"Ieslēgts";
}
void iRobot:: Run(int arr[]){
    
    int l_s = LeftSensor.state;
    int r_s = RightSensor.state;
    
    if (l_s == false || r_s == false ) {
        cout<<"lūdzu ieslēgt sensoru"<<endl;
    } else {
        
        for (int i = 0; i < 10; i++)
        {
            
            int l = LeftSensor.Scan(arr[i] % 10);
            int r = RightSensor.Scan(arr[i] / 10 );
            
            if (l==false &&  r == false) {
                iRobot::alarm = "Red";
                return;
                
            } else if(l==true &&  r == true)
            {
                //cout<<"f";
                iRobot::map[i]='f';
                iRobot::alarm = "green";
                
            } else if(l==false &&  r == true)
            {
                //cout<<"l";
                iRobot::map[i]='l';
                iRobot::alarm = "green";
                
            } else if(l==true &&  r == false)
            {
                //cout<<"r";
                iRobot::map[i]='r';
                iRobot::alarm = "green";
            }
            
        }
    }
}

void iRobot:: PrintRobot(){
    cout<<model_name<<endl;
    
    for (int i = 0; i < 10; i++) {
        cout << iRobot::map[i] << " ";
    }
    cout<<iRobot::alarm<<endl;

}

