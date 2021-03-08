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

void flipRow(vector<vector<int> > &a, int r)
{
    for(int i = 0; i < n; i++)
        a[r][i] ^= 1;
}

void FlipCol(vector<vector<int> > &a, int c)
{
    for(int i = 0; i < n; i++)
        a[i][c] ^= 1;
}

void solve()
{
    cin >> n;
    vector<vector<int> > a(n, vector<int> (n, 0));
    vector<vector<int> > b(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    }
    /**Just reform the first row and the first column(if needed) and then verify if the two matrices match**/
    if(a[0][0] != b[0][0]) flipRow(a, 0);
    for(int i = 1; i < n; i++)
    {
        if(a[0][i] != b[0][i])
            FlipCol(a, i);
    }
    for(int i = 1; i < n; i++)
    {
        if(a[i][0] != b[i][0])
            flipRow(a, i);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] != b[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
