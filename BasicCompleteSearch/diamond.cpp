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
    ll N, K, ans = 0;
    cin >> N >> K;
    vector<ll> siz(N);
    rep(i, 0, N) cin >> siz[i];
    sortv(siz);
    rep(i, 0, N)
    {
        ll mini = siz[i];
        ll res = 0;
        rep(j, 0, N) if (siz[j] - mini <= K && siz[j] - mini >= 0) res++;
        ans = max(ans, res);
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}