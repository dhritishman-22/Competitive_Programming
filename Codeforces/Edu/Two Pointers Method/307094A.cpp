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
const int N = 2e5 + 50;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(2*n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = n; i < 2*n; i++)
        a[i] = a[i - n];

    int total = 0;
    for(int i = 0; i < n; i++)
        total += a[i];
    int org = p;
    p %= total;

    int l = 0, r = 0, ans = inf, start = -1, sum = 0;
    while(r < 2*n)
    {
        sum += a[r];
        while(sum - a[l] >= p)
        {
            sum -= a[l];
            l++;
        }
        if(r - l + 1 < ans and sum >= p)
        {
            ans = r - l + 1;
            start = l;
        }
        r++;
    }

    if(org % total == 0)
    {
        cout << "1 " << org/total * n  << endl;
        return;
    }
    if(org > total)
        ans += (org/total * n);
    cout << start + 1 << ' ' << ans << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}

