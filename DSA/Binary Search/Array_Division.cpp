//divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.

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
const int N = 2e5 + 100;
 
bool good(vector<int> &a, int mid, int k)
{
    int sum = 0, cnt = 1;
    for(int i = 0; i < (int)a.size(); i++)
    {
        if(a[i] > mid)
            return 0;
        if(a[i] + sum <= mid)
            sum += a[i];
        else
            sum = a[i], cnt++;
    }
    return cnt <= k;
}
 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    int l = 1, r = accumulate(all(a), 0ll), ans = 0;
 
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(good(a, mid, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}
 
int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}
