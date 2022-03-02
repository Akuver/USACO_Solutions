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
ll power(ll a, ll b, ll mod = MOD)
{
    a %= mod;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll mult(ll a, ll b, ll mod = MOD)
{
    a %= mod, b %= mod;
    a *= b;
    a %= mod;
    return a;
}
ll modInverse(ll x)
{
    return power(x, MOD - 2, MOD) % MOD;
}
void solve(ll tcase)
{
    ll n, flag = 0;
    ;
    cin >> n;
    pair<ll, ll> fac[n];
    vector<ll> cnt[2];
    rep(i, 0, n)
    {
        cin >> fac[i].f >> fac[i].s;
        cnt[0].pb(fac[i].s);
        cnt[1].pb(fac[i].s + 1);
        if (fac[i].s & 1)
            flag = 1;
    }
    if (flag)
    {
        for (auto &i : cnt[1])
            if (i % 2 == 0)
            {
                i /= 2;
                break;
            }
    }
    else
    {
        for (auto &i : cnt[0])
            i /= 2;
    }
    ll numdiv = 1, sumdiv = 1, proddiv = 1, nnumdiv = 1;
    rep(i, 0, n)
    {
        numdiv = mult(numdiv, fac[i].s + 1);
        ll numerator = (power(fac[i].f, fac[i].s + 1) - 1 + MOD) % MOD;
        ll denominator = modInverse(fac[i].f - 1);
        numerator = mult(numerator, denominator);
        sumdiv = mult(sumdiv, numerator);
    }
    for (auto i : cnt[1])
        nnumdiv = mult(nnumdiv, i, MOD - 1);
    rep(i, 0, n)
    {
        ll x = nnumdiv;
        x = mult(x, cnt[0][i], MOD - 1);
        proddiv = mult(proddiv, power(fac[i].f, x));
    }
    cout << numdiv << ' ' << sumdiv << ' ' << proddiv;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}