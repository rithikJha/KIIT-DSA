//push pop top isempty
//LIFO -O(1) - push and pop only from one end
//fnc calls/recursion, undo in editor, parentheses check
#define Max 101
#include<iostream>
using namespace std;
class Stack
{
    int top;
    public:
    int A[Max];
    Stack()
    { top=-1; }
    bool isFull();
    bool isEmpty();
    void push(int data);
    int pop();
    int peek();
    void print()
    {
        cout<<" Stack -";
        if(isEmpty())
        {
            cout<<"Null\n";
            return;
        }

        for(int i=0;i<=top;i++)
            cout<<" -> "<<A[i];
            cout<<"\n";
    }
};
bool Stack::isFull()
{
    return top==Max-1;
}
bool Stack::isEmpty()
{
    return top==-1;
}
void Stack::push(int data)
{
    if(isFull())
    {
        cout<<"\nStack Overflow\n";
        return;
    }
    A[++top]=data;
}
int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"\nStack Underflow\n";
        return -655;
    }
    return A[top--];
}
int Stack::peek()
{
    return A[top];
}


int main()
{
    Stack s;
    s.print();
    s.push(1);s.print();
    s.push(2);s.print();
    s.push(3);s.print();
    s.push(4);s.print();
    s.push(5);s.print();
    s.push(6);s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    s.pop();s.print();
    return 0;
}
