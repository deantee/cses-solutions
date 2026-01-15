#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string str;
  cin >> str;
  vector<string> ans;
  sort(str.begin(), str.end());
  do {
    ans.emplace_back(str);
  } while (next_permutation(str.begin(), str.end()));
  cout << ans.size() << '\n';
  for (auto& s : ans) {
    cout << s << '\n';
  }
}
