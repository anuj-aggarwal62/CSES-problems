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

int bs(vvi &start,int end)
{
    int n = start.size();

    int low = 0,high = n-1;

    while(low<=high)
    {
        int mid = low + (high-low)/2;

        if(start[mid][0]<=end)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return low;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;

    vvi start;
    vi end;
    vi prize;

    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        start.push_back({x,i});
        end.push_back(y);
        prize.push_back(z);
    }

    

    vi dp(n+1,0);
    sort(all(start));

    for(int i=n-1;i>=0;i--)
    {
        int s = start[i][0];
        int e = end[start[i][1]];
        int p = prize[start[i][1]];

        int next = bs(start,e);

        int &ans = dp[i];

        ans = max(ans,dp[next] + p);
        ans = max(ans,dp[i+1]);
    }

    cout<< dp[0] <<endl;
    
}