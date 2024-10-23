//Median of running stream

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int ,vector<int>> pqmax;
priority_queue<int ,vector<int>,greater<int>> pqmin;

void insert(int x)
{
    if(pqmin.size()==pqmax.size())
    {
        if(pqmax.size()==0)
        {
            pqmax.push(x);
            return;
        }
        if(x<pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        if(pqmax.size()>pqmin.size())
        {
            if(x>pqmax.top())
            {
                pqmin.push(x);
            }
            else
            {
                pqmin.push(pqmax.top());
                pqmax.pop();
                pqmax.push(x);
            }
        }
        else
        {
            if(x<=pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                pqmax.push(pqmin.top());
                pqmin.pop();
                pqmax.push(x);
            }
        }
    }
}

double median()
{
    if(pqmin.size()==pqmax.size())
        return (pqmin.top()+pqmax.top())/2.0;
    else if(pqmin.size()>pqmax.size())
        return pqmin.top();
    else
        return pqmax.top();
}

int main()
{
    insert(10);
    cout<<median()<<endl;
    insert(15);
    cout<<median()<<endl;
    insert(21);
    cout<<median()<<endl;
    insert(30);
    cout<<median()<<endl;
    insert(18);
    cout<<median()<<endl;
    insert(19);
    cout<<median()<<endl;
    return 0;
}