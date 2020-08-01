#include<iostream>
using namespace std;
class Stack
{
    public:
    int data;
    Stack* next;
};
bool isEmpty(Stack* head)
{ return head==NULL; }
Stack* newNode(int data)
{
    Stack* temp=new Stack();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void push(Stack** head,int data)
{
    Stack* temp = newNode(data);
    temp->next=(*head);
    (*head)=temp;
}
int pop(Stack** head)
{
    if(isEmpty(*head))
    {
        cout<<"\nStack Underflow\n";
        return -65;
    }
    Stack* temp=(*head);
    (*head)=(*head)->next;
    int item = temp->data;
    free(temp);
    return item;
}
void print(Stack *head)
{
    cout<<"Stack-";
    while((head)!=NULL)
    {
        cout<<"->"<<head->data;
        head=head->next;
    }
    cout<<"\n";
        
}
int main()
{
    Stack* s = NULL;
    push(&s,1);print(s);
    push(&s,2);print(s);
    push(&s,3);print(s);
    push(&s,4);print(s);
    push(&s,5);print(s);
    push(&s,6);print(s);
    push(&s,7);print(s);
    push(&s,8);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);
    pop(&s);print(s);

}