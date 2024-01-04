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

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin>>a>>b;

    vvi dp(a+1,vi(b+1,1e9));

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            int &ans = dp[i][j];

            if(i==j) 
            {
                ans = 0;
                continue;
            }

            for(int x=1;x<i;x++)
            {
                ans = min(ans,1 + dp[x][j] + dp[i-x][j]);
            }
            for(int x=1;x<j;x++)
            {
                ans = min(ans,1 + dp[i][x] + dp[i][j-x]);
            }
        }
    }

    cout<<(dp[a][b])<<endl;
}