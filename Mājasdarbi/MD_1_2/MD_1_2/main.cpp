//
//  main.cpp
//  MD_1_2
//
//  Created by Eriks Karklins on 16/02/2023.
//

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class ProximitySensor
{
public:
    
    ProximitySensor(int,string);//piešķir sērijas numuru un izslēgto (off) statusu
    void Get/Set state;
    //bool Scan(“area”) – atgriež vai priekšā ir šķērslis, “area” ir pāra(ir)/nepāra(nav) cipars
    //PrintSensor – izvada informāciju par sensoru
    ~ProximitySensor();
    
    
private:
    string state(on/off);
    int serial_number;


};



int main() {


}
