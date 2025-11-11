#include <bits/stdc++.h>
using namespace std;
vector<int> v, p, weights, chosen;
int ksZeroOne(int n, int c)
{
    vector<vector<int> > dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= c; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + p[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int w = c;
    for (int i = n; i > 0; i--)
    {
        if(dp[i][w] != dp[i-1][w])
        {
            chosen.push_back(i);
            w -= weights[i-1];
        }
    }
    return dp[n][c];
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
        weights.push_back(weight);
    }
    int maxprofit = ksZeroOne(n, c);
    cout << maxprofit << endl << "Choosen: ";
    for(int i = chosen.size() - 1; i>=0; i--) cout << chosen[i] << ' ';
    cout << endl;
    return 0;
}
