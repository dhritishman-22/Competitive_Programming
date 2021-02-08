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
const int N = 4;

vector<int> a[N], n(N), ans(N, -1);
int mx = inf64;

/**consider a[b1][i1] and a[b2][i2](smaller) as the extreme points**/
bool good(int b1, int i1, int b2, int i2)
{
    int cur = a[b1][i1] - a[b2][i2];
    if(cur < 0)
        return 0;
    for(int i = 0; i < N; i++)
    {
        if(i == b1 or i == b2)
            continue;
        int j = lower_bound(all(a[i]), a[b2][i2]) - a[i].begin();
        if(j == n[i] or a[i][j] > a[b1][i1])
            return 0;
    }
    if(cur < mx)
    {
        ans[b1] = a[b1][i1];
        ans[b2] = a[b2][i2];
        for(int i = 0; i < N; i++)
        {
            if(i == b1 or i == b2)
                continue;
            int j = lower_bound(all(a[i]), a[b2][i2]) - a[i].begin();
            ans[i] = a[i][j];
        }
        mx = cur;
    }
    return 1;
}

void solve()
{
    for(int i = 0; i < N; i++)
    {
        cin >> n[i];
        a[i].resize(n[i]);
        for(auto &x : a[i])
            cin >> x;
        sort(all(a[i]));
    }

    for(int b1 = 0; b1 < N; b1++)
    {
        for(int b2 = 0; b2 < N; b2++)
        {
            if(b1 == b2)
                continue;
            int r = 0, l = 0;
            while(r < n[b1])
            {
                while(l < n[b2] and good(b1, r, b2, l))
                    l++;
                r++;
            }
        }
    }
    for(int i = 0; i < N; i++)
        cout << ans[i] << ' ';
}

int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}

