#include<iostream>
using namespace std;

//BASICS OF LINKED LIST



class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void display(node* head)
{
    node* temp=head;
    cout<<"Linked list has elements:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(node* &head ,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val)
{
    node* n =new node(val);
    node* temp= head;

    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cout<<"Element found at position:\n";
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int val)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete= temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

node* reverse(node* &head)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

// O(N)
node* reverseRecursive(node* &head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* newhead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* reversek (node* &head,int k)
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next =reversek(nextptr,k);
    }
    return prevptr;
}


//FLOYD'S ALGORITHM


void makeCycle(node* head,int pos)
{
    node*temp=head;
    node*startNode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count=pos)
        {
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
bool detectCycle(node* &head)
{
    node* slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node* &head)
{
    node* slow=head;
    node* fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

int main()
{
    node *head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    display(head);
    insertAtHead(head,8);
    display(head);
    cout<<search(head,5)<<endl;
    deletion(head,7);
    insertAtTail(head,10);
    cout<<"After deletion ";
    display(head); 
    return 0;
}
//{
//     int i,n,a[10],ele;
//     cout<<"Enter number of elements:\n";
//     cin>>n;
//     cout<<"Enter elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         insertAtTail(head,a[i]);
//     }
//     display(head);
//     cout<<"Enter the number to be inserted at head:\n";
//     cin>>ele;
//     insertAtHead(head,ele);
//     cout<<"After insertion ";
//     display(head);
//     cout<<"Enter the number to be deleted:\n";
//     cin>>ele;
//     deletion(head,ele);
//     cout<<"After deletion ";
//     display(head);
// }

// REVERSING A LINKED LIST


// int main()
// {
//     node* head=NULL;
//     int i,n,a[10];
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the data elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         insertAtTail(head,a[i]);
//     }
//     display(head);
//     cout<<"After reversing ";
//     node* newhead=reverseRecursive(head);
//     display(newhead);
// }


//REVERSING A LINKED LIST WITH K NODES
// int main()
// {
//     node* head=NULL;
//     int i,n,a[10],k;
//     cout<<"Enter the number of elements:\n";
//     cin>>n;
//     cout<<"Enter the data elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         insertAtTail(head,a[i]);
//     }
//     display(head);
//     cout<<"Enter the number of nodes:\n";
//     cin>>k;
//     node* newhead=reversek(head,k);
//     cout<<"After reversing ";
//     display(newhead);
// }

// FLOYD'S ALGORITHM || HARE AND TORTISE ALGORITHM DETECTION AND REMOVAL

// int main()
// {
//     node*head=NULL;
//     int n,i,a[10];
//     cout<<"Enter the number of elements\n";
//     cin>>n;
//     cout<<"Enter the elements:\n";
//     for(i=0;i<n;i++)
//     {
//         cin>>a[i];
//     }
//     for(i=0;i<n;i++)
//     {
//         insertAtTail(head,a[i]);
//     }
//     makeCycle(head,n-2);
//     cout<<detectCycle(head)<<endl;
//     removeCycle(head);
//     cout<<detectCycle(head)<<endl;
//     display(head);
// }