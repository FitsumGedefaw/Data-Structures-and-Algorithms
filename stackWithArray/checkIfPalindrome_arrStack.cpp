#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
private:
char arr[30];
int top;
public:
 Stack(){
     top = -1;
    for(int i = 0; i < 30; i++){
    arr[i] = 0;} 
}

bool isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if(top == 29)
        return true;
    else
        return false;
}

void push(char L){
    if(isFull())
    {
        cout<< "Stack overflow!";
    }
    else{
    top++;
    arr[top] = L;
    }
}

void pop(){
    if(isEmpty())
    {
        cout<< "Stack underflow!";
    }
    else{
        arr[top] = 0;
        top--;
    }
}

char topValue()
{
    return arr[top];
}

void printStack(){
    for(int i = top; i>=0; i--)
    {
    cout<<arr[top];
    top--;
    }
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
