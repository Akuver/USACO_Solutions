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
const ll N = 2e7 + 5;
vector<ll> prime(N), divs(N);
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
    for (ll i = 2; i < N; i++)
    {
        ll j = i / prime[i];
        divs[i] += divs[j] + (prime[i] != prime[j]);
    }
}
void solve(ll tcase)
{
    ll c, d, x, ans = 0;
    cin >> c >> d >> x;
    for (ll g = 1; g * g <= x; g++)
    {
        if (x % g)
            continue;
        ll num = x / g + d;
        if (num % c == 0)
            ans += 1LL << divs[num / c];
        if (g * g == x)
            continue;
        num = g + d;
        if (num % c == 0)
            ans += 1LL << divs[num / c];
    }
    cout << ans << "\n";
}
int main()
{
    speed;
    ll t = 1;
    sieve();
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}