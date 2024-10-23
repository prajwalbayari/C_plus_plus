#include<iostream>
// #include<queue>
using namespace std;

//IMPLEMENTATION OF QUEUE USING ARRAY

// #define n 20
// class queue
// {
//     int* arr;
//     int front;
//     int back;
//     public:
//     queue()
//     {
//         arr=new int[n];
//         front =-1;
//         back=-1;
//     }

//     void push(int x)
//     {
//         if(back==n-1)
//         {
//             cout<<"QUEUE OVERFLOW\n";
//             return;
//         }
//         back++;
//         arr[back]=x;

//         if(front==-1)
//         {
//             front++;
//         }
//     }

//     void pop()
//     {
//         if(front==-1 || front>back)
//         {
//             cout<<"QUEUE UNDERFLOW\n";
//             return;
//         }
//         front++;
//     }

//     int peek()
//     {
//         if(front==-1 || front>back)
//         {
//             cout<<"QUEUE UNDERFLOW\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     bool empty()
//     {
//         if(back==-1 || front>back)
//         {
//             return true;
//         }
//         return false;
//     }
// };

// int main()
// {
//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     if(q.empty())
//     {
//         cout<<"Queue is empty\n";
//     }
//     else
//     {
//         cout<<"Queue is not empty\n";
//     }
// }

//IMPLEMENTATION OF QUEUE USING LINKED LIST

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

//     void push(int x)
//     {
//         node* n=new node(x);
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
//             cout<<"QUEUE UNDERFLOW\n";
//             return;
//         }

//         node* todelete=front;
//         front=front->next;
//         delete todelete;
//     }

//     int peek()
//     {
//         if(front==NULL)
//         {
//             cout<<"QUEUE UNDERFLOW\n";
//             return -1;
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
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     q.pop();
//     cout<<q.peek()<<endl;
//     if(q.empty())
//     {
//         cout<<"Queue is empty\n";
//     }
//     else
//     {
//         cout<<"Queue is not empty\n";
//     }
//     return 0;
// }