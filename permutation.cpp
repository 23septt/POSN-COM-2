#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    int count = 0;
    do
    {
        bool b = false;
        bool c = false;
        for (int i = 0; i < v.size()-1; i++)
        {
            if ((v[i] == 'a' && v[i + 1] == 'e') || (v[i] == 'e' && v[i + 1] == 'a'))
            {
                b = true;
            }
            if ((v[i] == 'b' && v[i + 1] == 'd') || (v[i] == 'd' && v[i + 1] == 'b'))
            {
                c = true;
            }
        }
        if (c && !b)
        {
            count++;
            cout << count << " ";
            for (auto a : v)
                cout << a << " ";
            cout << "\n";
        }
    } while (next_permutation(v.begin(), v.end()));
}
