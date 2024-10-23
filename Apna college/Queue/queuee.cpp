#include<iostream>
#include<queue>
// #include<stack>

using namespace std;


//IMPLEMENTATION USING ARRAYS


// class queue
// {
//     int* arr;
//     int front;
//     int back;

//     public:
//     queue()
//     {
//         arr=new int[100];
//         front=-1;
//         back=-1;
//     }
//     void push(int x)
//     {
//         if(back>=99)
//         {
//             cout<<"Queue is full\n";
//             return;
//         }
//         if(front==-1)
//         {
//             front++;
//         }
//         arr[++back]=x;
//     }
//     void pop()
//     {
//         if(front==-1 || front>back)
//         {
//             cout<<"Queue is empty\n";
//             return;
//         }
//         front++;
//     }
//     int peek()
//     {
//         if(front==-1 || front>back)
//         {
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }
//     bool empty()
//     {
//         if(front==-1 || front>back)
//         {
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     queue q;
//     int n,m;
//     cout<<"Enter the number of elements in the queue\n";
//     cin>>n;
//     cout<<"Enter the elements\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         q.push(m);
//     }
//     cout<<"The elements are:\n";
//     while(!q.empty())
//     {
//         cout<<q.peek()<<" ";
//         q.pop();
//     }
//     cout<<endl;
//     cout<<q.empty()<<endl;
//     return 0;
// }

//IMPLEMENTATION USING LINKED LIST

// class node
// {
//     public:
//     int data;
//     node* next;
//     node(int val)
//     {
//         data=val;
//         next=NULL;
//     }
// };

// class queue
// {
//     node* front;
//     node* back;
//     public:
//     queue()
//     {
//         front=NULL;
//         back=NULL;
//     }
//     void push(int val)
//     {
//         node* n=new node(val);
//         if(front==NULL)
//         {
//             back=n;
//             front=n;
//             return;
//         }
//         back->next=n;
//         back=n;
//     }
//     void pop()
//     {
//         if(front==NULL)
//         {
//             cout<<"Queue underflow\n";
//             return;
//         }
//         node* t=front;
//         front=front->next;
//         delete t;
//     }
//     int peek()
//     {
//         if(front==NULL)
//         {
//             cout<<"Queue underflow\n";
//             return NULL;
//         }
//         return front->data;
//     }
//     bool empty()
//     {
//         if(front==NULL)
//         {
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     queue q;
//     int n,m;
//     cout<<"Enter the number of elements\n";
//     cin>>n;
//     cout<<"Enter the queue elements\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         q.push(m);
//     }
//     cout<<"Queue elements are:\n";
//     for(int i=0;i<n;i++)
//     {
//         cout<<q.peek()<<" ";
//         q.pop();
//     }
//     cout<<endl;
// }

//IMPLEMENTATION OF QUEUE USING STACK

// class queue
// {
//     stack<int> s1;
//     stack<int> s2;
//     public:
//     void push(int x)
//     {
//         s1.push(x);
//     }
//     int pop()
//     {
//         if(s1.empty() && s2.empty())
//         {
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         if(s2.empty())
//         {
//             while(!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int top=s2.top();
//         s2.pop();
//         return top;
//     }
//     //POP USING RECURSION
//     int popr()
//     {
//         if(s1.empty())
//         {
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         int x=s1.top();
//         s1.pop();
//         if(s1.empty())
//         {
//             return x;
//         }
//         int item=popr();
//         s1.push(x);
//         return item;
//     }
//     bool empty()
//     {
//         if(s1.empty() && s2.empty())  
//             return true;
//         return false;
//     }
// };

// int main()
// {
//     queue q;
//     q.push(10);
//     q.push(20);
//     q.push(30);
//     q.push(40);
//     q.push(50);
//     cout<<q.pop()<<" "<<endl;
//     q.push(60);
//     cout<<q.pop()<<" "<<endl;
//     cout<<q.pop()<<" "<<endl;
//     cout<<q.pop()<<" "<<endl;
//     cout<<q.pop()<<" "<<endl;
//     cout<<q.pop()<<" "<<endl;
//     cout<<q.pop()<<" "<<endl;
//     return 0;
// }

//IMPLEMENTATION OF STACK USING QUEUE

//METHOD 1

// class stack
// {
//     int N;
//     queue<int> q1;
//     queue<int> q2;
//     public:
//     stack()
//     {
//         N=0;
//     }
//     void push(int x)
//     {
//         N++;
//         q2.push(x);
//         while(!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue<int> t=q1;
//         q1=q2;
//         q2=t;
//     }
//     void pop()
//     {
//         N--;
//         q1.pop();
//     }
//     int top()
//     {
//         if(q1.empty())
//         {
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         return q1.front();
//     }
//     int size()
//     {
//         return N;
//     }
// };

// int main()
// {
//     stack st;
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     st.push(40);
//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.top()<<endl;
//     cout<<st.size()<<endl;
// }

class stack
{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack()
    {
        N=0;
    }
    void push(int x)
    {
        N++;
        q1.push(x);
    }
    void popc()   
    {
        if(q1.empty())
        {
            return;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> t=q1;
        q1=q2;
        q2=t;
    }
    int top()
    {
        if(q1.empty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int m=q1.front();
        q2.push(q1.front());
        queue<int> t=q1;
        q1=q2;
        q2=t;
        return m;
    }
    int size()
    {
        return N;
    }
};

int main()
{
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.top()<<endl;
    st.popc();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
}