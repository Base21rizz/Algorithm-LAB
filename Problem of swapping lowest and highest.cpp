#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    int min = v[0];
    int max = v[0];
    int minpos=0, maxpos=0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
            minpos = i;
        }
        if (v[i] > max)
        {
            max = v[i];
            maxpos = i;
        }
    }
    swap(v[minpos], v[maxpos]);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}