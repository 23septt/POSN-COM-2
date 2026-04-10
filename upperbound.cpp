#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,5,6,6,7};
    
    vector<int>::iterator low = lower_bound(v.begin(),v.end(),4); //ตำแหน่งแรกที่มีค่าไม่น้อยกว่า 4 เป็น pointer
    vector<int>::iterator high = upper_bound(v.begin(),v.end(),5); //ตำแหน่งแรกที่มีค่ามากกว่า 5 เป็น pointer
    int low_dis = distance(v.begin(),low);
    int high_dis = distance(v.begin(),high);

    cout << *low << endl << *high << endl << endl << low_dis << endl << high_dis << endl ;
}