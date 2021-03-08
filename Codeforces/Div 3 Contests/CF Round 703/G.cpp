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
     int n, m;
     cin >> n >> m;
     vector<int> a(n);
     for(auto &x : a)
        cin >> x;
     vector<int> pre, ind;

     int cur_ind = 0, sum = 0;
     for(int i = 0; i < n; i++)
     {
        sum += a[i];
        if(pre.empty() or sum > pre.back())
        {
            pre.push_back(sum);
            ind.push_back(cur_ind);
        }
        cur_ind++;
     }

     while(m--)
     {
         int x;
         cin >> x;
         if(pre.back() < x and sum <= 0)
         {
             cout << "-1 ";
             continue;
         }
         int times = 0;
         if(pre.back() < x)
             times = (x - pre.back() + sum - 1)/sum; //try to minimise number of rotations
         x -= times * sum;
         int ans = times * n;
         ans += ind[lower_bound(all(pre),x) - pre.begin()];
         cout << ans << ' ';
     }
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
