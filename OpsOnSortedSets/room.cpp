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
vector<pair<ll, ll> > a;
bool comp(ll i, ll j)
{
    if (a[i].f == a[j].f)
        return a[i].s < a[j].s;
    return a[i].f < a[j].f;
}
void solve(ll tcase)
{
    ll n;
    cin >> n;
    ll id[n], ans[n];
    rep(i, 0, n)
    {
        ll x, y;
        cin >> x >> y;
        a.pb({x, y});
        id[i] = i;
    }
    sort(id, id + n, comp);
    multiset<pair<ll, ll> > done;
    ll rooms = 0;
    rep(i, 0, n)
    {
        if (done.empty())
        {
            rooms++;
            ans[id[i]] = rooms;
            done.insert({a[id[i]].s, ans[id[i]]});
        }
        else
        {
            auto it = *done.begin();
            if (it.f < a[id[i]].f)
            {
                ans[id[i]] = it.s;
                done.erase(done.begin());
                done.insert({a[id[i]].s, it.s});
            }
            else
            {
                rooms++;
                ans[id[i]] = rooms;
                done.insert({a[id[i]].s, ans[id[i]]});
            }
        }
    }
    cout << rooms << "\n";
    rep(i, 0, n) cout << ans[i] << ' ';
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}