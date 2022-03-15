#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char data;
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

void push(char d)
{
   Node* temp = new Node();
   temp->data = d;
   temp->next = top;
   top = temp; 
}
void pop()
{
  if(isEmpty())
  {
    std ::cout<<"the stack is empty\n:";
    return;
  }
  else
   {
     Node* temp = top;
  top = top->next;
  delete temp;
   }
}
char topValue()
{
    if(isEmpty())
    {
       cout<<"The stack is empty\n:";
        return '0';
    }
    else
  return top->data;
}
void printStack()
{
    if(isEmpty())
    {
      cout<<"The stak is empty\n";
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
  string input1;
Stack stack1;
cout<<"Enter the word or phrase: ";
cin>>input1;
 transform(input1.begin(), input1.end(), input1.begin(), ::tolower);
 //now input1 is in small letters.
 int length = input1.length();
 for(int i = 0; i < length; i++){
     stack1.push(input1[i]);
 }
// now the stack is filled.
string s1;
while(!stack1.isEmpty()){
    s1 = s1 + stack1.topValue();
    stack1.pop();
}
if (input1 == s1){
cout<<"The word you entered is a palindrome!";
}
else
{
    cout<<"The word you entered is not a palindrome!";
}
return 0;
}
