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
const int N = 1e6 + 50;

bool check(int x, vector<int> &a, vector<int> &b, int y, int m)
{
    int sum = 0;
    if(x > 0)
        sum += a[x-1];
    if(y > 0)
        sum += b[y-1];
//    trace(sum);
    return (sum >= m);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ones, twos;
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        if(b[i] == 1)
            ones.push_back(a[i]);
        else
            twos.push_back(a[i]);
    }
    sort(all(ones), greater<int> ());
    sort(all(twos), greater<int> ());

    for(int i = 1; i < sz(ones); i++)
        ones[i] += ones[i-1];
    for(int i = 1; i < sz(twos); i++)
        twos[i] += twos[i-1];

    if(accumulate(all(a),0ll) < m)
    {
        cout << "-1\n";
        return;
    }

    int ans = inf64;
    for(int i = 0; i <= sz(ones); i++)
    {
        int l = 0, r = sz(twos);
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(check(mid, twos, ones, i, m))
            {
                ans = min(ans, i + 2*mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
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
