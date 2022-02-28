#include<iostream>
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

void infixToPostfix(string s)
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
            while(!st1.isEmpty() && prec(c) <= prec(st1.topValue())) {
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
 
    cout << result << endl;
}


int main()
{
string exp = "a+b*(c^d-e)^(f+g*h)-i";
string num2 = "(9+2)*(3+4)";
    infixToPostfix(num2);
    return 0;
}