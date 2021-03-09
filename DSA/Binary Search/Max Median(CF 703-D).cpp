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

const int inf = 1e9;
const int inf64 = 1e18;
const int mod = inf + 7;
const int N = 1e6 + 5;

bool work(vector<int> &a, int x, int n, int k)
{
    vector<int> pre(n);
    for(int i = 0; i < n; i++)
    {
        pre[i] = (a[i] >= x ? 1 : -1);
        if(i > 0)
            pre[i] += pre[i-1];
    }

    int mn = 0;
    int mx = pre[k - 1];
    for(int i = k; i < n; i++)
    {
        mn = min(mn, pre[i - k]);
        mx = max(mx, pre[i] - mn);
    }
    return (mx > 0 ? 1 : 0);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    int l = 1, r = n + 1, ans = 0;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(work(a, mid, n, k))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}
