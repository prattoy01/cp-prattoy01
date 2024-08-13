#include <bits/stdc++.h>
using namespace std;

// datatypes:
#define     ll       long long int
// #define int long long int
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
const int N = 100005;


struct PrefSum2D
{

	std::vector<vector<int>> prefix;

	//building 2d prefix sum
	PrefSum2D(int r, int c) {
		prefix.resize(r + 1);
		for (int i = 0; i <= r; i++) {
			prefix[i].resize(c + 1, 0);
		}
	}
	//adding new value
	void pref(int x, int y, int val) {
		prefix[x][y] = prefix[x - 1][y] + prefix[x][y - 1] - prefix[x - 1][y - 1] + val;
	}
	//getting sum
	int sum(int x, int y, int x1, int y1) {
		return  prefix[x1][y1] - prefix[x - 1][y1] - prefix[x1][y - 1] + prefix[x - 1][y - 1];
	}
};

int32_t main()
{
	faster

	int n = 3, m = 3;
	cin >> n >> m;

	PrefSum2D psum2d(n, m);
	psum2d.pref(1, 1, 5);
	psum2d.pref(1, 2, 5);
	psum2d.pref(1, 3, 5);
	psum2d.pref(2, 1, 5);
	psum2d.pref(2, 2, 5);
	psum2d.pref(2, 3, 5);
	psum2d.pref(3, 1, 5);
	psum2d.pref(3, 2, 5);
	psum2d.pref(3, 3, 5);
	cout << psum2d.sum(1, 1, 1, 3);


}