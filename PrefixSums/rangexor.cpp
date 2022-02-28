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
ll Xor(ll a, ll b)
{
    return a ^ b;
}
void solve(ll tcase)
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), prefix(n, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
        prefix[i] = Xor((i - 1 >= 0) ? prefix[i - 1] : 0LL, a[i]);
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << Xor(prefix[r], (l - 1 >= 0) ? prefix[l - 1] : 0LL) << "\n";
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}