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
  string pre, mid;
  for (ll i{}; i < 26; ++i) {
    pre.append(freq[i] / 2, i + 'A');
    mid.append(freq[i] % 2, i + 'A');
  }
  if (mid.size() > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  string post{pre};
  reverse(post.begin(), post.end());
  cout << pre << mid << post << '\n';
}
