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

    ll n;
    cin >> n;
    map<string, ll> m;
    m["Bessie"] = m["Elsie"] = m["Daisy"] = m["Gertie"] = m["Annabelle"] = m["Maggie"] = m["Henrietta"] = 0;
    rep(i, 0, n)
    {
        string s;
        ll x;
        cin >> s >> x;
        m[s] += x;
    }
    vector<ll> val;
    for (auto i : m)
        val.pb(i.s);
    sortv(val);
    ll mini = val[0], cnt = 0;
    for (auto i : val)
        if (i > mini)
        {
            mini = i;
            break;
        }
    for (auto i : val)
        if (i == mini)
            cnt++;
    if (cnt != 1)
    {
        cout << "Tie\n";
        return;
    }
    for (auto i : m)
    {
        if (i.s == mini)
            cout << i.f << "\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}