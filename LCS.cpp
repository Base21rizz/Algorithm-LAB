#include<bits/stdc++.h>
using namespace std;
void LCS(string a, string b)
{
    int n=a.length();
    int m=b.length();

    vector<vector<int> >lcs(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(a[i-1] == b[j-1])
            {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    string lcs_str = "";
    int i = n, j = m;
    while (i>0 && j>0)
    {
        if(a[i-1] == b[j-1]){
            lcs_str = a[i-1] + lcs_str;
            i--;
            j--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1]) i--;
        else j--;
    }
    cout << "LCS length: " << lcs[n][m] << endl;
    for (int i = 0; i < lcs_str.length(); i++)
    {
        cout << lcs_str[i] << ' ';
    }
    cout << endl;
}
int main()
{
    string a,b;
    cout << "Give your Strings: " << endl;
    cin >> a >> b;
    LCS(a,b);
    return 0;
}