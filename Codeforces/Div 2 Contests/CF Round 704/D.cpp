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
    int a, b, k;
    cin >> a >> b >> k;
    if(a == 0)
    {
        string s = string(b, '1');
        if(k == 0)
        {
            cout << "Yes\n";
            cout << s << endl << s;
        }
        else
            cout << "No\n";
    }
    else if(b == 1)
    {
        if(k == 0)
        {
            cout << "Yes\n";
            string s = string(a, '0');
            s = "1" + s;
            cout << s << endl << s;
        }
        else
            cout << "No\n";
    }
    else
    {
        if(k > a + b - 2)
            cout << "No\n";
        else
        {
            cout << "Yes\n";
            if(k <= a)
            {
                string x = string(b, '1') + string(a, '0');
                string s = string(b - 1, '1');
                s += string(k, '0');
                s += "1";
                s += string(a - k, '0');
                cout << x << endl << s;
            }
            else
            {
                k -= a;
                string x = string(b, '1') + string(a, '0');
                string s = string(b - k - 1, '1');
                s += "0";
                s += string(k, '1');
                s += string(a - 1, '0');
                s += "1";
                cout << x << endl << s;
            }
        }
    }
}

int32_t main()
{
    nitro;
    int tc = 1;
//    cin >> tc;
    while(tc--) solve();
}
