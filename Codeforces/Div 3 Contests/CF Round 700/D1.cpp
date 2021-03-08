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

int n;
vector<int> a(N), pos[N];

int nxt(int x, int ind)
{
    return *lower_bound(all(pos[x]), ind);
}

void solve()
{
    cin >> n;
    a.resize(n);
    for(auto &x : a)
        cin >> x;
    for(int i = 0; i < n; i++)
        pos[a[i]].push_back(i);
    for(int i = 0; i <= n; i++)
        pos[i].push_back(n);
    int ans = n;

    int end1 = 0, end2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == end1 and a[i] == end2)
            ans--;
        else if(a[i] == end1)
            end2 = a[i];
        else if(a[i] == end2)
            end1 = a[i];
        else
        {
            if(nxt(end1, i) < nxt(end2, i))
                end1 = a[i];
            else
                end2 = a[i];
        }
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
