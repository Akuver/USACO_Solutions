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
    ll n, maxn = 0;
    cin >> n;
    vector<ll> freq(1000001, 0);
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        maxn = max(maxn, x);
        freq[x]++;
    }
    for (ll g = maxn; g >= 1; g--)
    {
        ll cnt = 0;
        for (ll i = g; i <= maxn; i += g)
        {
            cnt += freq[i];
            if (cnt >= 2)
            {
                cout << g;
                return;
            }
        }
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}