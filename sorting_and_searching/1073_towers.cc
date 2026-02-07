#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec;
  vec.reserve(n);
  while (n--) {
    ll x;
    cin >> x;
    auto it = upper_bound(vec.begin(), vec.end(), x);
    if (it != vec.end()) {
      *it = x;
    } else {
      vec.emplace_back(x);
    }
  }
  cout << vec.size() << '\n';
}
