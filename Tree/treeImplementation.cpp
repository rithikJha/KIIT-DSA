//tree is not a linear data structure
//what needs to be store; cost of operation; memory consumption;
// tree is used for hierarchial data
//root at top ;
//root->No parent
//recursive datastructure - subtree concept
//depth(x) = root to x ; depth(root) = 0;
//height(x) = x-> leaf (longest) ; height(tree)=height(root)
//file system; quicks search, trie; network routing arrangement
#include<iostream>
using namespace std;
class tree
{
    public:
    int data;
    class tree* left;
    class tree* right;
    tree** direct(tree* p,tree *c)
    {
    if(p->data > c->data)
        return &(p->left);
    else
        return &(p->right);
    }   

};

//max child
tree* max(tree* root)
{
    if(!root)
        return NULL;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}
//min child
tree* min(tree* root)
{
    if(!root)
        return NULL;
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
tree* parent(tree* p,tree* c)
{   return p;   }
tree* current(tree* p,tree* c)
{   return c; }


int child(tree* current)
{
    if(current==NULL)
        return -1;
    else if(current->left!=NULL && current->right!=NULL)
        return 2;
    else if(current->left==NULL && current->right==NULL)
        return 0;
    else return 1;
}
tree* childD(tree* current)
{
    if(child(current)==1)
    {
        if(current->left != NULL)
            return current->left;
        else
            return current->right;  
    }
    else
        return NULL;
    
}


tree* search(tree* rootu,int key,tree* (*demand)(tree* , tree* ))
{
    if(rootu==NULL) return NULL;
    if(rootu->data == key)   return rootu;
    //cout<<"\nsearch root curr - "<<rootu<<"  for value - "<<rootu->data<<"\n";
    tree* p;
    tree* root = rootu;
    //cout<<"\nsearch curr b4 - "<<root<<"  for value - "<<(root)->data<<"\n";
    while((root)!=NULL && (root)->data != key)
    {
        p=root;
        if((root)->data > key)
            root= (root)->left;
        else
            (root)=(root)->right;
    }
    //cout<<"\nsearch curr - "<<root<<"  for value - "<<(root)->data<<"\n";
    if(root != NULL )
        return (demand(p,root));
    return NULL;
}


tree* createNode(int data)
{
    tree* t=new tree();
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    return t;
}


void insert(tree* &root,int data)
{
    tree* node = createNode(data);
    tree* p,*c;
    if((root)==NULL)  
    {
        (root)=node;
        cout<<"\ninserted "<<data<<" at "<<root;
        return;
    }
    p=NULL;
    c=(root);
    while(c!=NULL)
    {
        p=c;
        if(c->data > data)
            c=c->left;
        else
            c=c->right;
    }
    if(p->data > data)
    {
        p->left = node;
        cout<<"\ninserted "<<data<<" at "<<p->left;
    }
        
    else
    {
        p->right = node;
        cout<<"\ninserted "<<data<<" at "<<p->right;
    }
        
}

/****************************************************/
void inorder(tree* root)
{
    if(root==NULL)  return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void preorder(tree* root)
{
    if(root==NULL)  return;
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}void postorder(tree* root)
{
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
/******************************************************/

/******************************************************/
void deleteNode(tree* root,int key)
{

    tree* p = search(root,key,parent);
    tree* c = search(root,key,current);
    //cout<<"\ndelete curr - "<<c<<"  for value - "<<c->data<<"\n";
    if(c!=NULL)
    {
        if(child(c)==0)
        {
            if(p->data > c->data)
                p->left = NULL;
            else
                p->right = NULL;
            c=NULL;
            free(c);
        }
           
        if(child(c)==1)
        {
            tree** carr = p->direct(p,c) ;
            (*carr) = childD(c);
            c=NULL;
            free(c);
        }
        
        if(child(c)==2)
        {
            tree* m = max(c->left);
            deleteNode(root,m->data);
            c->data=m->data; 
        }
        


    }
}



/******************************************************/


int main()
{
    tree* t = NULL;
    insert(t,5);
    insert(t,3);
    insert(t,7);
    insert(t,4);
    insert(t,2);
    insert(t,6);
    insert(t,8);
    inorder(t);
    //cout<<"\nmain curr - "<<t<<"  for value - "<<t->data<<"\n";
    tree* s = search(t,4,current);
    //cout<<"\nmain child - "<<s<<"  for value - "<<s->data<<"\n";
    //cout<<"\n"<<max(t)->data;
    //cout<<"\n"<<search(t,4,parent)->data;
    //cout<<"\n"<<search(t,4,current)->data;
    deleteNode(t,5);
    insert(t,9);
    insert(t,10);
    cout<<"\n";
    inorder(t);
    tree* s1 = search(t,3,current);
    //cout<<"\nmain child - "<<s1<<"  for value - "<<s1->data<<"\n";
    deleteNode(t,4);
    deleteNode(t,9);
    cout<<"\n";
    inorder(t);
}

    
