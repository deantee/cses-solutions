#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> pf(n + 1);
  for (ll i{1}; i <= n; ++i) {
    cin >> pf[i];
    pf[i] = (pf[i] % n + n + pf[i - 1]) % n;
  }
  unordered_map<ll, ll, custom_hash> mp;
  ll ans{};
  for (ll i{}; i <= n; ++i) {
    ans += mp[pf[i]];
    ++mp[pf[i]];
  }
  cout << ans << '\n';
}
