#include<iostream>
#include <cassert>
using namespace std;
//1.insertion at different points
//2.deletion at different points
//3.Searching
/**************************class to be stored********************************/
class stu
{
    int name;
    int age;
    int roll;
    public:
    stu(){}
    stu(int a,int b,int c)
    {
        name=a;
        age=b;
        roll=c;
    }
    friend ostream & operator << (ostream &out, const stu &s); 
    friend istream & operator >> (istream &in,  stu &s);
    friend bool operator ==(stu &s1,stu &s2)
    {
        return (s1.roll==s2.roll);
    }
    static void print(stu s)
    {
        cout << "Enter name- "<<s.name; 
        cout << "Enter age- "<<s.age; 
        cout << "Enter roll- "<<s.roll; 
    }
     
};
ostream & operator << (ostream &out, const stu &s) 
    { 
        out << s.roll;  
        return out; 
    } 
istream & operator >> (istream &in,  stu &s) 
    { 
        cout << "Enter name- "; 
        in >> s.name; 
        cout << "Enter age- "; 
        in >> s.age; 
        cout << "Enter roll- "; 
        in >> s.roll; 
        return in; 
    }
/**********************************************************************/


/**********************************************************************/
template<class dtype>
struct Node
{
    dtype data;
    Node* next;
};

template<class dtype>
class linked_list
{
    public:
    int no_of_elements;
    /********************************************************************************/
    //a function to create an isolated node
    struct Node<dtype>* createNewNode(dtype data)
    {
        struct Node<dtype>* temp=new Node<dtype>(); //(int*)malloc(sizeof(struct node))
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    //a function that returns address of nth node in list (0 for first,-1 for last)
    struct Node<dtype>* getNth(struct Node<dtype> **head,int index)   
    {
        struct Node<dtype>* curr = *head;
        int cnt=0;
            while(curr!=NULL)
            {
                if(cnt == index || (index==-1 && curr->next==NULL) || (index==-2 && curr->next->next==NULL))
                    return curr;
                cnt++;
                curr=curr->next;
            }
            return curr;   
    }
    /********************************************************************************/



    /********************************************************************************/
    //a function that stores a new node at nth position
    void insertN(struct Node<dtype> **head, dtype data,int index)
    {
        struct Node<dtype>* temp = createNewNode(data);
        struct Node<dtype>* curr = getNth(head,(index!=0)?((index!=-1)?index-1:-1):0);
        if((*head)==NULL)
            (*head)=temp;
        else
        {
            if(index==0)
            {
                temp->next = curr;
                (*head)=temp;
            }    
            else
            {
                temp->next = curr->next;
                curr->next=temp;
            }     
        }
    }
    void insertAtBeginning(struct Node<dtype> **head, dtype data)
    { insertN(head,data,0); }
    void insertAtLast(struct Node<dtype> **head, dtype data)
    { insertN(head,data,-1); }
    /********************************************************************************/



    /********************************************************************************/
    //Delete node
    void deleteN(struct Node<dtype> **head,int index)
    {
        if((*head)->next==NULL)
        {
            free(*head);
            (*head)=NULL;
            return;
        }
        struct Node<dtype>* curr = getNth(head,(index!=0)?index-1:0);
        struct Node<dtype>* tofree;
        if(curr!=NULL)
        {
            if(index==0)
            {
                (*head)=curr->next;
                free(curr);
                return;
            }
            tofree = curr->next;
            curr->next = curr->next->next;
            free(tofree);
        }
    }
    void deleteAtBeginning(struct Node<dtype> **head)
    { deleteN(head,0); }
    void deleteAtLast(struct Node<dtype> **head)
    { deleteN(head,-1); }
    /********************************************************************************/



    /********************************************************************************/
    //a function to print linked list
    void printList(struct Node<dtype> *head)
    {
        struct Node<dtype>* temp = head;
        while(temp!=NULL)
        {
            cout<<(temp->data)<<" -> ";
            temp=temp->next;
        }
        if((temp)==NULL)
        { cout<<"Null"; }
        cout<<"\n";
    }
    /********************************************************************************/


    /********************************************************************************/
    //Searching
    struct Node<dtype>* search(struct Node<dtype>** head,dtype item)
    {
        if((*head)==NULL)
            return NULL;
        if((*head)->data==item)
            return (*head);
        return search(&(*head)->next,item);
    };
    


};

int main()
{
    linked_list<stu> ob;
    struct Node<stu>* l1 = NULL;
    //stu a;
    //cin>>a;
    ob.insertN(&l1,stu(1,2,1),0);
    ob.insertN(&l1,stu(1,2,2),-1);
    ob.insertN(&l1,stu(1,2,3),-1);
    ob.insertN(&l1,stu(1,2,4),-1);
    ob.insertN(&l1,stu(1,2,5),-1);
    ob.insertAtBeginning(&l1,stu(1,2,6));
    ob.insertN(&l1,stu(1,2,55),-1);
    ob.insertAtLast(&l1,stu(1,2,36));
    ob.insertN(&l1,stu(1,2,69),1);
    ob.printList(l1);
    ob.deleteN(&l1,4);
    ob.deleteAtBeginning(&l1);
    ob.deleteAtLast(&l1);
    ob.printList(l1);
    stu::print((ob.search(&l1,stu(1,2,4))->data));
    return 0;

}

