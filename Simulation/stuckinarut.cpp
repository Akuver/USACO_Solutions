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

void solve(ll tcase)
{
    ll n;
    cin >> n;
    vector<array<ll, 3>> ncows, ecows;

    rep(i, 0, n)
    {
        string dir;
        int x, y;
        cin >> dir >> x >> y;
        if (dir == "N")
            ncows.pb({x, y, i});
        else
            ecows.pb({x, y, i});
    }
    sortv(ncows);
    sort(ecows.begin(), ecows.end(), [](auto &left, auto &right)
         { return left[1] < right[1]; });

    vector<ll> stop(n);
    rep(i, 0, n)
        stop[i] = -1;

    for (auto n_cow : ncows)
    {
        for (auto e_cow : ecows)
        {
            if (n_cow[0] > e_cow[0] && n_cow[1] < e_cow[1])
            {
                ll n_dist = e_cow[1] - n_cow[1];
                ll e_dist = n_cow[0] - e_cow[0];

                if (n_dist < e_dist && stop[e_cow[2]] == -1)
                    stop[e_cow[2]] = e_dist;

                else if (e_dist < n_dist && stop[e_cow[2]] == -1)
                {
                    stop[n_cow[2]] = n_dist;
                    break;
                }
            }
        }
    }

    rep(i, 0, n)
    {
        if (stop[i] == -1)
            cout << "Infinity" << '\n';
        else
            cout << stop[i] << '\n';
    }
}
int main()
{

    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}