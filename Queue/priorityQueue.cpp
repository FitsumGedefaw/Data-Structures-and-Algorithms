#include<iostream>
using namespace std;
struct Node{
    int data;
    int key;
    Node* next;
    Node* prev;
};
class PriorutyQueue
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

    void enque(int num1, int num2)
{
    Node* temp = new Node();
    temp->data = num1;
    temp->key = num2; 
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
void deque()
{
    int num;
    cout<<"Enter the priority number: ";
    cin>>num;
    Node* temp = front;
    while(temp->key != num)
    {
       temp = temp->next;
    }
    temp->prev->next = temp->next;
    free(temp); 
}

void print_p_queue()
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
int main()
{
    PriorutyQueue pq;
    pq.enque(10,0)-;
    pq.enque(100,3);
    pq.enque(1000,2);
    pq.enque(10000,1);
    pq.print_p_queue();
    pq.deque();
    pq.print_p_queue();
}
