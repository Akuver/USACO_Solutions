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
map<ll, char> m;
ll res(ll x, char c)
{
    char d = m[x];
    if (d == 'H' && c == 'S')
        return 1;
    if (d == 'S' && c == 'P')
        return 1;
    if (d == 'P' && c == 'H')
        return 1;
    return 0;
}
void solve(ll tcase)
{
    ll n, k;
    cin >> n >> k;
    char move[n + 1];
    m[0] = 'H', m[1] = 'P', m[2] = 'S';
    rep(i, 1, n + 1) cin >> move[i];
    ll cnt[n + 1][k + 1][3];
    rep(i, 0, n + 1) rep(j, 0, k + 1) rep(l, 0, 3) cnt[i][j][l] = -1;
    rep(j, 0, k + 1) rep(l, 0, 3) cnt[0][j][l] = 0;
    rep(i, 1, n + 1)
    {
        rep(j, 0, k + 1)
        {
            rep(l, 0, 3)
            {
                cnt[i][j][l] = max(cnt[i - 1][j][l], cnt[i][j][l]);
                if (j - 1 >= 0)
                    rep(x, 0, 3) cnt[i][j][l] = max(cnt[i][j][l], cnt[i - 1][j - 1][x]);
                cnt[i][j][l] += res(l, move[i]);
            }
        }
    }
    ll maxi = 0;
    rep(l, 0, 3) maxi = max(maxi, cnt[n][k][l]);
    cout << maxi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}