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
    ll n, ans = 0;
    cin >> n;
    ll prefix[n][3];
    memset(prefix, 0, sizeof(prefix));
    rep(i, 0, n)
    {
        char c;
        cin >> c;
        if (c == 'H')
            prefix[i][0]++;
        else if (c == 'P')
            prefix[i][1]++;
        else
            prefix[i][2]++;
    }
    rep(i, 1, n) rep(j, 0, 3) prefix[i][j] += prefix[i - 1][j];
    vector<pair<ll, ll> > ops = {{0, 1}, {0, 2}, {1, 2}};
    for (auto i : ops)
    {
        ll a = i.f, b = i.s;
        ll sa = 0, sb = 0;
        rep(j, 0, n)
        {
            sa = max(sa, (j - 1 >= 0 ? prefix[j - 1][a] : 0LL) + prefix[n - 1][b] - (j - 1 >= 0 ? prefix[j - 1][b] : 0LL));
            sb = max(sb, (j - 1 >= 0 ? prefix[j - 1][b] : 0LL) + prefix[n - 1][a] - (j - 1 >= 0 ? prefix[j - 1][a] : 0LL));
        }
        ans = max(ans, max(sa, sb));
    }
    cout << ans;
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