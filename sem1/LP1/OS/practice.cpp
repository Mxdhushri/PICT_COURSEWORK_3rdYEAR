#include<iostream>
#include<stdlib.h>
using namespace std;

int mutex=1, full=0, x=0, buffersize, *empty;

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return(s++);
}

void Producer()
{
    mutex=wait(mutex);
    full=signal(full);
    *empty=wait((*empty));
    x++;
    cout<<"producer produces the process"<<x<<endl;
    mutex=signal(mutex);
}

void Consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    *empty=signal((*empty));
    cout<<"consumer consumes the process"<<x<<endl;
    mutex=signal(mutex);
    x--;
}

int main()
{
    Producer();
    Consumer();
    wait(x);
    signal(x);

    int ch;
    cout<<"enter the size of the buffer"<<endl;
    cin>>buffersize;
    *empty= new(buffersize);

    while(1){

        cout<<"/n 1.Producer /n 2.Consumer /n 3.Exit"<<endl;
        cout<<"enter your choice"<<endl;
        cin>>ch;

        switch(ch)
        {
        case1:
        if(ch==1)
        {
            Producer();
        }
        else {
            cout<<"buffer is full"<<endl;
            break;
        }

        case2:
        if(ch==2)
        {
            Consumer();
        }
        else {
            cout<<"buffer is empty"<<endl;
            break;
        }

        case3:
        if(ch==3){
        cout<<"the process has ended"<<endl;
        break;
        }

        default:
        Exit(0);

        }
    }
    return 0;
}