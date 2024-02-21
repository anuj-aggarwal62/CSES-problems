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


    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;

        int sz = 1<<n;
        vvi dp(m,vi(sz,0));

        for(int mask=0;mask<sz;mask++)
        {
            int &ans = dp[0][mask] = 1;
            int curr_mask = mask;
           
            for(int i=0;i<n-1;i++)
            {
                if(!(curr_mask&(1<<i)))
                {
                    if(curr_mask & (1<<(i+1)))
                    {
                        ans = 0;
                        break;
                    }
                    curr_mask ^= (1<<(i+1));
                }
            }

            if(!(curr_mask & (1<<(n-1)))) ans = 0;

        }

        vvi pre(sz,vi(sz));

        for(int mask= 0;mask<sz;mask++)
        {
            for(int prev_mask = 0;prev_mask<sz;prev_mask++)
            {
                dp[mask][prev_mask]  = comp(mask,prev_mask);
            }
        }

        for(int i=1;i<m;i++)
        {
            for(int mask = 0;mask<sz;mask++)
            {
                
                
            }
        }
    }
    
}