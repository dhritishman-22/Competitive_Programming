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

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    /**unordered_map<long long, int, custom_hash> safe_map;**/
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    int ans = inf;
    unordered_map<int,int,custom_hash> mp;
    for(int x : a)
        mp[x]++;
    vector<int> cnt;
    for(auto it: mp)
        cnt.push_back(it.S);
    sort(all(cnt));

    vector<int> pre(sz(cnt)), suf(sz(cnt));
    pre[0] = cnt[0];
    f(i,1,sz(cnt))
        pre[i] += pre[i-1], pre[i] += cnt[i];
    suf[sz(cnt) - 1] = cnt[sz(cnt) - 1];
    for(int i = sz(cnt)-2; i >= 0; i--)
        suf[i] += suf[i+1], suf[i] += cnt[i];

    for(int i = 1; i <= n; i++)
    {
        int cur = 0;
        int d = lower_bound(all(cnt),i) - cnt.begin();
        if(d > 0)
            cur += pre[d-1];
        d = upper_bound(all(cnt),i) - cnt.begin();
        if(d < sz(cnt))
            cur += suf[d] - (sz(cnt) - d)*i;
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
