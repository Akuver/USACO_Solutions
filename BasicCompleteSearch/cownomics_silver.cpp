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
    ll n, m, ans = 0;
    cin >> n >> m;
    string s[n], p[n];
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, n) cin >> p[i];
    vector<array<ll, 3>> comb;
    rep(i, 0, m) rep(j, i + 1, m) rep(k, j + 1, m) comb.pb({i, j, k});
    for (auto i : comb)
    {
        map<string, ll> P, S;
        ll flag = 1;
        rep(j, 0, n)
        {
            string a, b;
            rep(k, 0, 3)
            {
                a.pb(s[j][i[k]]);
                b.pb(p[j][i[k]]);
            }
            S[a]++;
            P[b]++;
            if (P[a] || S[b])
            {
                flag = 0;
                break;
            }
        }
        ans += flag;
    }

    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}