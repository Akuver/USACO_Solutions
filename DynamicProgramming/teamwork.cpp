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
    ll N, K;
    cin >> N >> K;
    ll dp[N + 1], s[N + 1];
    rep(i, 1, N + 1) cin >> s[i];
    s[0] = -1;
    memset(dp, 0, sizeof(dp));
    dp[1] = s[1];
    rep(i, 2, N + 1)
    {
        ll maxi = s[i];
        for (ll j = i; j >= 1 && i - j + 1 <= K; j--)
        {
            maxi = max(maxi, s[j]);
            if (j == 1)
                dp[i] = max(dp[i], maxi * (i + 1 - j));
            else
                dp[i] = max(dp[i], dp[j - 1] + maxi * (i + 1 - j));
        }
    }
    cout << dp[N];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}