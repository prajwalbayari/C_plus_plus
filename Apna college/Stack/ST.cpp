#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

// class stack
// {
//     int top;
//     char* arr;
//     public:
//     stack()
//     {
//         arr=new char[100];
//         top=-1;
//     }
//     void push(char ch)
//     {
//         if(top==99)
//         {
//             cout<<"Stack overflow\n";
//             return;
//         }
//         arr[++top]=ch;
//     }
//     void pop()
//     {
//         if(top==-1)
//         {
//             cout<<"Stack underflow\n";
//             return;
//         }
//         top--;
//     }
//     void Top()
//     {
//         if(top==-1)
//         {
//             cout<<"Stack underflow\n";
//             return;
//         }
//         cout<<arr[top];
//     }
//     int empty()
//     {
//         return top==-1;
//     }
// };

// int main()
// {
//     stack s;
//     string str;
//     cout<<"Enter the sentence\n";
//     getline(cin,str);
//     cout<<"The sentence is:\n";
//     cout<<str<<endl;
//     for(int i=0;i<str.size();i++)
//     {
//         s.push(str[i]);
//     }
//     cout<<"Reversed sentence is:\n";
//     while(!s.empty())
//     {
//         s.Top();
//         s.pop();
//     }
// }

// void reverseSentence(string str)
// {
//     stack<string> st;
//     string words="";
//     for(int i=0;i<str.size();i++)
//     {
//         if(str[i]==' ')
//         {
//             st.push(words);
//             words="";
//         }
//         else
//         {
//             words+=str[i];
//         }
//     }
//     st.push(words);
//     while(!st.empty())
//     {
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }

// int main()
// {
//     string str;
//     cout<<"Enter the string to be inserted\n";
//     getline(cin,str);
//     cout<<"String after reversing is:\n";
//     reverseSentence(str);
// }

// void insertAtBottom(stack<int>& st,int m)
// {
//     if(st.empty())
//     {
//         st.push(m);
//         return;
//     }
//     int top=st.top();
//     st.pop();
//     insertAtBottom(st,m);
//     st.push(top);
// }

// void reverseStack(stack<int>& st)
// {
//     if(st.empty())
//     {
//         return;
//     }
//     int m=st.top();
//     st.pop();
//     reverseStack(st);
//     insertAtBottom(st,m);
//     return;
// }
// int main()
// {
//     stack<int> st;
//     int n,m;
//     cout<<"Enter the number of elements\n";
//     cin>>n;
//     cout<<"Enter the elements of the stack\n";
//     for(int i=0;i<n;i++)
//     {
//         cin>>m;
//         st.push(m);
//     }
//     reverseStack(st);
//     cout<<"Stack after reversing is:\n";
//     for(int i=0;i<n;i++)
//     {
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }

// int prefix(string str)
// {
//     stack<int> st;
//     for(int i=str.size()-1;i>=0;i--)
//     {
//         if(str[i]>='0' && str[i]<='9')
//         {
//             st.push(str[i]-'0');
//         }
//         else
//         {
//             int op1=st.top();
//             st.pop();
//             int op2=st.top();
//             st.pop();
//             if(str[i]=='+')
//             {
//                 op1=op1+op2;
//             }
//             else if(str[i]=='-')
//             {
//                 op1=op1-op2;
//             }
//             else if(str[i]=='*')
//             {
//                 op1=op1*op2;
//             }
//             else if(str[i]=='/')
//             {
//                 op1=op1/op2;
//             }
//             // else if(str[i]=='^')
//             // {
//             //     op1=pow(op1,op2);
//             // }
//             st.push(op1);
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     string s;
//     cout<<"Enter the prefix expression\n";
//     getline(cin,s);
//     cout<<"The result of the prefix expression is:\n";
//     cout<<prefix(s)<<endl;
// }

// int postfix(string str)
// {
//     stack<int> st;
//     for(int i=0;i<str.size();i++)
//     {
//         if(str[i]>='0' && str[i]<='9')
//         {
//             st.push(str[i]-'0');
//         }
//         else
//         {
//             int op2=st.top();
//             st.pop();
//             int op1=st.top();
//             st.pop();
//             if(str[i]=='+')
//             {
//                 op1=op1+op2;
//             }
//             else if(str[i]=='-')
//             {
//                 op1=op1-op2;
//             }
//             else if(str[i]=='*')
//             {
//                 op1=op1*op2;
//             }
//             else if(str[i]=='/')
//             {
//                 op1=op1/op2;
//             }
//             // else if(str[i]=='^')
//             // {
//             //     op1=pow(op1,op2);
//             // }
//             st.push(op1);
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     string str;
//     cout<<"Enter the postfix expression\n";
//     getline(cin,str);
//     cout<<"The result of given postfix expression is: "<<postfix(str)<<endl;
// }

// int prec(char c)
// {
//     if(c=='^')
//         return 3;
//     else if(c=='*'||c=='/')
//         return 2;
//     else if(c=='+'||c=='-')
//         return 1;
//     else 
//         return -1;
// }

// string infixToPostfix(string s)
// {
//     stack<char> st;
//     string res;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]>='a'&&s[i]<='z')
//         {
//             res+=s[i];
//         }
//         else if(s[i]=='(')
//         {
//             st.push(s[i]);
//         }
//         else if(s[i]==')')
//         {
//             while(!st.empty() && st.top()!='(')
//             {
//                 res+=st.top();
//                 st.pop();
//             }
//             if(!st.empty())
//             {
//                 st.pop();
//             }
//         }
//         else
//         {
//             while(!st.empty() && prec(st.top())>prec(s[i]))
//             {
//                 res+=st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while(!st.empty())
//     {
//         res+=st.top();
//         st.pop();
//     }
//     return res;
// }

// int main()
// {
//     string s;
//     cout<<"Enter the infix expression\n";
//     getline(cin,s);
//     cout<<"The postfix expression is:\n";
//     s=infixToPostfix(s);
//     cout<<s<<endl;
// }

// string rev(string s)
// {
//     reverse(s.begin(),s.end());
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='(')
//             s[i]=')';
//         else if(s[i]==')')
//             s[i]='(';
//     }
//     return s;
// }

// int prec(char c)
// {
//     if(c=='^')
//         return 3;
//     else if(c=='*'||c=='/')
//         return 2;
//     else if(c=='+'||c=='-')
//         return 1;
//     else 
//         return -1;
// }

// string infixToPrefix(string s)
// {
//     s=rev(s);
//     string res;
//     stack<char> st;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A'&&s[i]<='Z')
//         {
//             res+=s[i];
//         }
//         else if(s[i]=='(')
//         {
//             st.push(s[i]);
//         }
//         else if(s[i]==')')
//         {
//             while(!st.empty() && st.top()!='(')
//             {
//                 res+=st.top();
//                 st.pop();
//             }
//             if(!st.empty())
//             {
//                 st.pop();
//             }
//         }
//         else
//         {
//             while(!st.empty() && prec(st.top())>prec(s[i]))
//             {
//                 res+=st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }
//     while(!st.empty())
//     {
//         res+=st.top();
//         st.pop();
//     }
//     return res;
// }

// int main()
// {
//     string s;
//     cout<<"Enter the infix expression\n";
//     getline(cin,s);
//     cout<<"The prefix expression is:\n"<<infixToPrefix(s)<<endl;
// }