#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node* next;

  Node() {
    data = 0;
    next = NULL;
  }
  Node( int d) {
    data = d;
  }
};

class Stack {
  public:
    Node* head;
    int top;

  Stack() {
    head = NULL;
    top = 0;
  }
  Stack(Node* n) {
    head = n;
  }
  bool isEmpty()
  {
      if(top == 0)
      return true;
      else
      return false;
  }
 bool isFull()
 {
     if(top == 30)
     return true;
     else
     return false;
 }
 void push() {
     if(isFull())
     cout<<"Stack Overflow.";
     else
     {
       int num;
       cout<<"Enter the number: ";
       cin>>num; 
       Node* n;
       n->data = num;  
       n-> next = head;
       head = n;
       top++;
       cout<< "Number pushed to the stack successfully." << endl;
     }
 }
     void pop()
     {
         if(isEmpty())
         cout<<"Stack Underflow.";
         else
         {
             head = head->next;
             top--;

         }
     }
     void printStack()
     {
         if(isEmpty())
         cout<<"Stack is empty.";
         else
         {
             Node * temp = head;

      while (temp != NULL)
            {
            cout<< temp->data;
             temp = temp -> next;
            }
         }
     }
     int topValue()
     {
         return head->data;
     }
};

int main()
{
Stack stack1;
stack1.push();



return 0;
}
    
  