#include<iostream>
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
     std :: cout<<"The stak is empty\n";
      return;
    }
    else
    {
      Node* temp = top;
      while ( temp != NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
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
