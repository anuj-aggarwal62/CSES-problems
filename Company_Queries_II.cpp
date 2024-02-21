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

    int n,q;
    cin>>n>>q;

    vi par(n,0);
    par[0] = -1;
    
    vvi adj(n);

    for(int i=1;i<n;i++)
    {
        cin>>par[i];
        par[i]--;

        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }

    // binary lifting
    int mx = 32;
    vvi dp(n,vi(mx,-1));

    for(int i=0;i<mx;i++)
    {
        for(int node=0;node<n;node++)
        {
            if(i==0)
            {
                dp[node][i] = par[node];
                continue;
            }
            
            if(dp[node][i-1]!=-1) dp[node][i] = dp[dp[node][i-1]][i-1];
        }
    }

    function<int(int,int)> helper = [&](int node,int k)
    {
        int ans = node;

        for(int i=mx-1;i>=0;i--)
        {
            if(ans==-1) break;

            int bit = k & (1<<i);
            
            if(bit)
            {
                ans = dp[ans][i];
            }
        }

        return ans;
    };

    // depth
    vi depth(n);
    depth[0] = 0;
    function<void(int,int,int)> calDepth = [&](int node,int dep,int parent)
    {
        depth[node] = dep;

        for(auto &child : adj[node])
        {
            if(child==parent) continue;
            calDepth(child,dep+1,node);
        }
    };
    calDepth(0,0,-1);

    function<int(int,int)> LCA = [&](int a,int b)
    {
    
        int ans;
        int h1 = depth[a] , h2 = depth[b];

        a = helper(a,h1 - min(h1,h2));
        b = helper(b,h2 - min(h1,h2));

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

    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a-- ; b-- ;

        int ans = LCA(a,b);
        if(ans>=0) ans++;

        cout<<ans<<endl;
    }
}