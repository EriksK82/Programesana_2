// Jārealizē klasi Time (Laiks) kas sastāv no sekundes, minūtes, un stundas.
// Jārealizē sekojošas klases Time metodes:
// konstruktors ar noklusēto laika vērtību
// laika ievade (ar >>)
// laika izvade (ar <<)
// laika piešķiršana citam laikam, ar iespēju laiks1=laiks2=laiks3.
// laika palielināšana par vienu sekundi ar ++ prefiksa (++x) operāciju (ja tas ir sekundes pēdēja vērtība, tad jāpalielina arī minūti, u.t.t.)
// laika palielināšana par vienu minūti ar ++ postfiksa (x++) operāciju (ja tas ir minūtes pēdēja vērtība, tad jāpalielina arī stundu, u.t.t.)
// laika samazināšana par vienu sekundi ar -- prefiksa (--x) operāciju (ja tas ir sekundes pirmā vērtība, tad jāsamazina arī minūti, u.t.t.)
// laika samazināšana par vienu minūti ar -- postfiksa (x--) operāciju (ja tas ir minūtes pirmā vērtība, tad jāsamazina arī stundu, u.t.t.)
// laika salīdzināšana ar >, <, >=, <=, ==, != operatoriem. Jāatgriež bool vērtību.

#include <iostream>

using namespace std;

class Time
{
public:
   Time();
   void setTime(int, int, int);
   void printTime();
   Time &setH(int);
   Time &setM(int);
   Time &setS(int);

private:
   int hour;   // 0-23
   int minute; // 0-59
   int second; // 0-59
};


Time::Time()
{
   hour=minute=second = 0;
}

Time &Time::setH(int a)
{
   hour=a;
   return *this;
}

Time &Time::setM(int a)
{
   minute=a;
  // return *this;
}

Time &Time::setS(int a)
{
   second=a;
   return *this;
}

void Time::setTime (int h, int m, int s)
{
  hour = (h>=0 && h <24) ? h : 0;
  minute = (m>=0 && m<60) ? m : 0;
  second = (s>=0 && s<60) ? s : 0;
}

void Time::printTime()
{
   cout << (hour < 10 ? "0" : "") << hour << ":"
		<< (minute < 10 ? "0" : "") << minute << ":"
		<< (second < 10 ? "0" : "") << second;
}

int main()
{
   
   Time t;
   cout << "Laiks ir: ";
   t.printTime();
   t.setTime(13, 27, 6);
   cout << endl << "Laiks ir: ";
   t.printTime();

   t.setTime(78, 10, 99);

   cout << endl << "Peec nepareiza meeginaajuma: ";
   t.printTime();
   cout << endl << endl;
   t.setH(5).setS(5).setM(5).setH(6);
   t.printTime();
   cout << endl << endl;
   system("Pause");
   return 0;
}


