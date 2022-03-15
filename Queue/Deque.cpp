#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};

class Deque
{
  public:
   Node* front = NULL;
   Node* rear = NULL;
  bool isEmpty()
    {
        if(front == NULL && rear == NULL)
        return true;
        else 
        return false;
    }

void enqueFront(int num)
{
    Node* temp = new Node();
   temp->data = num;
   temp->next = front;
   temp->prev = NULL;
   if(isEmpty())
     {
         front = temp;
         rear = temp;
         return;
     }
     else
        front = temp;
   
}
void dequeFront()
{
    Node* temp = front;
    if(isEmpty())
       {cout<<"Deque underflow!";
        return;
       }
    if(front==rear){
    front= NULL;
    rear = NULL;
    }
    else
        {
    front = front->next;
    front->prev = NULL;
    
        }
        free(temp);
}
void enqueRear(int num)
{
    Node* temp = new Node();
    temp->data = num;
    temp->next = NULL;
    if(isEmpty()){
        front = temp;
        rear=temp;
        return;
    }
    else
    {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
	
}
void dequeRear()
{
    Node* temp = rear;
    if(isEmpty())
        {
            cout<<"Deque underflow!";
            return;
        }
        if(front == rear)
        {
            front= NULL;
            rear = NULL;
        }

    else
   {
     rear = rear->prev;
     rear->next = NULL;
   }
    free(temp); 
}
void printDeque()
{
    if(isEmpty())
    {
      std :: cout<<"The Deque is empty\n";
      return;
    }
    else
    {
      struct Node* temp = front;
	while(temp != NULL) {
		std::cout<<temp->data<<" ";
		temp = temp->next;
	}
    }
    cout<<endl;
}

};

int main(int argc, char const *argv[])
{
    
   Deque deck;
   deck.enqueFront(1);
   deck.enqueFront(2);
   deck.enqueFront(3);
   deck.printDeque();

   deck.enqueRear(0);
   deck.enqueRear(-1);
   deck.printDeque();

   deck.dequeFront();
   deck.printDeque();

   deck.dequeRear();
   deck.dequeRear();
   deck.printDeque();

}