#include <bits/stdc++.h>
using namespace std;

// datatypes:
// #define     ll                   long long int
#define int long long int
#define ull unsigned long long int
#define int128 __int128_t

// I/O:
#define pb push_back
#define eb emplace_back
#define pp pop_back

#define sin insert
#define all(x) x.begin(), x.end()
#define amhie const

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

// #define test_case

const int N = 100005, M = 1e9 + 7;

int step(int n, int m) {
    int cnt = 0;
    while (n <= m) {
        if ((n << 1) >= m) {
            if ((n << 1) == m) {
                cnt++;
                return cnt;
            }
            return cnt;
        }

        cnt++;
        n <<= 1;
    }
    return 0;
}



int power(int a, int b) {

    int ans = 1;
    while (b) {
        if (b & 1)ans = (a * ans) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}

void test(int tc)
{
    int n, k;
    cin >> n >> k;
    std::vector<int> v(n);
    for (auto &i : v)cin >> i;
    sort(all(v));
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += step(v[i], v[m]);
        }
        if (cnt <= k)l = m + 1;
        else r = m - 1;
    }
    int taken_step = 0;
    for (int i = 0; i < l - 1; i++) {
        int x = (step(v[i], v[l - 1]));
        taken_step += x;
        v[i] <<= x;
    }
    sort(all(v));
    // cout << (k - taken_step) % n << '\n';
    int xx = power(2, (k - taken_step) / n);
    int xx1 = (k - taken_step) % n;
    for (int i = 0; i < n; i++) {
        v[i] = (v[i] * xx) % M;
    }
    sort(all(v));
    for (int i = 0; i < xx1; i++) {
        v[i] = (v[i] * 2) % M;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (v[i] + ans) % M;
    }
    cout << ans << '\n';

}
int32_t main()
{
    faster

    int t = 1,
        tc = 0;

#ifdef test_case
    cin >> t;
#endif
    while (t--)
    {
        test(++tc);
    }
}