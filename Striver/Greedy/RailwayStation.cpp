// Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.
// In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> arrival(n), departure(n);
    cout << "Enter the arrival and departure time of each train:\n";
    for(int i = 0; i < n; i++)
        cin >> arrival[i] >> departure[i];

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 0, maxPlatforms = 0;
    int i = 0, j = 0;

    while(i < n && j < n){
        if(arrival[i] <= departure[j]){
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }

    cout << "The maximum number of platforms required is: " << maxPlatforms << endl;
    return 0;
}


// Time complexity: O(2*(nlog(n)+n))
// Space complexity: O(1)