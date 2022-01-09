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
    ll k, n, ans = 0;
    cin >> k >> n;
    vector<ll> rank[k];
    rep(i, 0, k)
    {
        rank[i].resize(n);
        rep(j, 0, n) cin >> rank[i][j];
    }
    rep(i, 1, n + 1)
    {
        rep(j, i + 1, n + 1)
        {
            ll cnt = 0;
            rep(z, 0, k)
            {
                ll pi, pj;
                rep(u, 0, n)
                {
                    if (rank[z][u] == i)
                        pi = u;
                    if (rank[z][u] == j)
                        pj = u;
                }
                if (pi > pj)
                    cnt++;
            }
            if (cnt % k == 0)
                ans++;
        }
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}