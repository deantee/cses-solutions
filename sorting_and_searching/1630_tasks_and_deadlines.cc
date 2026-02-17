#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans{};
  vector<ll> vec(n);
  for (ll& a : vec) {
    ll d{};
    cin >> a >> d;
    ans += d;
  }
  ll s{};
  sort(vec.begin(), vec.end());
  for (ll x : vec) {
    ans -= s += x;
  }
  cout << ans << '\n';
}
