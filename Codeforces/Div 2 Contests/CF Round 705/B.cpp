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
const int N = 1e6 + 100;

void solve()
{
    set<int> st = {0, 1, 2, 5, 8};
    map<int,int> mp;
    mp[0] = 0, mp[1] = 1, mp[2] = 5, mp[5] = 2, mp[8] = 8;
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int x = 10*(s[0] - '0') + (s[1] - '0');
    int y = 10*(s[3] - '0') + (s[4] - '0');

    int c = 0;
    while(1)
    {
        if(y == m)   y = 0, x++;
        if(x == h)   x = 0;

        vector<int> rf1, rf2;
        set<int> cur;
        int tx = x, ty = y;
        int cnt = 0;
        while(cnt < 2)
        {
            cur.insert(tx%10);
            rf1.push_back(tx%10);
            tx /= 10;
            cnt++;
        }
        cnt = 0;
        while(cnt < 2)
        {
            cur.insert(ty%10);
            rf2.push_back(ty%10);
            ty /= 10;
            cnt++;
        }
        bool ok = 1;
        for(int z : cur)
        {
            if(st.find(z) == st.end())
                ok = 0;
        }

        if(ok)
        {
            int rx = 0, ry = 0;
            reverse(all(rf1)); reverse(all(rf2));
            rx = 10*mp[rf1[1]] + mp[rf1[0]];
            ry = 10*mp[rf2[1]] + mp[rf2[0]];
            swap(rx, ry);
            if(!(rx < h and ry < m))
                ok = 0;
        }


        if(ok)
        {
            string ans = to_string(x);
            if(sz(ans) == 1)
                ans = "0" + ans;
            ans += ':';
            string ans2 = to_string(y);
            if(sz(ans2) == 1)
                ans2 = "0" + ans2;
            ans += ans2;
            cout << ans << endl;
            return;
        }
        y++;
    }
}

int32_t main()
{
    nitro;
    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}
