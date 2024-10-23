#include<iostream>
using namespace std;

//REVERSING A STRING USING RECURSION

// void reverse(string s)
// {
//     if(s.length()==0)
//     {
//         return;
//     }
//     string ros = s.substr(1);
//     reverse(ros);
//     cout<<s[0];
// }
// int main()
// {
//     reverse("Prajwal");
// }

// REPLACE PI WITH 3.14

// void replacePi(string s)
// {
//     if(s.length()==0)
//     {
//         return;
//     }
//     if(s[0]=='p' && s[1]=='i')
//     {
//         cout<<"3.14";
//         replacePi(s.substr(2));
//     }   
//     else
//     {
//         cout<<s[0];
//         replacePi(s.substr(1));
//     }
// } 

// int main()
// {
//     replacePi("pippppiiiipi");
//     return 0;
// }

//TOWER OF HANOI

// void toh(int n,char src,char dest,char helper)
// {
//     if(n==0)
//     {
//         return;
//     }
//     toh(n-1,src,helper,dest);
//     cout<<"Move from "<<src<<" to "<<dest<<endl;
//     toh(n-1,helper,dest,src);
// }

// int main()
// {
//     toh(5,'A','C','B');
//     return 0;
// }

//REMOVE ALL THE DUPLICATES FROM THE STRING

// string remove(string s)
// {
//     if(s.length()==0)
//     {
//         return "";
//     }

//     char ch=s[0];
//     string ans = remove(s.substr(1));

//     if(ch==ans[0])
//     {
//         return ans;
//     }
//     return ch+ans;
// }

// int main()
// {
//     cout<<remove("aaaabcddee")<<endl;
//     return 0;
// }

//MOVE ALL THE "X" TO THE END OF THE STRING

// string movex(string s)
// {
//     if(s.length()==0)
//     {
//         return "";
//     }

//     char ch=s[0];
//     string ans=movex(s.substr(1));

//     if(ch=='x')
//     {
//         return ans+ch;
//     }
//     return ch+ans;
// }  

// int main()
// {
//     cout<<movex("axxbdxcefxhix");
//     return 0;
// }

//Generate all substrings of a string

// void subseq(string s,string ans)
// {

//     if(s.length()==0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     string ros=s.substr(1);
    
//     subseq(ros,ans);
//     subseq(ros,ans+ch);
// }

// int main()
// {
//     subseq("ABC"," ");
//     return 0;
// }

//GENERATE SUBSTRINGS WITH ASCII NUMBER

// void subseq(string s,string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     int code=ch;
//     string ros=s.substr(1);

//     subseq(ros,ans);
//     subseq(ros,ans+ch);
//     subseq(ros,ans + to_string(code));
// }

// int main()
// {
//     subseq("AB","");
//     return 0;
// }

//Print all possible words from  phone digits

// string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
// void keypad(string s,string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     char ch=s[0];
//     string code = keypadArr[ch-'0'];
//     string ros= s.substr(1);

//     for(int i=0;i<code.length();i++)
//     {
//         keypad(ros,ans+code[i]);
//     }
// }

// int main()
// {
//     keypad("23","");
//     return 0;
// }


//PRINT ALL THE POSSIBLE PERMUTATIONS OF A STRING

// void permutation(string s,string ans)
// {
//     if(s.length()==0)
//     {
//         cout<<ans<<endl;
//         return;
//     }
//     for(int i=0;i<s.length();i++)
//     {
//         char ch=s[i];
//         string ros=s.substr(0,i)+s.substr(i+1);
//         permutation(ros,ch+ans);
//     }
// }

// int main()
// {
//     permutation("ABC","");
//     return 0;
// }


//COUNT THE NUMBER OF PATHS POSSIBLE FROM START POINT TO END POINT IN GAMEBOARD

// int countPath(int s,int e)
// {
//     if(s==e)
//     {
//         return 1;
//     }
//     if(s>e)
//     {
//         return 0;
//     }
//     int count=0;
//     for(int i=0;i<=6;i++)
//     {
//         count+=countPath(s+i,e);
//     }
//     return count;
// }

// int main()
// {
//     cout<<countPath(0,3)<<endl;
//     return 0;
// }

//Maze count

// int countPathMaze(int n,int i,int j)
// {
//     if(i==n-1 && j==n-1)
//     {
//         return 1;
//     }
//     if(i>=n || j>=n)
//     {
//         return 0;
//     }
//     return countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
// }

// int main()
// {
//     cout<<countPathMaze(4,0,0)<<endl;
//     return 0;
// }

//KEEPING 2*1 TILES IN A SEQUENCE

// int tilingWays(int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     if(n==1)
//     {
//         return 1;
//     }
//     return tilingWays(n-1) + tilingWays(n-2);
// }
// int main()
// {
//     cout<<tilingWays(4)<<endl;
//     return 0;
// }

//FRIENDS PAIRING PROBLEMS

// int friends(int n)
// {
//     if(n==0 ||n==1 || n==2)
//     {
//         return n;
//     }

//     return friends(n-1) +friends(n-2)*(n-1);
// }

// int main()
// {
//     cout<<friends(3)<<endl;
//     return 0;
// }

//0-1 KNAPSACK PROBLEM

// int knapsack(int value[], int wt[],int n,int W)
// {
//     if(n==0||W==0)
//     {
//         return 0;
//     }

//     if(wt[n-1]>W)
//     {
//         return knapsack(value,wt,n-1,W);
//     }
//     return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1],knapsack(value,wt,n-1,W));
// }

// int main()
// {
//     int wt[]={10,20,30};
//     int value[]={100,50,150};
//     int W=50;

//     cout<<knapsack(value,wt,3,W)<<endl;;
//     return 0;
// }


// int fib(int n)
// {
//     int temp=0;
//     if(n==1)
//     {
//         cout<<"0"<<" ";
//         return 0;
//     }
//     if(n==2)
//     {
//         cout<<"1"<<" ";
//         return 1;
//     }
//     temp=fib(n-2)+fib(n-1);
//     cout<<temp<<" ";
//     return temp;
// }


// void pi(string& s)
// {
//     if(s.length()==0)
//     {
//         return;
//     }
//     if(s[0]=='p' && s[1]=='i')
//     {
//         string str=s.substr(2);
//         pi(str);
//         s.replace(0,1,"3.14");
//         s.erase(4,s.length());
//         s.append(str);
//     }
//     else
//     {
//         string str=s.substr(1);
//         pi(str);
//         s.erase(1,s.length());
//         s.append(str);
//     }
// }

// int main()
// {
//     string s="pippxxppiixipi";
//     pi(s);
//     cout<<s<<endl;
// }