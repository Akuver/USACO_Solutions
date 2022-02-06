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
    map<pair<ll, char>, ll> m;
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, vector<pair<ll, ll> > > res;
    map<char, ll> freq;
    s.pb('{');
    n++;
    rep(i, 0, 26)
    {
        char c = char('a' + i);
        ll st = 0, len = 0;
        rep(j, 0, n)
        {
            if (s[j] != c && len)
                res[c].pb({st, st + len - 1}), len = 0;
            else if (s[j] == c && !len)
                st = j, len = 1;
            else if (s[j] == c && len)
                len++;
        }
    }
    n--;
    s.pop_back();
    rep(i, 0, n) freq[s[i]]++;
    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        char c;
        cin >> x >> c;
        if (m[{x, c}])
        {
            cout << m[{x, c}] << "\n";
            continue;
        }
        if (x >= n - freq[c])
        {
            cout << n << "\n";
            continue;
        }
        if (!freq[c])
        {
            cout << x << "\n";
            continue;
        }
        ll best = 0, sub = 1;
        vector<pair<ll, ll> > v = res[c];
        while (sub <= v.size())
        {
            ll left = x, ans = v[v.size() - sub].s - v[v.size() - sub].f + 1;
            for (ll i = v.size() - sub; i > 0; i--)
            {
                ll gap = v[i].f - v[i - 1].s - 1;
                if (gap <= left)
                    left -= gap, ans += (v[i - 1].s - v[i - 1].f + 1 + gap);
                else
                {
                    ans += left, left = 0;
                    break;
                }
            }
            if (left)
            {
                ll l1 = v[0].f, l2 = ((sub != 1) ? v[v.size() - sub + 1].f : (n - 1)) - v[v.size() - sub].s;
                ll y = min(l1, left);
                ans += y;
                left -= y;
                y = min(l2, left);
                ans += y, left -= y;
            }
            sub++;
            best = max(best, ans);
        }
        m[{x, c}] = best;
        cout << best << "\n";
    }
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}