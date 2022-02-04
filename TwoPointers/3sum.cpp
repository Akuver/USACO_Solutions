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
ll a[5000];
bool comp(ll i, ll j)
{
    if (a[i] < a[j])
        return true;
    return false;
}
void solve(ll tcase)
{
    ll n, x;
    cin >> n >> x;
    ll id[n];
    rep(i, 0, n)
    {
        cin >> a[i];
        id[i] = i;
    }
    sort(id, id + n, comp);
    rep(i, 0, n)
    {
        ll sum = x - a[id[i]];
        ll left = 0, right = n - 1;
        while (left < right)
        {
            if (left == id[i])
                left++;
            if (right == id[i])
                right--;
            ll cur = a[id[left]] + a[id[right]];
            if (cur == sum)
            {
                if (id[left] != id[i] && id[right] != id[i] && id[left] != id[right])
                {
                    cout << id[i] + 1 << ' ' << id[left] + 1 << ' ' << id[right] + 1 << "\n";

                    return;
                }
                left++;
            }
            else if (cur < sum)
                left++;
            else
                right--;
        }
    }
    cout << "IMPOSSIBLE";
}
int main()
{

    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}