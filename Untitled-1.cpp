#include <bits/stdc++.h>
using namespace std;
vector<int> v, p, w;

double fracknap(int c)
{
    vector<pair<double, pair<int, int>>> R;
    for (int i = 0; i < v.size(); i++)
    {
        double r = (double)p[i] / w[i];
        R.push_back({r, {p[i], w[i]}});
    }
    sort(R.begin(),R.end(), greater<pair<double,pair<int, int>>>());
    double profit = 0.0;
    int rem_cap = c;
    for (int i = 0; i < R.size(); i++)
    {
        int price = R[i].second.first;
        int weight = R[i].second.second;
        if(weight <= rem_cap)
        {
            profit += price;
            rem_cap -= weight;
        }
        else
        {
            profit += price * ((double)rem_cap / weight);
            break;
        }
    }
    return profit;
}

int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        p.push_back(price);
    }
    for (int i = 0; i < n; i++)
    {
        int weight;
        cin >> weight;
        w.push_back(weight);
    }
    cout << fixed << setprecision(2) << fracknap(c) << endl;
    return 0;
}
