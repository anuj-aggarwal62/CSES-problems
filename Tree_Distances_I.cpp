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
        u-- ; v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vi in(n,0),out(n,0);

    function<void(int,int)> dfs1 = [&](int node,int parent)
    {
        
        for(auto &child : adj[node])
        {
            if(child==parent) continue;
            dfs1(child,node);
            in[node] = max(in[node],in[child]+1);
        }
    };

    function<void(int,int)> dfs2 = [&](int node,int parent)
    {
        int mx1 = -2,mx2 = -2;

        for(auto &child : adj[node])
        {
            if(child==parent) continue;
            if(mx1<in[child])
            {
                mx2 = mx1;
                mx1 = in[child];

            }
            else if(mx2<in[child])
            {
                mx2 = in[child];
            }
        }

        for(auto &child : adj[node])
        {
            if(child==parent)continue;
            int sib_mx = mx1;
            if(in[child]==mx1) sib_mx = mx2;

            out[child] = max(1+out[node],2+sib_mx);

            dfs2(child,node);
        }
    };

    dfs1(0,-1);
    dfs2(0,-1);

    for(int i=0;i<n;i++)
    {
        cout<<max(in[i],out[i])<<" ";
    }

    cout<<endl;
    
}