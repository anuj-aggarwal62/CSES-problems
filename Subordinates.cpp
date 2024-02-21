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

    vvi adj(n);

    for(int i=0;i<n-1;i++)
    {
        int v;
        cin>>v;

        int u = i+1;
        v--;

        adj[v].push_back(u);
    }

    vi dp(n,0);
    function<void(int)> dfs = [&](int node)
    {
        for(auto &i : adj[node])
        {
            dfs(i);
            dp[node] += dp[i]+1;
        }
    };

    dfs(0);
    for(auto &i : dp) cout<<i<<" ";
    cout<<endl;
    
}