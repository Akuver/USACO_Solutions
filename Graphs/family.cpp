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
const ll N = 1000;
ll p[N], dep[N];
ll par(ll x)
{
    if (p[x] == x)
        return x;
    return par(p[x]);
}
ll d(ll x)
{
    if (p[x] == x)
        return 0;
    return d(p[x]) + 1;
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    map<string, ll> id;
    rep(i, 0, N) p[i] = i;
    ll num = 1;
    id[a] = num++;
    id[b] = num++;
    vector<string> ans;
    rep(i, 0, n)
    {
        string u, v;
        cin >> u >> v;
        if (!id[u])
            id[u] = num++;
        if (!id[v])
            id[v] = num++;
        p[id[v]] = id[u];
    }
    rep(i, 0, num + 1) dep[i] = d(i);
    if (par(id[a]) != par(id[b]))
    {
        cout << "NOT RELATED";
        return;
    }
    if (dep[id[a]] == dep[id[b]])
    {
        if (p[id[a]] == p[id[b]])
            cout << "SIBLINGS";
        else
            cout << "COUSINS";
        return;
    }
    if (dep[id[a]] < dep[id[b]])
        swap(a, b);
    if (dep[id[a]] > dep[id[b]])
    {
        vector<ll> hist;
        ll x = id[a], y = id[b];
        while (true)
        {
            hist.pb(p[x]);
            x = p[x];
            if (p[x] == x)
                break;
        }
        ll flag = 0;
        rep(i, 0, hist.size())
        {
            if (hist[i] == id[b])
            {
                rep(j, 0, i - 1) ans.pb("great-");
                if (i)
                    ans.pb("grand-");
                ans.pb("mother");
                flag = 1;
            }
        }
        if (!flag)
        {
            ll diff = dep[id[a]] - dep[id[b]];
            rep(i, 0, diff - 1) ans.pb("great-");
            ans.pb("aunt");
            ll u = ans.size() + 1, v = 1;
            x = id[a];
            ll resu, resv;
            rep(i, 0, u) resu = p[x], x = p[x];
            rep(i, 0, v) resv = p[y], y = p[y];
            if (resu != resv)
            {
                cout << "COUSINS";
                return;
            }
        }
    }

    cout << b << " is the ";
    for (auto i : ans)
        cout << i;
    cout << " of " << a;
    cout << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}