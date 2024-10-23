#include<iostream>
using namespace std;


//BASICS OF DOUBLY LINKED LIST


class node
{
    public:

    int data;
    node* next;
    node* prev;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }
    head=n;
} 

void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    node* temp=head;

    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=n;
    n->prev=temp;
}

void display(node* &head)
{
    node* temp=head;
    cout<<"Elments in the linked list:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}

void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
}

void deletion(node* &head,int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }
    

    delete temp;
}

int length(node* head)
{
    int l=0;
    node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

node* kappend(node* &head,int k)
{
    node* newHead;
    node* newTail;
    node* tail=head;

    int l=length(head);
    k=k%l;
    cout<<k<<" "<<l<<endl;
    int count=1;
    while(tail->next!=NULL)
    {
        if(count==l-k)
        {
            newTail=tail;
        }
        if(count==l-k+1)
        {
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;

    return newHead;
}

void intersect(node* head1,node* head2,int pos)
{
    node* temp1=head1;
    pos--;
    while(pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}


int intersection(node* &head1,node* & head2)
{
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return -1;
        }
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

node* merge(node* &head1, node* &head2)
{
    node* p1=head1;
    node*p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}

node* mergeRecursive(node* &head1,node* &head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    node* result;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else
    {
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

void evenAfterOdd(node* &head)
{
    node* odd=head;
    node* even=head->next;
    node* evenStart=even;

    while(odd->next!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }

    odd->next=evenStart;
    if(odd->next==NULL)
    {
        even->next=NULL;
    }
}

/*METHOD 1*/

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,6);
    display(head);
    return 0;
}

/*METHOD 2(MANUAL)*/
// int main()
// {
//     node* head=NULL;
//     int i,n,pos,a[100],ele;
//     cout<<"Enter the number of elements:\n";
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
//     display(head);
//     cout<<"Enter the number to be inserted at head:\n";
//     cin>>ele;
//     insertAtHead(head,ele);
//     cout<<"After inserting ";
//     display(head);
//     cout<<"Enter the position of the number to be deleted:\n";
//     cin>>pos;
//     if(pos>n)
//     {
//         cout<<"Invalid position\n";
//         goto label;
//     }
//     deletion(head,pos);
//     cout<<"After deletion ";
//     display(head);
//     label:
//     return 0;
// }

/*APPENDING*/

// int main()
// {
//     node* head=NULL;
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     insertAtTail(head,5);
//     insertAtTail(head,6);
//     display(head);
//     node* newhead=kappend(head,4);
//     display(newhead);
//     return 0;
// }

/*INTERSECTION OF TWO NODES*/

// int main()
// {
//     node* head1=NULL;
//     node* head2=NULL;
//     insertAtTail(head1,1);
//     insertAtTail(head1,2);
//     insertAtTail(head1,3);
//     insertAtTail(head1,4);
//     insertAtTail(head1,5);
//     insertAtTail(head1,6);
//     insertAtTail(head2,9);
//     insertAtTail(head2,10);
//     intersect(head1,head2,3);
//     display(head1);
//     display(head2);
//     cout<<intersection(head1,head2)<<endl;;
// }

/*MERGE SORTING OF TWO NODES*/

// int main()
// {
//     node* head1=NULL;
//     node*head2=NULL;
//     int arr1[]={11,34,55,76,89,100,234,786},i;
//     int arr2[]={-11,-9,8,78,90,768,1000};
//     for(i=0;i<8;i++)
//     {
//         insertAtTail(head1,arr1[i]);
//     }
//     for(i=0;i<7;i++)
//     {
//         insertAtTail(head2,arr2[i]);
//     }
//     display(head1);
//     display(head2);
//     // node*newhead=merge(head1,head2);
//     node* newhead=mergeRecursive(head1,head2);
//     display(newhead);
// }    

// int main()
// {
//     node* head=NULL;
//     int arr[]={1,2,3,4,5,6};
//     for(int i=0;i<6;i++)
//     {
//         insertAtTail(head,arr[i]);
//     }
//     display(head);
//     evenAfterOdd(head);
//     display(head);
// }