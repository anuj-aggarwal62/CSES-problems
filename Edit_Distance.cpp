#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define pii pair<int,pair<int,int>>
#define all(x) x.begin(), x.end()
#define rSort(x) sort(all(x),greater<int>())
#define display(v) for(auto i:v)cout<<i<<" ";
#define vi vector<int>
#define vl vector<long long>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vvb vector<vector<bool>>
#define sti set<int>
#define stl set<long long>
#define mpii map<int,int>
#define mpll map<long long,long long>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define loop(i, N) for (int i = 0; i < N; i++)
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define rev(i,n,x) for(int i=n;i>=x;i--)
#define mod 1000000007
void input(vi &v) {for(int i=0;i<(int)v.size();i++) cin>>v[i];}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s1,s2;
    cin>>s1>>s2;

    int n = s1.size(),m = s2.size();

    vvi dp(n+1,vi(m+1,1e9));

    for(int i=0;i<n;i++)
    {
        dp[i][m] = n-i;
    }
    for(int j=0;j<m;j++)
    {
        dp[n][j] = m-j;
    }
    dp[n][m] = 0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            int &ans = dp[i][j];

            if(s1[i]==s2[j])
            {
                ans = dp[i+1][j+1];
            }
            else
            {
                ans = min(ans,1+dp[i+1][j+1]);
                ans = min(ans,1+dp[i+1][j]);
                ans = min(ans,1+dp[i][j+1]);
            }
        }
    }

    cout<<dp[0][0]<<endl;
}