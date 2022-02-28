#include<iostream>
#include<math.h>
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

char topValue()
{
    return arr[top];
}

void printStack(){
    int temp = top;
    for(int i = temp; i>=0; i--)
    {
    cout<<arr[temp];
    temp--;
    }
    cout<<endl;
}
};

int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
Stack st1;
string result;
for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result = result + c;

// If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st1.push('(');

            // If the scanned character is an ‘)’,
        // pop everything on the stack and store it to the result string
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st1.topValue() != '(')
            {
                result = result + st1.topValue();
                st1.pop();
            }
            st1.pop();
        }

        //If an operator is scanned
        else {
            while(!st1.isEmpty() && prec(s[i]) <= prec(st1.topValue())) {
                result = result + st1.topValue();
                st1.pop(); 
            }
            st1.push(c);
        }
    } // for loop ends here, all elements of the infix string are accessed
    
    // Pop all the remaining elements from the stack
    while(!st1.isEmpty()) {
        result = result + st1.topValue();
        st1.pop();
    }
 
    return result;
}

int val(char c)
{
return (c - '0');
}

bool isOperand(char c)
{
    if(c >= '0' && c <= '9')
    return true;
    else
        return false;
}
 
 
     

int main()
{
    string expr;
   cout<<"Enter the expression: ";
   cin>> expr;
   string str = infixToPostfix(expr);
   cout << str <<endl;

   Stack stack1;

   for(int i = 0; i < str.length(); i++)
   {
       char c = str[i];
       if(isOperand(c))
            {
                stack1.push(val(c));
                stack1.printStack();
            
            }
        else
            {
                 if(c == '+')
           {
               int num1 = stack1.topValue();
                    stack1.pop();
                    int num2 = stack1.topValue();
                    stack1.pop();
                    int temp = num2+num1;
                    stack1.push(temp);
                    stack1.printStack();
           }
           else if(c == '-')
           {
               int num1 = stack1.topValue();
                    stack1.pop();
                    int num2 = stack1.topValue();
                    stack1.pop();
                    int temp = num2-num1;
                    stack1.push(temp);
                    stack1.printStack();
           }
           else if(c == '*')
           {
               int num1 = stack1.topValue();
                    stack1.pop();
                    int num2 = stack1.topValue();
                    stack1.pop();
                    int temp = num2*num1;
                    stack1.push(temp);
                    stack1.printStack();
           }
           else if(c == '/')
           {
               int num1 = stack1.topValue();
                    stack1.pop();
                    int num2 = stack1.topValue();
                    stack1.pop();
                    int temp = num2/num1;
                    stack1.push(temp);
                    stack1.printStack();
           }
            else if(c == '^')
           {
               int num1 = stack1.topValue();
                    stack1.pop();
                    int num2 = stack1.topValue();
                    stack1.pop();
                    int temp =pow(num2,num1);
                    stack1.push(temp);
                    stack1.printStack();
           }
                 
            }

   }
int result = stack1.topValue();

cout<< "Answer: " << result;



    return 0;
    }