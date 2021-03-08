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
    return (a % mod * b % mod) % mod;
}

vector<int> spf(N);
void sieve()
{
    spf[1] = 1;
    for(int i = 2; i < N; i++)
        spf[i] = i;

    for(int i = 4; i < N; i += 2)
        spf[i] = 2;

    for(int i = 3; i*i < N; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i*i; j < N; j += i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

multiset<int> mn[N];  //mn[p] -> all non-zero a[i][p]
map<int, int> expo[N]; //expo[i][p] -> exponent of p in i

void solve()
{
    int n, m, ans = 1;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while(x > 1)
        {
            int p = spf[x];
            if(expo[i][p] == 0)
                mn[p].insert(0);
            int minm = *mn[p].begin();
            mn[p].erase(mn[p].find(expo[i][p]));
            expo[i][p]++;
            mn[p].insert(expo[i][p]);
            if((int)mn[p].size() == n and *mn[p].begin() > minm) //while accessing the last element
                ans = mul(ans, p);
            x /= p;
        }
    }
    while(m--)
    {
        int i, x;
        cin >> i >> x;
        i--;

        while(x > 1)
        {
            int p = spf[x];
            if(expo[i][p] == 0)
                mn[p].insert(0);
                        int minm = *mn[p].begin();
            mn[p].erase(mn[p].find(expo[i][p]));
            expo[i][p]++;
            mn[p].insert(expo[i][p]);
            if((int)mn[p].size() == n and *mn[p].begin() > minm)
                ans = mul(ans, p);
            x /= p;
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    nitro;
    sieve();
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}
