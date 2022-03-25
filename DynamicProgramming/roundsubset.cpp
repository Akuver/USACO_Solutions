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
    ll n, k;
    cin >> n >> k;
    pair<ll, ll> A[n + 1];
    rep(i, 1, n + 1)
    {
        ll x, p2 = 0, p5 = 0;
        cin >> x;
        while (x % 2 == 0)
            x /= 2, p2++;
        while (x % 5 == 0)
            x /= 5, p5++;
        A[i] = {p2, p5};
    }
    ll maxl = 5200, maxj = k + 1;
    vector<vector<ll> > fdp(maxj, vector<ll>(maxl, -1LL)), ndp(maxj, vector<ll>(maxl, -1LL));
    fdp[1][A[1].s] = A[1].f;
    rep(i, 2, n + 1)
    {
        fdp[0][0] = 0;
        rep(j, 1, min(maxj, i + 1))
        {
            rep(l, 0, maxl)
            {
                ll maxi = -1;
                maxi = max(maxi, fdp[j][l]);
                if (l >= A[i].s && fdp[j - 1][l - A[i].s] != -1)
                    maxi = max(maxi, fdp[j - 1][l - A[i].s] + A[i].f);
                ndp[j][l] = maxi;
            }
        }
        fdp = ndp;
    }
    ll ans = 0;
    rep(j, 0, maxj) rep(l, 0, maxl) ans = max(ans, min(fdp[j][l], l));
    cout << ans;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}
