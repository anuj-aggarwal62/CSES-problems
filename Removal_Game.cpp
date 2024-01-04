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

    int n;
    cin>>n;

    vi vec(n);
    input(vec);

    vvi dp(n,vi (n));

    bool odd = n&1;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            int &ans = dp[i][j];
            if(i==j)
            {
                if(odd) ans = vec[i];
                else ans = 0;
                
                continue;
            }

            bool ok = (j-i+1)&1;
            if(!(ok^odd))
            {
                ans = max(dp[i+1][j]+vec[i],dp[i][j-1]+vec[j]);
            }
            else
            {
                ans = min(dp[i+1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}