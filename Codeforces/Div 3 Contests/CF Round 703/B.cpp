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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    vector<int> v(3);
    for(int x : a)
        v[x%3]++;
    int ans = 0;
    if(v[0] > v[1])
    {
        int d = v[0] - n/3;
        ans += d;
        v[0] -= d;
        v[1] += d;
    }
    if(v[1] > v[2])
    {
        int d = v[1] - n/3;
        ans += d;
        v[1] -= d;
        v[2] += d;
    }
    if(v[2] > v[0])
    {
        int d = v[2] - n/3;
        ans += d;
        v[2] -= d;
        v[0] += d;
    }


    if(v[0] > v[1])
    {
        int d = v[0] - n/3;
        ans += d;
        v[0] -= d;
        v[1] += d;
    }
    if(v[1] > v[2])
    {
        int d = v[1] - n/3;
        ans += d;
        v[1] -= d;
        v[2] += d;
    }
    if(v[2] > v[0])
    {
        int d = v[2] - n/3;
        ans += d;
        v[2] -= d;
        v[0] += d;
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
