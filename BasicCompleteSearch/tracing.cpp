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
bool cow_ends_infected[101];
ll N, cowx[251], cowy[251];
bool consistent_with_data(ll patient_zero, ll K)
{
    bool infected[101] = {false};
    ll num_handshakes[101] = {0};
    infected[patient_zero] = true;
    rep(t, 0, 251)
    {
        ll x = cowx[t], y = cowy[t];
        if (x)
        {
            if (infected[x])
                num_handshakes[x]++;
            if (infected[y])
                num_handshakes[y]++;
            if (num_handshakes[x] <= K && infected[x])
                infected[y] = true;
            if (num_handshakes[y] <= K && infected[y])
                infected[x] = true;
        }
    }
    rep(i, 1, N + 1) if (infected[i] != cow_ends_infected[i]) return false;
    return true;
}

void solve(ll tcase)
{
    ll T, t, x, y;
    string s;

    cin >> N >> T >> s;
    rep(i, 1, N + 1)
        cow_ends_infected[i] = s[i - 1] == '1';
    rep(i, 0, T)
    {
        cin >> t >> x >> y;
        cowx[t] = x;
        cowy[t] = y;
    }

    bool possible_i[101] = {false};
    bool possible_K[252] = {false};
    rep(i, 1, N + 1) rep(K, 0, 252) if (consistent_with_data(i, K))
    {
        possible_i[i] = true;
        possible_K[K] = true;
    }

    ll lower_K = 251, upper_K = 0, num_patient_zero = 0;
    rep(K, 0, 252) if (possible_K[K])
        upper_K = K;
    for (ll K = 251; K >= 0; K--)
        if (possible_K[K])
            lower_K = K;
    rep(i, 1, N + 1) if (possible_i[i])
        num_patient_zero++;

    cout << num_patient_zero << " " << lower_K << " ";
    if (upper_K == 251)
        cout << "Infinity\n";
    else
        cout << upper_K << "\n";
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}