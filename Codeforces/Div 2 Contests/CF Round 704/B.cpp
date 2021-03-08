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
const int N = 1e5 + 100;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    if(n == 1)
    {
        cout << a[0] << endl;
        return;
    }
    vector<int> mx(n);
    mx[0] = a[0];
    for(int i = 1; i < n; i++)
        mx[i] = max(mx[i-1], a[i]);
    int i = 0;
    vector<int> ans;
    while(i < n)
    {
        vector<int> cur;
        cur.push_back(a[i]);
        while(i < n - 1 and mx[i] == mx[i+1])
            cur.push_back(a[i+1]), i++;
        while(!cur.empty())
        {
            ans.push_back(cur.back());
            cur.pop_back();
        }
        i++;
    }
    reverse(all(ans));
    for(int x : ans)
        cout << x << ' ';
    cout << endl;
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
