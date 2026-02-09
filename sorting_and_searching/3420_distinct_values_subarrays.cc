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
  unordered_map<ll, ll, custom_hash> last;
  ll ans{};
  for (ll l{}, r{}; r < n; ++r) {
    ll x;
    cin >> x;
    auto it = last.find(x);
    if (it != last.end() && l <= it->second) {
      l = it->second + 1;
    }
    last[x] = r;
    ans += r - l + 1;
  }
  cout << ans << '\n';
}
