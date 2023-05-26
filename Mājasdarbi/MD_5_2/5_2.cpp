// Izveidojiet klases Queue šablonu masīva veidā, kas imitē rindas darbu.

// Rinda —datu struktūra, kurā pieeja elementiem ir organizēta pēc principa FIFO (FIFO, First In — First Out).

// Elementa pievienošana (enqueue) iespējama tikai rindas beigās, dzēšana (dequeue) — tikai no rindas sākuma.
// void enqueue(Type Х);
// Type dequeue();
// void PrintQueue();

// Notestējiet visu funkciju darbu ar datu tipiem: int, float, char.

#include <iostream>
#include <string>

using namespace std;

class Human {
private:
    string name;
    int age;

public:
    // pamata klases Konstruktors
    Human() : name(""), age(0) {}

    // parametru konstruktors
    Human(const string& name, int age) : name(name), age(age) {}

    // getName
    string getName() const {
        return name;
    }

    // getAge
    int getAge() const {
        return age;
    }

    // Print
    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

template <typename Type>

class Queue {
private:
    Type* elements;  // masīvs kur uzglabāt rindas elementus
    int front;       // priekšējā elementa index
    int rear;        // pēdējā elementa index
    int capacity;    // rindas kapacitāte
    int size;        // rindas izmērs


public:
// konstruktors rindas izveidei
    Queue(int capacity) {
        elements = new Type[capacity];
        front = 0;
        rear = -1;
        this->capacity = capacity;
        size = 0;
    }

//Destruktors
    ~Queue() {
        delete[] elements;
    }

// funkcija elementu pievienošanai rindai // void enqueue(Type Х);
    void enqueue(Type x) {
        if (size == capacity) {
            cout << "Queue full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;// apgriežam ja pēdējais ir līdz galam
        elements[rear] = x;
        size++;
    }

 // izstāšanās no rindas// Type dequeue();
    Type dequeue() {
        if (size == 0) {
            cout << "Queue empty" << endl;
            return Type();
        }
        Type frontElement = elements[front];
        front = (front + 1) % capacity;// // apgriežam ja priekša ir beigā
        size--;
        return frontElement;
    }

// print// void PrintQueue();
    void PrintQueue() {
        if (size == 0) {
            cout << "Queue empty" << endl;
            return;
        }
        cout << "Queue: ";
        int index = front;
        for (int i = 0; i < size; i++) {
            cout << elements[index].getName() << " ";  
            index = (index + 1) % capacity; // apgriežam ja index sasniedz sākumu
        }
        cout << endl;
    }
};

int main() {

    Queue<Human> humanQueue(3); //Queue<Human> HumanQueue

    Human person1("Eriks", 40);
    Human person2("Katrina", 25);
    Human person3("Juris", 89);

// Notestējiet visu funkciju darbu
// void enqueue(Type Х);

    humanQueue.enqueue(person1);
    humanQueue.enqueue(person2);
    humanQueue.enqueue(person3);
    
// void PrintQueue();
    humanQueue.PrintQueue();

// Type dequeue();
    Human frontHuman = humanQueue.dequeue();
    
    cout << "Dequeued human: ";
    frontHuman.print();

    humanQueue.PrintQueue();

    return 0;
}


