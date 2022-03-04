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
ll add(ll a, ll b, ll mod = MOD)
{
    a %= mod, b %= mod;
    a += b;
    a %= mod;
    return a;
}
ll modInverse(ll x, ll mod = MOD)
{
    return power(x, mod - 2, mod);
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    map<ll, ll> cntchild;   // cntchild[i]= cnt. of children who want item i
    map<ll, vector<ll> > K; //  K[i]= all k's with item i
    rep(i, 0, n)
    {
        ll k;
        cin >> k;
        rep(j, 0, k)
        {
            ll a;
            cin >> a;
            cntchild[a]++;
            K[a].pb(k);
        }
    }
    ll max_item = 1e6;
    ll x = 0, y = modInverse(power(n, 2, MODA), MODA);
    rep(i, 1, max_item + 1)
    {
        if (!cntchild[i])
            continue;
        ll res = cntchild[i], res1 = 0;
        for (auto j : K[i])
            res1 = add(res1, modInverse(j, MODA), MODA);
        res = mult(res, res1, MODA);
        x = add(x, res, MODA);
    }
    x = mult(x, y, MODA);
    cout << x;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}