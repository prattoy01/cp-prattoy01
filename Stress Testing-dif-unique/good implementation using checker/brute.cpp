#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res % MOD;
}

/*
 * If sort(A)  = [1, 3, 5, 8]
 * Then MSB(A) = [0, 2, 3, 3]
 * Hence, we can multiply A by [2^(3 - 0), 2^(3 - 2), 2^(3 - 3), 2^(3 - 3)]
 * To get      = [8, 6, 5, 8]
 * Now every A_i is set till MSB = 3
 * If still K remains, 
 * Then we can count extra number of times that we need to multiply a[i].second by 2 
 * Via a[i].first
 * 
 * Continuing with example, maxDiff = 3 + 1 + 0 + 0 = 4
 * If K = 9
 * Then after getting [8, 6, 5, 8] and remaining K = 5
 * We can multiply by (K / N) = (5 / 4) number of times with 2
 * To get [{1, 8}, {1, 6}, {1, 5}, {1, 8}] to represent [16, 12, 10, 16] with MSB = 4 set
 * We can multiply now smallest (K % N) = (1 % 4) = 1 numbers with 2
 * To get [{1, 8}, {1, 6}, {2, 5}, {1, 8}]
 */
int main() {
    ll T=1;
    // cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector < ll > A(N);
        vector < pair < ll, ll >> a;
        for (auto & A_i: A) {
            cin >> A_i;
            a.push_back({
                0,
                A_i
            });
        }

        sort(begin(a), end(a));

        ll maxDiff = 0;
        for (int i = 0; i < (N - 1); i += 1)
            maxDiff += floor(log2(a[N - 1].second)) - floor(log2(a[i].second));

        if (maxDiff > K) {
            int i = 1;
            ll sumTillNow = 0;
            while (i < N) {
                ll diff = floor(log2(a[i].second)) - floor(log2(a[i - 1].second));
                if (sumTillNow + (diff * i) > K)
                    break;
                sumTillNow += diff * i;
                i += 1;
            }
            i -= 1;
            
            K -= sumTillNow;
            for (int j = 0; j <= i; j += 1) {
                ll diff = floor(log2(a[i].second)) - floor(log2(a[j].second)) + (K / (i + 1));
                a[j].second <<= diff;
            }
            K %= (i + 1);
            
            sort(begin(a), end(a));
            int k = 0;
            while (K) {
                a[k].second <<= 1;
                K -= 1;
                k += 1;
            }
        } else {
            K -= maxDiff;
            for (int i = 0; i < N; i += 1) {
                ll diff = floor(log2(a[N - 1].second)) - floor(log2(a[i].second));
                a[i].second <<= diff;
                a[i].first = (K / N);
            }
            K %= N;
            
            sort(begin(a), end(a));
            int k = 0;
            while (K) {
                a[k].first += 1;
                K -= 1;
                k += 1;
            }
        }

        ll sum = 0;
        for (int i = 0; i < N; i += 1) {
            ll p = power(2LL, a[i].first);
            ll num = (p * a[i].second) % MOD;
            sum = (sum + num) % MOD;
        }

        cout << sum << "\n";
    }
}