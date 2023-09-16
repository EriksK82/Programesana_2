#include <iostream>

using namespace std;

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

    // Destruktors 
    ~Queue() {
        delete[] elements;
    }

    // funkcija elementu pievienošanai rindai // void enqueue(Type Х);

    void enqueue(Type x) {
        if (size == capacity) {
            
            cout << "Queue full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // apgriežam ja pēdējais ir līdz galam
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
        front = (front + 1) % capacity;  // // apgriežam ja priekša ir beigās
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
            cout << elements[index] << " ";
            index = (index + 1) % capacity;  // apgriežam ja index sasniedz sākumu
        }
        cout << endl;
    }
};


int main() {
    // Notestējiet visu funkciju darbu ar datu tipiem: int
    Queue<int> intQueue(5);// rindas garums
    intQueue.enqueue(10);// pievienojam rindas elementu
    intQueue.enqueue(20);// pievienojam rindas elementu
    intQueue.enqueue(30);// pievienojam rindas elementu
    intQueue.PrintQueue();  //izvadam pirms 10 20 30
    int frontInt = intQueue.dequeue();//izsaucam lai iztātos no rindas
    cout << "dequeue int " << frontInt << endl; // izstājas 10
    intQueue.PrintQueue(); //izvadam pirms 20 30

    // Notestējiet visu funkciju darbu ar datu tipiem: float
    Queue<float> floatQueue(4);
    floatQueue.enqueue(3.1489);
    floatQueue.enqueue(2.745);
    floatQueue.PrintQueue();
    float frontFloat = floatQueue.dequeue();
    cout << "dequeue float: " << frontFloat << endl;
    floatQueue.PrintQueue();

    // Notestējiet visu funkciju darbu ar datu tipiem: char.
    Queue<char> charQueue(6);
    charQueue.enqueue('A');
    charQueue.enqueue('B');
    charQueue.enqueue('C');
    charQueue.enqueue('D');
    charQueue.enqueue('E');
    charQueue.PrintQueue();
    char frontChar = charQueue.dequeue();
    cout << "dequeue char: " << frontChar << endl; 
    charQueue.PrintQueue();

    return 0;
}
