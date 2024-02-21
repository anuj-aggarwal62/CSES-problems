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

    int ans = 0;

    function<int(int)> bfs = [&](int node)
    {
        queue<pi> q;

        q.push({node,-1});

        int count = -1;
        int last_node = -1;
        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                int u = q.front().first, par = q.front().second;
                last_node = u;
                q.pop();

                for(auto &v : adj[u])
                {
                    if(v==par) continue;

                    q.push({v,u});
                }
            }
            count++;
        }
        ans = max(ans,count);
        return last_node;
    };

    int dia_end = bfs(0);
    bfs(dia_end);

    cout<<ans<<endl;
    
}