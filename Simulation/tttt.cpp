#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
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
pair<ll, pair<ll, ll>> cnt(map<ll, ll> m)
{
    pair<ll, pair<ll, ll>> res = {-1, {-1, -1}}; // ind,team
    if (m.size() == 1)
        for (auto i : m)
            res.f = i.f;
    else if (m.size() == 2)
    {
        ll ta = -1, tb = -1;
        for (auto i : m)
        {
            if (ta == -1)
                ta = i.f;
            else
                tb = i.f;
        }
        res.s.f = ta, res.s.s = tb;
    }
    return res;
}
void solve(ll tcase)
{
    set<ll> ind;
    set<pair<ll, ll>> team;
    string grid[3];
    rep(i, 0, 3) cin >> grid[i];
    // row & column
    rep(i, 0, 3)
    {
        map<ll, ll> m;
        rep(j, 0, 3) m[grid[i][j] - 'A']++;
        auto res = cnt(m);
        if (res.f != -1)
            ind.insert(res.f);
        if (res.s.f != -1)
            team.insert(res.s);
        m.clear();
        rep(j, 0, 3) m[grid[j][i] - 'A']++;
        res = cnt(m);
        if (res.f != -1)
            ind.insert(res.f);
        if (res.s.f != -1)
            team.insert(res.s);
    }
    // diagonal
    map<ll, ll> m[2];
    rep(i, 0, 3)
    {
        rep(j, 0, 3)
        {
            if (i == j)
                m[0][grid[i][j] - 'A']++;
            if (i + j == 2)
                m[1][grid[i][j] - 'A']++;
        }
    }
    rep(j, 0, 2)
    {
        auto res = cnt(m[j]);
        if (res.f != -1)
            ind.insert(res.f);
        if (res.s.f != -1)
            team.insert(res.s);
    }
    cout << ind.size() << "\n"
         << team.size();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}