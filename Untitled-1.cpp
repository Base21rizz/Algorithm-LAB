#include <bits/stdc++.h>
using namespace std;

double fracknap(vector<int> &v, vector<int> &p, vector<int> &w, int c)
{
    vector<pair<double, pair<int, int>>> R;

    for (int i = 0; i < v.size(); i++)
    {
        double ratio = (double)p[i] / w[i];
        R.push_back({ratio, {p[i], w[i]}});
    }

    sort(R.rbegin(), R.rend());

    double totalP = 0.0;
    int rem_cap = c;

    for (int i = 0; i < R.size(); i++)
    {
        int price = R[i].second.first;
        int weight = R[i].second.second;

        if (weight <= rem_cap)
        {
            totalP += price;
            rem_cap -= weight;
        }
        else
        {
            totalP += price * ((double)rem_cap / weight);
            break;
        }
    }
    return totalP;
}

int main()
{
    vector<int> v, p, w;
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

    cout << fixed << setprecision(2) << fracknap(v, p, w, c) << endl;

    return 0;
}
