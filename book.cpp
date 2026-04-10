#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, i, d, count = 0,high=0;
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        high = max(high,v[i]);
    }
    cin >> d;
    int mid , low=1;
    while(low<high)
    {
        count = 0;
        mid = (low+high)/2;
        int temp;
        i=0;
        for(i=0;i<n;i++){
                count+=v[i]/mid;
                if(v[i]%mid!=0) count++;
        }
        if(count > d) low = mid+1;
        else high = mid;
    }
    cout << low << "\n";

}