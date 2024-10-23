#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int ,vector<int>> pq;       //Push = O(logn) = Pop
    pq.push(3);                                //Size = O(1) = Top
    pq.push(56);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    priority_queue<int ,vector<int>,greater<int>> pqm;
    pqm.push(-100);
    pqm.push(90);
    pqm.push(123);
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;
}