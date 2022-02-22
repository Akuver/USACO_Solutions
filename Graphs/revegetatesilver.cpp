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
const ll MAXN = 1e5;
vector<pair<ll, ll> > adj[MAXN];
ll vis[MAXN], cnt, valid = 1;
void dfs(ll node, ll col = 1)
{
    vis[node] = col;
    for (auto child : adj[node])
    {
        if (!vis[child.f])
        {
            ll num = col;
            if (child.s == 2)
            {
                if (num == 2)
                    num = 1;
                else
                    num = 2;
            }
            dfs(child.f, num);
        }
        else
        {
            if (child.s == 2 && vis[child.f] == vis[node])
                valid = 0;
            if (child.s == 1 && vis[child.f] != vis[node])
                valid = 0;
        }
    }
}
void solve(ll tcase)
{
    ll n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        char c;
        ll u, v, num;
        cin >> c >> u >> v;
        u--, v--;
        if (c == 'S')
            num = 1;
        else
            num = 2;
        adj[u].pb({v, num});
        adj[v].pb({u, num});
    }
    rep(i, 0, n) if (!vis[i]) { cnt++, dfs(i); }
    if (!valid)
    {
        cout << 0 << "\n";
        return;
    }
    cout << 1 << string(cnt, '0');
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}