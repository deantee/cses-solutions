#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  multiset<ll> st;
  while (n--) {
    ll x;
    cin >> x;
    st.insert(x);
  }
  while (m--) {
    ll x;
    cin >> x;
    auto it = st.upper_bound(x);
    if (it == st.begin()) {
      cout << "-1\n";
      continue;
    }
    --it;
    cout << *it << '\n';
    st.erase(it);
  }
}
