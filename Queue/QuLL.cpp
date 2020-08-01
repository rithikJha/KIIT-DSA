#include<iostream>
using namespace std;
class QNode
{
    public:
    int data;
    QNode* next;
    QNode(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class Queue
{
    public:
    QNode *front, *rear;
    Queue()
    {
        front=rear=NULL;
    }
    void enqueue(int data)
    {
        QNode* temp=new QNode(data);
        if(rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    int dequeue()
    {
        QNode* temp=front;
        int item=temp->data;
        if(front==NULL)
        {
            rear==NULL;
            return -32323;
        }
        front=front->next;
        free(temp);
        return item;
    }
};

void print(Queue* q)
{
    QNode* temp = q->front;
    while(temp!=NULL)
    {
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    print(&q);
    q.dequeue();
    q.dequeue();
    //q.dequeue();
    //q.dequeue();
    q.dequeue();
    q.dequeue();
    print(&q);
    return 0;
}
