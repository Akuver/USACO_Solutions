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
    ll n, ans;
    cin >> n;
    string s;
    cin >> s;
    set<char> x;
    for (auto i : s)
        x.insert(i);
    ll lo = 0, hi = n;
    while (lo < hi)
    {
        ll m = (lo + hi) / 2, flag = 0;
        map<char, ll> y;
        rep(i, 0, m) y[s[i]]++;
        rep(i, m, n + 1)
        {
            ll mf = 1;
            for (auto i : x)
            {
                if (y[i] <= 0)
                {
                    mf = 0;
                    break;
                }
            }
            if (mf)
            {
                flag = 1;
                break;
            }
            if (i != n)
            {
                y[s[i - m]]--;
                y[s[i]]++;
            }
        }
        if (flag)
            hi = m;
        else
            lo = m + 1;
    }
    cout << hi;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}