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
ll gcd(ll a, ll b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
using namespace std;
vector<ll> ar;
void foo(ll a1, ll a2, ll b1, ll b2)
{
    a1--, a2--, b1--, b2--;
    rep(i, a1, a2 + 1)
    {
        if (i >= a2 - i + a1)
            break;
        swap(ar[i], ar[a2 - i + a1]);
    }
    rep(i, b1, b2 + 1)
    {
        if (i >= b2 - i + b1)
            break;
        swap(ar[i], ar[b2 - i + b1]);
    }
}
void solve(ll tcase)
{
    ll n, k;
    cin >> n >> k;
    ll a[2], b[2];
    rep(i, 0, 2) cin >> a[i];
    rep(i, 0, 2) cin >> b[i];
    ar.resize(n);
    iota(ar.begin(), ar.end(), 0);
    ll l = 0;
    rep(i, 0, k)
    {
        foo(a[0], a[1], b[0], b[1]);
        ll flag = 1;
        rep(i, 0, n) if (ar[i] != i)
        {
            flag = 0;
            break;
        }
        if (flag)
        {
            l = i + 1;
            break;
        }
    }
    if (l)
    {
        k %= l;
        rep(i, 0, k) foo(a[0], a[1], b[0], b[1]);
    }
    for (auto i : ar)
        cout << i + 1 << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}