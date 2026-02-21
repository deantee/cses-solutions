#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (ll& x : vec) {
    cin >> x;
  }
  vector<ll> stk;
  stk.reserve(n);
  for (ll i{}; i < n; ++i) {
    while (!stk.empty() && vec[stk.back()] >= vec[i]) {
      stk.pop_back();
    }
    cout << (stk.empty() ? 0 : stk.back() + 1) << (i + 1 < n ? ' ' : '\n');
    stk.emplace_back(i);
  }
}
