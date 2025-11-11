#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void merge(int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> leftarr(n1);
    vector<int> rightarr(n2);
    for (int i = 0; i < n1; i++) leftarr[i] = v[l+i];
    for (int j = 0; j < n2; j++) rightarr[j] = v[m+1+j];
    int i=0;
    int j=0;
    int k=l;
    while (i < n1 && j<n2)
    {
        if(leftarr[i] <= rightarr[j])
        {
            v[k] = leftarr[i];
            i++;
        }
        else{
            v[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        v[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        v[k] = rightarr[j];
        j++;
        k++;
    }
}
void mergesort(int l,int r)
{
    if(l >= r) return;
    int m = l + (r-l) / 2;
    mergesort(l,m);
    mergesort(m+1,r);
    merge(l,m,r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << "Unsorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    mergesort(0,n-1);
    cout << endl << "Sorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
}