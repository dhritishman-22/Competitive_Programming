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

int n, k;

struct stck
{
    vector<int> cur, curMax = {-inf64}, curMin = {inf64};

    void push(int x)
    {
        cur.push_back(x);
        curMax.push_back(max(curMax.back(), x));
        curMin.push_back(min(curMin.back(), x));
    }

    int pop()
    {
        int val = cur.back();
        cur.pop_back();
        curMax.pop_back();
        curMin.pop_back();
        return val;
    }

    bool empty()
    {
        return cur.empty();
    }

    int minn()
    {
        return curMin.back();
    }

    int maxx()
    {
        return curMax.back();
    }
};

stck s1, s2;

void add(int x)
{
    s2.push(x);
}

void remove()
{
    if(s1.empty())
    {
        while(!s2.empty())
            s1.push(s2.pop());
    }
    s1.pop();
}

bool good()
{
    int mn = min(s1.minn(), s2.minn());
    int mx = max(s1.maxx(), s2.maxx());
    return (mx - mn <= k);
}

void solve()
{
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;

    int l = 0, r = 0, ans = 0;
    while(r < n)
    {
        add(a[r]);
        while(!good())
        {
            remove();
            l++;
        }
        ans += (r - l + 1);
        r++;
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

