#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define lb(x, y) lower_bound(all(x), y) - begin(x)
#define ub(x, y) upper_bound(all(x), y) - begin(x)
#define init(a, n)           \
  for (ll i = 0; i < n; i++) \
  {                          \
    cin >> a[i];             \
  }
#define M_PI 3.14159265358979323846
const int M = 1e9 + 7;
using namespace std;

void solve()
{
  ll n;
  cin >> n;
  ll a[n], b[n], ans[n];
  init(a, n);
  init(b, n);
  set<ll> st;
  ll p = 0, q = n - 1;

  while (p <= q)
  {
    ll mini1 = LLONG_MAX, mini2 = LLONG_MAX;
    ll a1 = -1, b1 = -1;

    for (ll i = 0; i < n; i++)
    {
      if (st.find(i) != st.end())
        continue;
      if (a[i] < mini1)
      {
        mini1 = a[i];
        a1 = i;
      }
    }

    for (ll i = 0; i < n; i++)
    {
      if (st.find(i) != st.end())
        continue;
      if (b[i] < mini2)
      {
        mini2 = b[i];
        b1 = i;
      }
    }

    if (mini1 <= mini2)
    {
      st.insert(a1);
      ans[p] = a1 + 1;
      p++;
    }
    else
    {
      st.insert(b1);
      ans[q] = b1 + 1;
      q--;
    }
  }

  for (ll i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}