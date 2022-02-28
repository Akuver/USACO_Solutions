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
const ll N = 1e6 + 5;
vector<ll> prime(N);
void sieve()
{
    rep(i, 0, N) prime[i] = i;
    for (ll i = 4; i < N; i += 2)
        prime[i] = 2;
    for (ll i = 3; i * i < N; i += 2)
    {
        if (prime[i] == i)
            for (ll j = i * i; j < N; j += i)
                if (prime[j] == j)
                    prime[j] = i;
    }
}
vector<ll> factor(ll N)
{
    vector<ll> fac;
    while (N != 1)
    {
        fac.pb(prime[N]);
        N /= prime[N];
    }

    return fac;
}
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
void solve(ll tcase)
{
    ll n, ans = 1;
    cin >> n;
    map<ll, vector<ll> > exponents;
    exponents[1].pb(1);
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        if (x == 1)
            continue;
        vector<ll> fac = factor(x);
        map<ll, ll> freq;
        for (auto i : fac)
            freq[i]++;
        for (auto i : freq)
            exponents[i.f].pb(i.s);
    }
    for (auto &i : exponents)
    {
        sortv(i.s);
        ll x = i.s.size();
        if (x <= n - 2)
            continue;
        if (x == n - 1)
            ans *= power(i.f, i.s[0]);
        else
            ans *= power(i.f, i.s[1]);
    }
    cout << ans;
}
int main()
{
    speed;
    sieve();
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}