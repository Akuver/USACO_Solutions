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
    vector<array<ll, 3>> log;
    ll N;
    ll day, cow_id;
    string cow_str, change;

    cin >> N;
    log.reserve(N);

    while (N--)
    {
        cin >> day >> cow_str >> change;
        if (cow_str[0] == 'B')
            cow_id = 0;
        else if (cow_str[0] == 'E')
            cow_id = 1;
        else
            cow_id = 2;
        log.pb({day, cow_id, stoi(change)});
    }
    sortv(log);
    ll currmax = 7;
    array<ll, 3> cow = {7, 7, 7};
    array<bool, 3> display = {true, true, true};
    ll count = 0;

    for (auto entry : log)
    {

        array<bool, 3> display_copy = display;

        cow[entry[1]] += entry[2];
        currmax = *max_element(begin(cow), end(cow));

        display[0] = (cow[0] == currmax);
        display[1] = (cow[1] == currmax);
        display[2] = (cow[2] == currmax);

        if (display != display_copy)
            count++;
    }

    cout << count;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}