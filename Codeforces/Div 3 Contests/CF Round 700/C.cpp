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

vector<int> a(N);

int ask(int i)
{
    cout << "? " << i << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n+2);
    fill(all(a),0);
    a[0] = a[n+1] = inf;
    if(n == 1)
    {
        cout << "! 1";
        return;
    }
    a[1] = ask(1);
    a[2] = ask(2);
    if(a[1] < a[2])
    {
        cout << "! 1";
        return;
    }
    if(a[n] == 0)
        a[n] = ask(n);
    if(a[n-1] == 0)
        a[n-1] = ask(n-1);
    if(a[n-1] > a[n])
    {
        cout << "! " << n;
        return;
    }
    int i = 1, j = n;
    while(1)
    {
        int m = (i + j)/2;
        if(a[m] < a[m-1] and a[m] < a[m+1] and a[m] and a[m+1] and a[m-1])
        {
            cout << "! " << m;
            return;
        }
        if(a[m] == 0)
            a[m] = ask(m);
        if(a[m+1] == 0)
            a[m+1] = ask(m+1);
        if(a[m] > a[m+1])
            i = m;
        else
            j = m+1;
    }
}

int32_t main()
{
//    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}
