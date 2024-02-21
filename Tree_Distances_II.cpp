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

    vector<pi> in(n,{0,0}),out(n,{0,0});

    function<void(int,int)> dfs1 = [&](int node,int parent)
    {
        for(auto &child : adj[node])
        {
            if(child==parent) continue;

            dfs1(child,node);

            in[node].first += in[child].first + in[child].second + 1;
            in[node].second += in[child].second + 1;
        }
    };

    function<void(int,int)> dfs2 = [&](int node,int parent)
    {
        int sum = 0,count = 0;
        int num  = 0;
        for(auto &child : adj[node])
        {
            if(child==parent) continue;

            sum += in[child].first;
            count += in[child].second;
            num++;
        }
        num--;

        for(auto &child : adj[node])
        {
            if(child==parent)continue;
            out[child].first = (out[node].first + out[node].second + 1) + (sum - in[child].first + (count-in[child].second + num)*2);
            out[child].second = out[node].second + 1 + (count - in[child].second) + num;
            dfs2(child,node);
        }
    };

    dfs1(0,-1);
    dfs2(0,-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<in[i].first + out[i].first<<" ";
    }
    cout<<endl;
}