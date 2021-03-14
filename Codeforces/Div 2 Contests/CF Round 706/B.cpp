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
    int n, k;
    cin >> n >> k;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int cnt = 0, mex = -1;
    for(int x : s)
    {
        if(x != cnt)
        {
            mex = cnt;
            break;
        }
        cnt++;
    }
    if(mex == -1)
    {
        cout << (int)s.size() + k << endl;
        return;
    }
    else
    {
        if(k == 0)
            cout << (int)s.size() << endl;
        else
        {
            s.insert((mex + *prev(s.end()) + 1)/2);
            cout << (int)s.size() << endl;
        }
    }
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
