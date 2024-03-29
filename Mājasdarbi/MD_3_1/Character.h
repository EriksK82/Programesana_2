//
//  Character.h
//  MD_3_1

//
// Izveidot klasi Character - personāžs, kas iekapsulē laukus:
// string name; - vārds;
// int life; - dzīve (1-10);
// char path[10]; - maršruts, saglabā pēdējos 10 iešanas virzienus (virzieni – t-top, b-bottom, l-left, r-right);
// var papildināt ja nepieciešams
// un metodes:
// Character(string, int); - konstruktors, uzdod laukus name un life;
// bool Hit(int); - samazina personāža dzīvi par parametra vērtību, atgriež vai personāžs ir dzīvs;
// int GetLife(); - atgriež personāža dzīves daudzumu;
// void Go(char); - pievieno iešanas virzienu;
// void PrintCharacter(); - izvada vārdu, dzīvs (tad izvada arī dzīves punktu skaitu), vai miris, pēdējos 10 gājienus
// ~Character(); - destruktors, izvada ziņojumu “Game over for name”
// var papildināt ja nepieciešams
// Nosacījumi:
// Personāžu var izveidot tikai dzīvu life > 0
// Ja personāžam beidzās dzīve tas skaitās par mirušo.
// Mirušam personāžam funkcionē tikai funkcija PrintCharacter(), un protams ~Character()
// Funkcijai Go(char) realizēt ievades datu korektuma pārbaudi (tikai tblr).
// Testa personāži:
// Jāizveido 2 personāži
// vienam ievadīt <10 iešanas virzienus, otram >10
// vienam jāpaliek dzīvam, otro jānogalina :)
// Tam kuru nogalinājāt mēģināt vēlreiz izsaukt Hit un Go.
// Beigās abiem izsaukt PrintCharacter


#ifndef Character_h
#define Character_h
#include <iostream>
using namespace std;


class Character
{
public:
    
    Character(string,int);
    bool Hit(int);
    int GetLife();
    void Go(char );
    void PrintCharacter();
    ~Character();
    
protected:   
    int life;
    string name;
    char path[10];
};

#endif /* Character_h */
