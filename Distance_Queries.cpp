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

    int n,q;
    cin>>n>>q;

    vvi adj(n);
    vi par(n,-1);
    
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // depth & parent array
    vi depth(n,0);
    depth[0] = 0;
    function<void(int,int,int)> calDepth = [&](int node,int parent,int dep)
    {
        depth[node] = dep;
        par[node] = parent;
        for(auto &child : adj[node])
        {
            if(child==parent) continue;

            calDepth(child,node,dep+1);
        }
    };
    calDepth(0,-1,0);

    // binary lifting
    int mx = 21;
    vvi dp(n,vi(mx,-1));
    for(int i=0;i<mx;i++)
    {
        for(int node = 0;node<n;node++)
        {
            if(i==0)
            {
                dp[node][i] = par[node];
            }
            else if(dp[node][i-1]!=-1)  dp[node][i] = dp[dp[node][i-1]][i-1];
        }
    }

    //Kth ancestor
    function<int(int,int)> Kth = [&](int node,int k)
    {
        for(int i=mx-1;i>=0;i--)
        {
            if(node==-1) break;

            if(k & (1<<i)) node = dp[node][i];
        }
        return node;
    };

    // LCA
    function<int(int,int)> LCA = [&](int a,int b)
    {
        int h1 = depth[a] , h2 = depth[b];
        if(h1<h2)  b = Kth(b,h2-h1);
        else a = Kth(a,h1-h2);

        if(a==b) return a;

        for(int i=mx-1;i>=0;i--)
        {
            if(dp[a][i]!=dp[b][i]) 
            {
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        return dp[a][0];
    };

    //Distance
    function<int(int,int)> dist = [&](int a,int b)
    {
        int h1 = depth[a] , h2 = depth[b];
        int lca = LCA(a,b);
        int h = depth[lca];
        return (h1 + h2 - 2*h);
    };

    // queries
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--; b--;
        cout<<dist(a,b)<<endl;
    }
}