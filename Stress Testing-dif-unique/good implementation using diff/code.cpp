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

const int N = 100005;

void test(int tc)
{
  int n;
  cin >> n;
  multiset<int> mst, mst1;
  map<int, int> mp;
  vector<int> v(n), v1(n);
  for (int &i : v)
    cin >> i;
  for (int &i : v1)
    cin >> i, mp[i]++;

  int m;
  cin >> m;
  vector<int> ok;
  for (int i = 0; i < m; i++)
  {
    int x;
    cin >> x;
    ok.eb(x);
    mst.sin(x);
  }
  for (int i = 0; i < n; i++)
  {

    if (v[i] != v1[i]) {
      auto it = mst.find(v1[i]);

      if (it != mst.end())
      {
        mst.erase(it);
      }
      else
      {
        cout << "NO\n";
        return;
      }
    }

  }



  if (mp[ok.back()])cout << "YES\n";
  else cout << "NO\n";

  // cout << "YES\n";
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