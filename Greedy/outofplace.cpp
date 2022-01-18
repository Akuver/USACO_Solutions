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
bool foo(ll a[], ll n, ll i)
{
    ll b[n - 1], pos = 0;
    rep(j, 0, n)
    {
        if (j == i)
            continue;
        b[pos++] = a[j];
    }
    rep(j, 0, n - 2) if (b[j] > b[j + 1]) return 0;
    return 1;
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    ll a[n];
    ll ind = -1, t = -1;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n)
    {
        if (a[i] > a[i + 1] && i + 1 < n)
        {
            if (foo(a, n, i))
                ind = i, t = 1;
            else
                ind = i + 1, t = 0;
        }
    }
    set<ll> ele;
    if (!t)
        for (ll i = ind - 1; i >= 0; i--)
        {
            if (a[i] > a[ind])
                ele.insert(a[i]);
        }
    else
        rep(i, ind + 1, n)
        {
            if (a[i] < a[ind])
                ele.insert(a[i]);
        }
    cout << ele.size();
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}