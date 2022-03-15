#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    
};
class Stack
{
  public:
  Node* top = NULL;
bool isEmpty()
{
    if(top == NULL)
    return true;
    else return false;
}

void push(int num)
{
   Node* temp = new Node();
   temp->data = num;
   temp->next = top;
   top = temp; 
}
void pop()
{
  if(isEmpty())
  {
    std ::cout<<"the stack is empty\n";
    return;
  }
  else
   {
     Node* temp = top;
  top = top->next;
  delete temp;
   }
}
int topValue()
{
    if(isEmpty())
    {
       cout<<"The stack is empty\n:";
        return -1;
    }
    else
  return top->data;
}
void printStack()
{
    if(isEmpty())
    {
     std :: cout<<"The stak is empty\n";
      return;
    }
    else
    {
      Node* temp = top;
      while ( temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    }
    cout<<endl;
}

};
int main()
{
int dec_num;
Stack stack1;
cout<<"Enter the decimal number: ";
cin>> dec_num;
while(dec_num > 0){
        int remainder = dec_num%2;
        stack1.push(remainder);
        dec_num = dec_num/2;
   }
  
cout<< "The binary equivalent of the number you entered is: ";
stack1.printStack();

    return 0;
}