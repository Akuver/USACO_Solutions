#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << "is" << x;
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
void op(ll &a, ll &dist, ll toreach)
{
    if (toreach < a)
        a--, dist++;
    else if (toreach > a)
        a++, dist++;
}
void solve(ll tcase)
{
    ll a, b, dist = 0, type = 0;
    cin >> a >> b;
    ll olda = a;
    for (ll i = 1; i <= 10000; i *= 2)
    {
        ll toreach = olda;
        if (!type)
            toreach += i;
        else
            toreach -= i;

        while (a != toreach)
        {
            op(a, dist, toreach);
            if (a == b)
            {
                cout << dist;
                return;
            }
        }

        type = !type;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}