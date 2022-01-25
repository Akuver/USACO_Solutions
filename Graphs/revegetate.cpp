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
const ll N = 105;
vector<ll> adj[N];
ll grass[N];
void col(ll node)
{
    rep(i, 1, 5)
    {
        bool valid = true;
        for (auto child : adj[node])
        {
            if (grass[child] == i)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            grass[node] = i;
            return;
        }
    }
}
void solve(ll tcase)
{
    ll n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i, 1, n + 1) col(i);
    rep(i, 1, n + 1) cout << grass[i];
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