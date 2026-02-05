#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> vec(n + 2), idx(n + 2);
  vec[n + 1] = idx[n + 1] = n + 1;
  for (ll i{1}; i <= n; ++i) {
    cin >> vec[i];
    idx[vec[i]] = i;
  }
  ll ans{1};
  for (ll i{2}; i <= n; ++i) {
    if (idx[i] < idx[i - 1]) {
      ++ans;
    }
  }
  while (m--) {
    ll a, b;
    cin >> a >> b;
    vector<ll> tmp{vec[a], vec[a] + 1, vec[b], vec[b] + 1};
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (ll x : tmp) {
      if (idx[x] < idx[x - 1]) {
        --ans;
      }
    }
    swap(idx[vec[a]], idx[vec[b]]);
    swap(vec[a], vec[b]);
    for (ll x : tmp) {
      if (idx[x] < idx[x - 1]) {
        ++ans;
      }
    }
    cout << ans << '\n';
  }
}
