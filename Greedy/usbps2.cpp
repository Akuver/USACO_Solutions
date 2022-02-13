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
    ll a, b, c, m, cost = 0, cnt = 0;
    cin >> a >> b >> c >> m;
    vector<ll> mo[2];
    rep(i, 0, m)
    {
        ll x;
        string s;
        cin >> x >> s;
        if (s == "USB")
            mo[0].pb(x);
        else
            mo[1].pb(x);
    }
    rep(j, 0, 2) sortv(mo[j]);
    ll x = min((ll)mo[0].size(), a);
    ll y = min((ll)mo[1].size(), b);
    cnt += x + y;
    rep(i, 0, x) cost += mo[0][i];
    rep(i, 0, y) cost += mo[1][i];
    a -= x;
    b -= y;
    ll p1 = x, p2 = y;
    while (p1 < mo[0].size() && p2 < mo[1].size())
    {
        ll c1 = mo[0][p1], c2 = mo[1][p2];
        if (c1 <= c2)
        {
            if (a)
                a--, cnt++, cost += c1, p1++;
            else if (c)
                c--, cnt++, cost += c1, p1++;
            else
                p1++;
        }
        else
        {
            if (b)
                b--, cnt++, cost += c2, p2++;
            else if (c)
                c--, cnt++, cost += c2, p2++;
            else
                p2++;
        }
        if (a + b + c == 0)
            break;
    }
    while (p1 < mo[0].size())
    {
        if (a)
            a--, cnt++, cost += mo[0][p1], p1++;
        else if (c)
            c--, cnt++, cost += mo[0][p1], p1++;
        if (a + c == 0)
            break;
    }
    while (p2 < mo[1].size())
    {
        if (b)
            b--, cnt++, cost += mo[1][p2], p2++;
        else if (c)
            c--, cnt++, cost += mo[1][p2], p2++;
        if (b + c == 0)
            break;
    }
    cout << cnt << ' ' << cost;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}