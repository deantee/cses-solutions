#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (auto& row : grid) {
    cin >> row;
  }
  for (ll i{}; i < n; ++i) {
    for (ll j{}; j < m; ++j) {
      for (ll k{(i + j) & 1}; k < 4; k += 2) {
        char ch(k + 'A');
        if (grid[i][j] == ch) {
          continue;
        }
        cout << ch;
        break;
      }
    }
    cout << '\n';
  }
}
