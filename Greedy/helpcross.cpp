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
bool comp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.s == b.s)
        return a.f < b.f;
    return a.s < b.s;
}
void solve(ll tcase)
{
    ll C, N, cnt = 0;
    cin >> C >> N;
    multiset<ll> T;
    pair<ll, ll> c[N];
    T.insert(-1);
    rep(i, 0, C)
    {
        ll x;
        cin >> x;
        T.insert(x);
    }
    rep(i, 0, N) cin >> c[i].f >> c[i].s;
    sort(c, c + N, comp);
    rep(i, 0, N)
    {
        ll a = c[i].f, b = c[i].s;
        auto it = T.upper_bound(a);
        it--;
        if (*it < a && it != T.end())
            it++;
        if (*it >= a && *it <= b)
        {
            cnt++;
            T.erase(it);
        }
    }
    cout << cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}