#include <bits/stdc++.h>

using namespace std;

int main() {
  int t=1;
//   cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int &x : a) scanf("%d", &x);
    for (int &x : b) scanf("%d", &x);
    int m;
    cin >> m;
    vector <int> d(m);
    for (int &x : d) scanf("%d", &x);
    map <int, int> has, need;
    for (int &x : d) ++has[x];
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) ++need[b[i]];
    }
    bool okay = true;
    for (auto [key, value] : need) {
      if (has[key] < value) {
        okay = false;
        break;
      }
    }
    if (find(b.begin(), b.end(), d.back()) == b.end()) {
      okay = false;
    }
    puts(okay ? "YES" : "NO");
  }
  return 0;
}

