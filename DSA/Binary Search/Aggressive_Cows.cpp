//assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.

#include<bits/stdc++.h>
using namespace std;
 
#define pi 3.1415926535
#define endl "\n"
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ll long long
#define setbits(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f(i,a,n) for(int i = a ; i < n ; i++)
#define rf(i,n,a) for(int i = n-1 ; i >= a ; i--)
#define F first
#define S second
#define mem(a,x) memset(a,x,sizeof(a))
#define all(c) (c).begin(),(c).end()
#define get(a,n) f(i,0,n) cin >> a[i];
#define sp(x) fixed << setprecision(10) << x
#define nitro ios:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define trace(x) cerr << '>' << #x << ':' << (x) << "\n"
#define trace2(x,y) cerr<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace3(a,b,c) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define show(a,n) f(i,0,n) cout << a[i] << " "; cout << endl;
 
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
string ds = "DULR";
 
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
 
const int inf = 1e9;
const ll inf64 = 1e18;
const int mod = inf + 7;
const int N = 2e5 + 10;
 
bool ok(int mid, const vector<int> &a, int n, int c)
{
    int prev = a[0], cnt = 1;
    f(i,1,n)
    {
        if(a[i] - prev >= mid)
        {
            prev = a[i];
            cnt++;
        }
        if(cnt == c)
            return true;
    }
    return false;
}
 
/**check for test cases**/
void solve()
{
    int n, c;
    cin >> n >> c;
    vi a(n); get(a,n);
    sort(all(a));
    int l = 0, r = inf, ans = 0;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(ok(mid, a, n, c))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
 
int main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
