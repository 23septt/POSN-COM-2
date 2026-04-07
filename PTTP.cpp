#include <bits/stdc++.h>
using namespace std;

vector<string> a;

bool IsVaild(string b)
{
    int s = 0;
    if (b[b.size() - 1] == 'T')
        return false;
    for (auto i : b)
    {
        if (s == 0 && i == 'P')
            s = 1;
        else if (s == 1 && i == 'P')
            s = 1;
        else if (s == 2 && i == 'P')
            s = 1;
        else if (s == 3 && i == 'P')
            s = 1;
        else if (s == 0 && i == 'T')
            return false;
        else if (s == 1 && i == 'T')
            s = 2;
        else if (s == 2 && i == 'T')
            s = 3;
        else if (s == 3 && i != 'P')
            return false;
    }
    return true;
}

int main()
{
    int n;
    string temp;
    cin >> n;
    vector<string> a(n);
    for (int j = 0; j < n; j++)
    {
        cin >> a[j];
    }
    for (int j = 0; j < n; j++)
    {
        if (IsVaild(a[j]))
        {
            cout << "True" << " " << a[j] << "\n";
        }
        else
            cout << "False" << " " << a[j] << "\n";
    }
}