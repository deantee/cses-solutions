#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  array<ll, 26> freq{};
  for (char ch : str) {
    ++freq[ch - 'A'];
  }
  ll n(str.size());
  if (*max_element(freq.begin(), freq.end()) * 2 > n + 1) {
    cout << "-1\n";
    return 0;
  }
  for (ll i{}, last{}; i < n; ++i) {
    for (ll j{}; j < 26; ++j) {
      if (freq[j] == 0) {
        continue;
      }
      if (i > 0 && last == j) {
        continue;
      }
      --freq[j];
      if (*max_element(freq.begin(), freq.end()) * 2 > n - i) {
        ++freq[j];
        continue;
      }
      cout << char(j + 'A');
      last = j;
      break;
    }
  }
  cout << '\n';
}
