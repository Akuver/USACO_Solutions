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
set<ll> loc[2];
multiset<ll> len[2];
void op(ll i, ll x)
{
    auto it1 = loc[i].lower_bound(x);
    auto it2 = loc[i].upper_bound(x);
    if (*it1 >= x)
        it1--;
    len[!i].erase(len[!i].find(x - 1 - *it1));
    len[!i].erase(len[!i].find(*it2 - x - 1));
    len[!i].insert(*it2 - *it1 - 1);
    it1++;
    loc[i].erase(it1);
    it1 = loc[!i].lower_bound(x);
    if (*it1 > x)
        it1--;
    it2 = loc[!i].upper_bound(x);
    len[i].erase(len[i].find(*it2 - *it1 - 1));
    len[i].insert(x - *it1 - 1);
    len[i].insert(*it2 - x - 1);
    loc[!i].insert(x);
}
void solve(ll tcase)
{
    string s;
    cin >> s;
    ll m, n = s.size();
    cin >> m;
    rep(i, 0, n)
    {
        ll j = s[i] - '0';
        loc[j].insert(i);
    }
    loc[0].insert(-1);
    loc[1].insert(-1);
    loc[0].insert(n);
    loc[1].insert(n);
    rep(j, 0, 2)
    {
        ll prev = -1;
        for (auto i : loc[j])
        {
            len[!j].insert(i - prev - 1);
            prev = i;
        }
    }
    while (m--)
    {
        ll x;
        cin >> x;
        x--;
        ll c = s[x] - '0';
        op(c, x);
        s[x] = char('0' + !c);
        cout << max(*(--len[0].end()), *(--len[1].end())) << ' ';
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}