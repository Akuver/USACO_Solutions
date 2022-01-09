#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
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

void solve(ll tcase)
{
    string s;
    cin >> s;
    pair<ll, ll> points[26];
    ll ans = 0;
    rep(i, 0, 26) points[i] = {-1, -1};
    rep(i, 0, 52)
    {
        ll c = s[i] - 'A';
        if (points[c].f == -1)
            points[c].f = i + 1;
        else
            points[c].s = i + 1;
    }
    sorta(points, 26);
    rep(i, 0, 26) rep(j, i + 1, 26)
    {
        ll a = points[i].f, b = points[i].s, c = points[j].f, d = points[j].s;
        if (b > c && b < d)
            ans++;
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}