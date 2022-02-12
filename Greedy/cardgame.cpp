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
    ll n, wins = 0;
    cin >> n;
    ll a[n], b[n];
    vector<ll> done(2 * n, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
        done[a[i]] = 1;
    }
    ll pos = 0;
    rep(i, 0, 2 * n) if (!done[i]) b[pos++] = i;
    set<ll> p1, p2;
    rep(i, 0, n)
    {
        if (i < n / 2)
            p1.insert(b[i]);
        else
            p2.insert(b[i]);
    }
    rep(i, 0, n)
    {
        if (i < n / 2)
        {
            auto it = p2.upper_bound(a[i]);
            if (it == p2.end())
            {
                p2.erase(p2.begin());
                continue;
            }
            p2.erase(it);
            wins++;
        }
        else
        {
            auto it = p1.lower_bound(a[i]);
            if (it == p1.end())
                it--;
            if (*it > a[i] && it != p1.begin())
                it--;
            if (*it > a[i])
            {
                p1.erase((--p1.end()));
                continue;
            }
            p1.erase(it);
            wins++;
        }
    }
    cout << wins;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}