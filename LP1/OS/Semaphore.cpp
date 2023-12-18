// implementation of a simple producer-consumer problem using a buffer with a fixed size. 
// The producer-consumer problem involves two processes, a producer, and a consumer,
// which share a common,buffer as a communication medium.

#include<iostream>
#include<stdlib.h>
using namespace std;

int mutex = 1, full = 0, x = 0, bufferSize, *empty;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    (*empty) = wait((*empty));
    x++;
    cout << endl << "Producer produces the item: " << x;
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    (*empty) = signal((*empty));
    cout << endl << "Consumer consumes the item: " << x;
    mutex = signal(mutex);
    x--;
}

int main()
{
    int ch;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

    cout << "Enter the size of the buffer: ";
    cin >> bufferSize;
    empty = new int(bufferSize);

    cout << "\n 1) Producer \n 2) Consumer \n 3) Exit" << endl;
    while (1)
    {
        cout << endl << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if ((mutex == 1) && ((*empty) != 0))
            {
                producer();
            }
            else {
                cout << endl << "Buffer is Full";
            }
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else {
                cout << endl << "Buffer is Empty";
            }
            break;

        case 3:
            delete empty; // Deallocate memory before exiting
            exit(0);
            break;

        default:
            cout << endl << "Wrong choice";
            break;
        }
    }

    return 0;
}