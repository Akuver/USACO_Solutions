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
    ll n, o = 0, e = 0;
    cin >> n;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        (x & 1) ? o++ : e++;
    }
    if (e == o)
    {
        cout << 2 * e;
        return;
    }
    if (e > o)
    {
        cout << 2 * o + 1;
        return;
    }
    ll ans = 2 * e;
    o -= e;
    // ll t = 0;
    // while (o)
    // {
    //     if (!t)
    //     {
    //         if (o >= 2)
    //             o -= 2, ans++;
    //         else
    //             o = 0, ans--;
    //     }
    //     else
    //     {
    //         if (o >= 1)
    //             o--, ans++;
    //     }
    //     t = !t;
    // }
    ans += (o / 3) * 2;
    if (o % 3 == 2)
        ans++;
    else if (o % 3 == 1)
        ans--;
    cout << ans;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}