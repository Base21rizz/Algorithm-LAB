#include <bits/stdc++.h>
using namespace std;

int ZeroOneKnapsack(int c, vector<int> &p, vector<int> &weights, int n, vector<int> &chosen)
{
    vector<vector<int> > dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= c; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + p[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int w = c;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            chosen.push_back(i);
            w -= weights[i - 1];
        }
    }
    return dp[n][c];
}

int main()
{
    int n, c;
    vector<int> v, p, weights;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        p.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {

        int num;
        cin >> num;
        weights.push_back(num);
    }
    vector<int> chosen;
    int MaxProfit = ZeroOneKnapsack(c, p, weights, n, chosen);
    for (int i = chosen.size() - 1; i >= 0; i--)
    {
        cout << chosen[i] << ' ';
    }
    cout << endl;
    cout << MaxProfit << endl;
    return 0;
}