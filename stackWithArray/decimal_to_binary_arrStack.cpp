#include<iostream>
using namespace std;
class Stack
{
private:
int arr[30];
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

void push(int num){
    if(isFull())
    {
        cout<< "Stack overflow!";
    }
    else{
    top++;
    arr[top] = num;
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

void printStack(){
    int temp = top;
    for(int i = temp; i>=0; i--)
    {
    cout<<arr[temp] <<" ";
    temp--;
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
stack1.printStack();


    return 0;
}