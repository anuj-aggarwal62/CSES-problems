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

    vector<vector<char>> vec(n,vector<char>(n));
    loop(i,n)
    {
        loop(j,n)
        {
            cin>>vec[i][j];
        }
    }

    vi dp(n+1,0);



    rev(i,n-1,0)
    {
        vi ndp(n+1,0);
        rev(j,n-1,0)
        {
            if(i==n-1 && j==n-1) 
            {
                ndp[j] = (vec[i][j]=='.');
                continue;
            }
            ndp[j] += ndp[j+1];
            ndp[j] %= mod;
            ndp[j] += dp[j];
            ndp[j] %= mod;

            if(vec[i][j]=='*') ndp[j] = 0;
        }
        dp = ndp;
    }

    cout<< dp[0] <<endl;
    
}