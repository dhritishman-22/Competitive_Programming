//maximum sum of values in a contiguous subarray with length between l and r.

#include<bits/stdc++.h>
using namespace std;
 
#define pi 3.1415926535
#define int long long
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define pb push_back
#define sz(x) (int)x.size()
#define f(i,a,n) for(int i = a ; i < n ; i++)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define get(a,n) f(i,0,n) cin >> a[i];
#define show(a,n) f(i,0,n) cout << a[i] << " "; cout << endl;
#define nitro ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define trace(x) cerr << '>' << #x << ':' << (x) << "\n"
#define trace2(x,y) cerr<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace3(a,b,c) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
 
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
 
const int inf = 2e9;
const int inf64 = 2e18;
const int mod = 1000000007;
const int N = 1e6 + 100;
 
void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), pre(n);
    for(auto &x : a)
        cin >> x;
    for(int i = 0 ;i < n; i++)
    {
        pre[i] = a[i];
        if(i > 0) pre[i] += pre[i-1];
    }
    multiset<int> ms;
 
    ms.insert(0);
    int ans = pre[l - 1], flag = 0;
 
    for(int i = l; i < n; i++)
    {
        if(i >= r)
        {
            if(!flag)
            {
                ms.erase(ms.find(0));
                flag = 1;
            }
        }
 
        ms.insert(pre[i - l]);
 
        ans = max(ans, pre[i] - *ms.begin());
 
        if(i >= r)
            ms.erase(ms.find(pre[i - r]));
    }
    cout << ans;
}
 
int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
