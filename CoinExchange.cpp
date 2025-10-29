#include <bits/stdc++.h>
using namespace std;
vector<int> coins;
int CoinExchange(int n, int t)
{
    vector<vector<int> > table(n + 1, vector<int>(t + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        table[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            table[i][j] = table[i - 1][j];
            if (coins[i - 1] <= j)
                table[i][j] += table[i][j - coins[i - 1]];
        }
    }
    return table[n][t];
}
int main()
{
    int n, t;
    cout << "Number of coins: ";
    cin >> n;
    cout << "Total Amount: ";
    cin >> t;
    cout << "Enter Your Coins: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int ans = CoinExchange(n, t);
    cout << ans << endl;
    return 0;
}