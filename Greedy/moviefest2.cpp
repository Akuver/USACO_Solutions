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
vector<pair<ll, ll> > movie;
vector<ll> movId;
bool comp(ll a, ll b)
{
    if (movie[a].s == movie[b].s)
        return movie[a].f < movie[b].f;
    return movie[a].s < movie[b].s;
}
void solve(ll tcase)
{
    ll n, k, cnt = 0;
    cin >> n >> k;
    movie.resize(n);
    movId.resize(n);
    rep(i, 0, n)
    {
        cin >> movie[i].f >> movie[i].s;
        movId[i] = i;
    }
    sort(movId.begin(), movId.end(), comp);
    multiset<ll> person;
    ll left = k - 1;
    person.insert(0);
    rep(i, 0, n)
    {
        ll ind = movId[i];
        ll st = movie[ind].f, fin = movie[ind].s;
        if (*person.begin() > st)
        {
            if (left)
                person.insert(fin), left--, cnt++;
            continue;
        }
        auto it = person.upper_bound(st);
        it--;
        person.erase(it);
        person.insert(fin);
        cnt++;
    }
    cout << cnt;
}
int main()
{
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}