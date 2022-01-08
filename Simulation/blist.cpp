#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define cd complex<double>
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define mp make_pair
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << "is" << x;
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
struct Cow
{
    ll s, t, b;
    Cow() {}
    Cow(ll s, ll t, ll b)
    {
        this->s = s;
        this->t = t;
        this->b = b;
    }
};
void solve(ll tcase)
{
    ll n, buckets = 0, max_time = 0;
    cin >> n;
    Cow cows[n];
    rep(i, 0, n)
    {
        ll s, t, b;
        cin >> s >> t >> b;
        cows[i] = Cow(s, t, b);
        max_time = max(max_time, t);
    }
    rep(time, 1, max_time + 1)
    {
        ll need = 0;
        rep(i, 0, n)
        {
            if (cows[i].s <= time && cows[i].t >= time)
                need += cows[i].b;
        }
        buckets = max(buckets, need);
    }
    cout << buckets;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}