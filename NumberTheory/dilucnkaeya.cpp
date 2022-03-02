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
ll gcd(ll a, ll b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}
void solve(ll tcase)
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> cntD(n, 0), cntK(n, 0);
    rep(i, 0, n)
    {
        if (i)
            cntD[i] = cntD[i - 1], cntK[i] = cntK[i - 1];
        if (s[i] == 'D')
            cntD[i]++;
        else
            cntK[i]++;
    }
    vector<ll> ans(n, 0);
    map<pair<ll, ll>, ll> before;
    rep(i, 0, n)
    {
        ll g = gcd(cntD[i], cntK[i]);
        ll a = cntD[i] / g, b = cntK[i] / g;
        ans[i] = before[{a, b}] + 1;
        before[{a, b}]++;
    }
    for (auto i : ans)
        cout << i << ' ';
    cout << "\n";
}
int main()
{
    speed;
    ll t = 1;
    cin >> t;
    rep(i, 1, t + 1)
        solve(i);
}