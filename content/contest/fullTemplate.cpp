#include <bits/stdc++.h>
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define forsn(i, s, n) for (ll i = s; i < ll(n); i++)
#define dforn(i, n) for (ll i = ll(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (ll i = ll(n) - 1; i >= s; i--)
#define sz(x) ll(x.size())
#define all(x) x.begin(), x.end()
#define DBG(x) cerr << #x << " = " << x << endl
#define LINE cerr << "##########################" << endl

#define rep(i, a, b) for (ll i = a; i < ll(b); ++i)

using namespace std;
using ll = long long;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, sz(v)) {
    if (i > 0) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

inline void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

int main() { 
  fastIO(); 
  
}