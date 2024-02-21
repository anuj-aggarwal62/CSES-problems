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
        int u,v;
        cin>>u>>v;

        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vvi dp(n,vi(2,-1));

    function<int(int , int, bool)> dfs = [&] (int node,int parent,bool can_take)
    {
        if(dp[node][can_take]!=-1) return dp[node][can_take];
        int ans = 0;
        int total = 0;
        for(auto &i : adj[node])
        {
            if(i==parent) continue;
            total += dfs(i,node,true);
        }

        ans = total;
        if(can_take)
        {
            for(auto &i : adj[node])
            {
                if(i==parent) continue;

                ans = max(ans,total - dp[i][true] + dfs(i,node,false) + 1);
            }
        }

        return dp[node][can_take] = ans;
    };

    cout<<dfs(0,-1,true)<<endl ;

    
}