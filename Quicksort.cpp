#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int Part_ition(int start,int end)
{
    int pivot = v[end];
    int i = start-1;
    for (int j = start; j <= end-1; j++)
    {
        if(v[j] < pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    i++;
    swap(v[i],v[end]);
    return i;
}
void quicksort(int start,int end)
{
    if(end <= start) return;
    int pivot = Part_ition(start,end);
    quicksort(start,pivot-1);
    quicksort(pivot+1,end);
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
    quicksort(0,n-1);
    cout << endl << "Sorted Array: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
}
