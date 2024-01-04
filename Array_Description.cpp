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

    int n,m;
    cin>>n>>m;

    vi vec(n);
    input(vec);

    vi dp(m+1,0);

    if(vec[0]==0)
    {
        for(int i=1;i<=m;i++) dp[i]++;
    }
    else dp[vec[0]]++;

    vi dx = {-1,0,1};

    for(int i=1;i<n;i++)
    {
        vi ndp(m+1,0);

        if(vec[i]==0)
        {
            
            for(int j=1;j<=m;j++)
            {
                for(auto &y : dx)
                {
                    int curr = j + y;

                    if(curr>=1 && curr<=m)
                    {
                        ndp[j] += dp[curr];
                        ndp[j] %= mod;
                    }
                }

            }
        }
        else
        {
            for(auto &y : dx)
            {
                int curr = vec[i] + y;

                if(curr>=1 && curr<=m)
                {
                    ndp[vec[i]] += dp[curr];
                    ndp[vec[i]] %= mod;
                }
            }
        }

        dp = ndp;
    }

    int sum = 0;
    for(auto &i : dp) {sum += i;sum %= mod;}

    cout<<sum<<endl;
}