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

    int n,x;
    cin>>n>>x;
    vi vec(n);
    input(vec);

    int sz = 1<<n;

    vector<pi> dp(sz);

    dp[0] = {1,0};

    for(int s=1;s<sz;s++)
    {
        pi &ans = dp[s];
        ans = {n+1,0};
        for(int i=0;i<n;i++)
        {
            if(!(s&(1<<i))) continue;

            int ns = s & (~(1<<i));

            pi curr;

            if(dp[ns].second + vec[i] <= x)
            {
                curr = {dp[ns].first,dp[ns].second + vec[i]};
            }
            else 
            {
                curr = {dp[ns].first + 1,vec[i]};
            }

            ans = min(ans,curr);

        }
    }

    cout<<dp[sz-1].first<<endl;

}
