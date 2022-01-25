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
vector<ll> adj[10];
bool comp(vector<ll> a, vector<ll> b)
{
    return *a.begin() < *b.begin();
}
void solve(ll tcase)
{
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sortv(cows);
    map<string, ll> id;
    rep(i, 0, cows.size()) id[cows[i]] = i;
    ll n;
    cin >> n;
    rep(i, 0, n)
    {
        string s;
        ll u, v;
        rep(j, 0, 6)
        {
            cin >> s;
            if (j == 0)
                u = id[s];
            if (j == 5)
                v = id[s];
        }
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> res;
    ll done[8] = {0};
    rep(i, 0, 8)
    {
        if (!done[i] && adj[i].size() <= 1)
        {
            ll cur = i;
            while (adj[cur].size() == 1)
            {
                res.pb(cur);
                done[cur] = 1;
                ll nxt = adj[cur][0];
                adj[nxt].erase(remove(adj[nxt].begin(), adj[nxt].end(), cur), adj[nxt].end());
                cur = nxt;
            }
            res.pb(cur);
            done[cur] = 1;
        }
    }
    for (auto i : res)
        cout << cows[i] << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}