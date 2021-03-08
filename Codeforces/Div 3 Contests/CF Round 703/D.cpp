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

vector<int> ans(105);
vector<int> a(105);
int n;

void work(int l, int r, int h = 0)
{
    if(r < l or l < 0 or r >= n)
        return;
    int mx = -1, ind = -1;
    for(int i =l; i <= r; i++)
    {
        if(a[i] > mx)
        {
            mx = a[i];
            ind = i;
        }
    }
    ans[ind] = h;
    work(l,ind-1,h+1);
    work(ind+1,r,h+1);
}

void solve()
{
    cin >> n;
    f(i,0,101)
        ans[i] = 0;
    f(i,0,n)
        cin >> a[i];
    work(0,n-1);
    f(i,0,n)
        cout << ans[i] << ' ';

    cout << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
