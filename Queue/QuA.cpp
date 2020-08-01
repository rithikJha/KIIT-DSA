//enqueue dequeue peek/front isEmpty front+rear
//FIFO - O(1)
// printer processor 
//circular array -curr= i ; next= (i+1)%n ; prev=(i+n-1)%n
#include<iostream>
using namespace std;
class Queue
{
    public:
    int front , rear, size,capacity;
    int* Array;
    Queue()
    {
        front=rear=-1;
    }
};

Queue* createMe(int capacity);
bool isEmpty(Queue* q);
bool isFull(Queue* q);
void enqueue(int data);
int dequeue();
int frontx(Queue* q);

Queue* createMe(int capacity)
{
    Queue* Q = new Queue();
    Q->front=0;Q->rear=-1;Q->size=0;
    Q->capacity=capacity;
    Q->Array = new int[(Q->capacity)*sizeof(int)];
    return Q;
}

bool isEmpty(Queue* q)
{ return (q->size==0); }

bool isFull(Queue* q)
{ return (q->size==q->capacity); }

void enqueue(Queue* q,int data)
{
    if(isFull(q))
    {
        cout<<"Error: Overflow;";
        return;
    }
    q->rear=(q->rear + 1)%(q->capacity);
    q->Array[q->rear]=data;
    q->size=q->size+1;
    cout<<" enqueue:"<<data<<"  \n";
}

void dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        cout<<"Error: Underflow";
        return;
    }
    int item=q->Array[q->front];
    q->front=(q->front + 1)%(q->capacity);
    cout<<" dequeue:"<<item<<"  \n";
    q->size=q->size-1;
    //return item;
}

int frontx(Queue* q)
{
    if(q->size==0)
        return -54434;
    return q->Array[q->front];
}

void print(Queue* q)
{
    int c=0;
    cout<<"Queue-";
    for(int i=q->front;c<(q->size);i=(i+1)%(q->capacity))
    {
        cout<<"->";
        cout<<q->Array[i];
        c++;
    }
    cout<<"\n";
}

int main()
{
    Queue* q = createMe(10);
    enqueue(q,11);
    enqueue(q,21);
    enqueue(q,31);
    enqueue(q,41);
    enqueue(q,51);
    enqueue(q,61);
    enqueue(q,71);
    enqueue(q,81);
    enqueue(q,91);
    enqueue(q,101);
    //enqueue(q,11);
    //enqueue(q,9);
    cout<<"\n    front:"<<q->front<<"   size:"<<q->size<<"    \n";
    //print(q);
    dequeue(q);//print(q);
    cout<<"\n    front:"<<q->front<<"   size:"<<q->size<<"    \n";
    dequeue(q);//print(q);
    dequeue(q);//print(q);
    dequeue(q);//print(q);
    dequeue(q);//print(q);
    dequeue(q);//print(q);
    dequeue(q);print(q);
    dequeue(q);print(q);
    dequeue(q);print(q);
    dequeue(q);print(q);
    dequeue(q);print(q);

}
