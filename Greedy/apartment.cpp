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
    ll n, m, k, cnt = 0;
    cin >> n >> m >> k;
    ll a[n], b[m];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    sorta(a, n);
    sorta(b, m);
    ll posb = 0, posa = 0;
    while (posa < n && posb < m)
    {
        ll a_size = a[posa];
        ll b_size = b[posb];
        if (abs(a_size - b_size) <= k)
        {
            posa++, posb++, cnt++;
            continue;
        }
        if (a_size < b_size)
            posa++;
        if (b_size < a_size)
            posb++;
    }

    cout << cnt;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}