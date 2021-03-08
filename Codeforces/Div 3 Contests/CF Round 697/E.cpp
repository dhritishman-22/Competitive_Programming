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


ll modular_Exponentiation(ll x,ll n)
{
    if(n == 0)
        return 1;
    else if(n%2 == 0)
        return modular_Exponentiation((x * x)%mod, n/2);
    else
        return (x*modular_Exponentiation((x * x)%mod, (n-1)/2))%mod;
}

ll mod_inverse(ll a)
{
   return modular_Exponentiation(a, mod-2);
}

ll fact[N], factinv[N];
void factorial_values()
{
    fact[0] = 1 , factinv[0] = 1;
    f(i,1,N)
    {
        fact[i] = (fact[i-1] * i) % mod;
        factinv[i] = (factinv[i-1] * mod_inverse(i)) % mod;
    }
}

ll nCr(ll n , ll r)
{
    if(r < 0 or r > n)
        return 0;
    return (fact[n] * mod_inverse(fact[n-r]) % mod * mod_inverse(fact[r]) % mod) % mod ;
}

ll add(ll a, ll b)
{
	a += b;
	if(a >= mod)
        a -= mod;
    return a;
}

ll sub(ll a, ll b)
{
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}

ll mul(ll a, ll b)
{
	return (a * b) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    get(a,n);
    vi b = a;

    int sum = 0;
    map<int,int> m;
    set<int> s;
    sort(all(b),greater<int> ());
    for(int i = 0; i < k; i++)
        sum += b[i], m[b[i]]++, s.insert(b[i]);
    vi cnt(n+1);
    for(int x : a)
        cnt[x]++;
    int ans = 1;
    for(int x : s)
    {
        ans = mul(ans, nCr(cnt[x], m[x]));
    }
    cout << ans << endl;
}

int32_t main()
{
    nitro;
    factorial_values();
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
