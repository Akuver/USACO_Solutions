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
const ll MAXN = 1001;
const ll MAXD = 1001;
ll N, M, C, m[MAXN], dp[MAXN][MAXD], best[MAXN];
vector<ll> adj[MAXN];
void solve(ll tcase)
{
    cin >> N >> M >> C;
    rep(i, 1, N + 1) cin >> m[i];
    rep(i, 0, M)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    dp[1][0] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
    q.push({0, 1});
    while (!q.empty())
    {
        auto node = q.top();
        ll par = node.s, d = node.f;
        q.pop();
        if (d >= MAXD)
            continue;
        for (auto child : adj[par])
        {
            dp[child][d + 1] = max(dp[par][d] + m[child] + C * d * d - C * (d + 1) * (d + 1), dp[child][d + 1]);
            if (best[child] < dp[child][d + 1])
                q.push({d + 1, child}), best[child] = dp[child][d + 1];
        }
    }

    cout << best[1];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}