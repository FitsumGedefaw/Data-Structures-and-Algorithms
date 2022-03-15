#include<iostream>
using namespace std;
class Queue
{
private:
int arr[30];
int front;
int back;
int queueSize;
const int MAX_SIZE = 30;
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
        cout<< "Queue overflow!";
    }
    else{
    back++;
  //  if((back == MAX_SIZE) && ((back+1)%MAX_SIZE !=0))
   //     {
    //        back = 0;
     //   }
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
    int x = q.frontValue();
    cout<<x <<endl;
    q.deque();
    q.printQueue();
     x = q.frontValue();
    cout<<x <<endl;  
    
return 0;
}