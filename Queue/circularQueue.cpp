#include<iostream>
using namespace std;
class Queue
{
private:
int arr[30];
int front;
int back;
int queueSize;
const int MAX_SIZE = 5;
public:
 Queue(){
     queueSize = 0;
     front = -1;
     back = -1;
    for(int i = 0; i < MAX_SIZE-1; i++)
    {
        arr[i] = 0; 
    }
}

bool isEmpty(){
    if(queueSize == 0)
        return true;
    else
        return false;
}

bool isFull(){
    if(queueSize == MAX_SIZE)
        return true;
    else
        return false;
}

void enque(int num){
    if(isFull())
    {
        cout<< "Queue overflow!" <<endl;
    }
    else{
    back++;
  if(back == MAX_SIZE)
        back = 0;
    arr[back] = num;
    queueSize++;
    
    } 
    if(front == -1)
    front = 0;
    
}

void deque(){
    if(isEmpty())
    {
        cout<< "Queue underflow!";
    }
    else{
       front++;
       if(front == MAX_SIZE)
            front = 0;
       queueSize--;

    }
    
}

void printQueue(){
    int temp = front;
    for(int i = temp; i<=back; i++)
    {
    cout<<arr[temp] <<" ";
    temp++;
    }
    cout<<endl;
}
int frontValue()
{
    return arr[front];
}
int rearValue()
{
    return arr[back];
}

};

int main()
{
    Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

     q.printQueue();
     int x1 = q.rearValue();
    cout<<x1 <<endl;

     q.enque(6);

     q.deque();
     q.deque();

    q.printQueue();

     q.enque(6);
      q.enque(7);

     int x3 = q.rearValue();
    cout<<x3 <<endl;

     q.enque(8);
    
    
    
return 0;
}