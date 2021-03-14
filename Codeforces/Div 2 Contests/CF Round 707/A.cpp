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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), tm(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for(int i = 1; i <= n; i++)
        cin >> tm[i];

    vector<int> dep(n+1), arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i] = dep[i-1] + (a[i] - b[i-1]) + tm[i];
        dep[i] = max(b[i], arr[i] + (b[i] - a[i] + 1)/2);
    }
    cout << arr[n] << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
