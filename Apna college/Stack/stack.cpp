#include<iostream>
// #include<stack>
#include<math.h>
#include<algorithm>

using namespace std;

#define n 100

//IMPLEMENTSATION OF STACK

class stack
{
    int* arr;
    int top;
    public:
    stack()
    {
        arr=new int[n];
        top=-1;
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"STACK OVERFLOW\n";
            return;
        }
        top++;
        arr[top]=x;
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"STACK UNDERFLOW (No elements to delete)\n";
            return;
        }
        top--;
    }

    int Top()
    {
        if(top==-1)
        {
            cout<<"No element in stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top==-1;
    }
};

int main()
{
    stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}

//REVERSE A SENTENCE IN A STACK

// void reverseSentence(string s)
// {
//     stack<string> st;
//     for(int i=0;i<s.length();i++)
//     {
//         string word="";
//         while(s[i]!=' ' && i<s.length())
//         {
//             word+=s[i];
//             i++;
//         }
//         st.push(word);
//     }

//     while(!st.empty())
//     {
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;
// }

// int main()
// {
//     string s="Hey, how are you doing?";
//     reverseSentence(s);
// }

//REVERSING A STACK

// void insertAtBottom(stack<int> &st, int ele)
// {
//     if(st.empty())
//     {
//         st.push(ele);
//         return;
//     }
//     int topele=st.top();
//     st.pop();
//     insertAtBottom(st,ele);

//     st.push(topele);
// }

// void reverse(stack<int> &st)
// {
//     if(st.empty())
//     {
//         return;
//     }

//     int ele=st.top();
//     st.pop();
//     reverse(st);
//     insertAtBottom(st,ele);
// }

// int main()
// {
//     stack<int> st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     reverse(st);
//     while(!st.empty())
//     {
//         cout<<st.top()<<" ";
//         st.pop();
//     }
//     cout<<endl;

//     return 0;
// }


//APPLICTIONS OF STACK

//EVALUATION OF PREFIX EXPRESSIONS

// int prefix(string s)
// {
//     stack<int> st;

//     for(int i=s.length()-1;i>=0;i--)
//     {
//         if(s[i]>='0' && s[i]<='9')
//         {
//             st.push(s[i]-'0');
//         }
//         else
//         {
//             int op1=st.top();
//             st.pop();
//             int op2=st.top();
//             st.pop();
//             switch (s[i])
//             {
//                 case '+': st.push(op1+op2);
//                          break;
//                 case '-': st.push(op1-op2);
//                          break;
//                 case '*': st.push(op2*op1);
//                          break; 
//                 case '/':st.push(op1/op2);
//                          break;
//                 case '%':st.push(op1%op2);
//                          break;
//                 case '^':st.push(pow(op1,op2));
//                          break;                                                   
//             }
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     cout<<prefix("^2/8+31")<<endl; //4
//     return 0;
// }


//POSTFIX EVALUATION

// int postfix(string s)
// {
//     stack<int> st;
//     for(int i=0;i<s.length();i++)
//     {
//         cout<<s[i]<<" ";
//         if(s[i]>='0' && s[i]<='9')
//         {
//             st.push(s[i]-'0');
//         }
//         else
//         {
//             int op2=st.top();
//             st.pop();
//             int op1=st.top();
//             st.pop();

//             switch (s[i])
//             {
//                 case '+': st.push(op2+op1);
//                           break;
//                 case '-': st.push(op2-op1);
//                           break;
//                 case '*': st.push(op1*op2);
//                           break;
//                 case '/': st.push(op1/op2);
//                           break;
//                 case '^': st.push(pow(op1,op2));
//                           break;
//                 case '%': st.push(op1%op2);
//                           break;                                                
//             }
//             cout<<st.top()<<endl;
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     cout<<postfix("87+3*8+6*4+")<<endl; //322
//     return 0;
// }

//INFIX EXPRESSION TO POSTFIX EXPRESSION

// int prec(char c)
// {
//     if(c=='^')
//     {
//         return 3;
//     }
//     else if(c=='*' || c=='/')
//     {
//         return 2;
//     }
//     else if(c=='+' || c=='-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int convertToPostfix(string s)
// {
//     stack<char> st;
//     string res;
//     for(int i=0;i<s.length();i++)
//     {
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
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
//     for(int i=0;i<res.length();i++)
//     {
//         cout<<res[i];
//     }
//     cout<<endl;
// }

// int main()
// {
//     convertToPostfix("(a-b/c)*(a/k-l)");
//     return 0;
// }

//INFIX TO PREFIX

// int prec(char c)
// {
//     if(c=='^')
//     {
//         return 3;
//     }
//     else if(c=='*' || c=='/')
//     {
//         return 2;
//     }
//     else if(c=='+' || c=='-')
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int convertToPrefix(string s)
// {
//     reverse(s.begin(),s.end());
//     stack<char> st;
//     string res;

//     for(int i=0;i<s.length();i++)
//     {
//         if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
//         {
//             res+=s[i];
//         }
//         else if(s[i]==')')
//         {
//             st.push(s[i]);
//         }
//         else if(s[i]=='(')
//         {
//             while(!st.empty() && st.top()!=')')
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
//             while(!st.empty() && prec(st.top())>=prec(s[i]))
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

//     reverse(res.begin(),res.end());
//     for(int i=0;i<res.length();i++)
//     {
//         cout<<res[i];
//     }
//     cout<<endl;
// }

// int main()
// {
//     convertToPrefix("(a-b/c)*(a/k-l)");
//     return 0;
// }

// UNBALANCED PARANTHESIS

// int isValid(string s)
// {
//     int n=s.size();

//     stack<char> st;
//     bool ans=true;

//     for(int i=0;i<n;i++)
//     {
//         if(s[i]=='(' || s[i]=='[' ||s[i]=='{')
//         {
//             st.push(s[i]);
//         }
//         else if(!st.empty() && s[i]==')')
//         {
//             if(st.top()=='(')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans=false;
//                 break;
//             }
//         }
//         else if(!st.empty() && s[i]==']')
//         {
//             if(st.top()=='[')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans=false;
//                 break;
//             }
//         }
//         else if(!st.empty() && s[i]=='}')
//         {
//             if(st.top()=='{')
//             {
//                 st.pop();
//             }
//             else
//             {
//                 ans=false;
//                 break;
//             }
//         }
//     }
//     if(!st.empty())
//     {
//         return false;
//     }
//     return ans;
// }

// int main()
// {
//     string s1="{[()]}";
//     string s2="{[()}";
//     cout<<"First string is ";
//     if(isValid(s1))
//     {
//         cout<<"valid string\n";
//     }
//     else
//     {
//         cout<<"invalid string\n";
//     }

//     cout<<"Second string is ";
//     if(isValid(s2))
//     {
//         cout<<"valid string\n";
//     }
//     else
//     {
//         cout<<"invalid string\n";
//     }
//     return 0;
// }