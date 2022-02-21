#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << " is " << x;
#define rep(i, a, N) for (ll i = a; i < N; i++)
#define f first
#define s second
#define uniq(v)                                       \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

void solve(ll tcase)
{
    ll x[2], y[2], n;
    string s;
    rep(i, 0, 2) cin >> x[i] >> y[i];
    cin >> n >> s;
    ll lo = 0, hi = 1e18;
    ll cntud = y[1] - y[0], cntrd = x[1] - x[0];
    while (lo < hi)
    {
        ll m = (lo + hi) / 2;
        ll q = m / n, r = m % n;
        ll cntup = 0, cntright = 0;
        if (q)
        {
            rep(i, 0, n)
            {
                if (s[i] == 'U')
                    cntup++;
                else if (s[i] == 'D')
                    cntup--;
                else if (s[i] == 'R')
                    cntright++;
                else
                    cntright--;
            }
            cntup *= q;
            cntright *= q;
        }
        if (r)
        {
            rep(i, 0, r)
            {
                if (s[i] == 'U')
                    cntup++;
                else if (s[i] == 'D')
                    cntup--;
                else if (s[i] == 'R')
                    cntright++;
                else
                    cntright--;
            }
        }
        ll cntupleft = abs(cntud - cntup), cntrightleft = abs(cntrd - cntright);
        if (cntupleft + cntrightleft <= m)
            hi = m;
        else
            lo = m + 1;
    }
    if (hi == 1e18)
        hi = -1;
    cout << hi;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}