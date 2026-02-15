#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<tuple<ll, ll, ll>> vec(n);
  for (ll i{}; i < n; ++i) {
    auto& [l, r, j] = vec[i];
    cin >> l >> r;
    j = i;
  }
  sort(vec.begin(), vec.end());
  ll m{};
  set<pair<ll, ll>> st;
  vector<ll> ans(n);
  for (auto& [l, r, i] : vec) {
    auto it = st.lower_bound({l, 0});
    if (it != st.begin()) {
      --it;
      ans[i] = it->second;
      st.erase(it);
    } else {
      ans[i] = ++m;
    }
    st.emplace(r, ans[i]);
  }
  cout << m << '\n';
  for (ll i{}; i < n; ++i) {
    cout << ans[i] << (i + 1 < n ? ' ' : '\n');
  }
}
