#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fill(x, y) memset(x, y, sizeof(x))
#define manytests int TT;cin >> TT; while (TT--)
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORd(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,a,b,c) for (int i = (a); i < (b); i += (c))
#define REPd(i,a,b,c) for (int i = (a); i >= (b); i -= (c))
 
#define ll long long
#define ld long double
#define str string
#define fi first
#define se second
#define rev reverse
 
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int INF = 1e9;
ll INFI = 1e18;
double PI = atan(1) * 4;
double eps = 1e-9;
const int MOD = 1e9+7;
// const int MOD = 998244353;
 
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vd vector<double>
#define vs vector<string>
#define vld vector<ld>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pl pair<ll, ll>
#define pld pair<ld, ld>
#define vpi vector<pii>
#define vpl vector<pl>
#define vpld vector<pld>
#define vmi vector<mint>
#define pmi pair<mint, mint>
 
template<class T> bool ckmin(T &a, const T &b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T &b) { return (a < b ? a = b, 1 : 0); }
 
#define dbg(var) { cerr << #var << ": " << var << "\n"; }
 
template<class T, class U> istream& operator>>(istream& in, pair<T, U> &x) { in >> x.fi >> x.se; return in; }
template<class T> istream& operator>>(istream& in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
 
template<class T, class U> ostream& operator<<(ostream& out, const pair<T, U> &x) { out << "(" << x.fi << ", " << x.se << ")"; return out; }
template<class T> ostream& operator<<(ostream& out, const vector<T> &v) { FOR(i,0,sz(v)) out << v[i] << " \n"[i == sz(v) - 1]; return out; }
 
inline namespace FileIO {
  void setIn(str s) { freopen(s.c_str(), "r", stdin); }
	void setOut(str s) { freopen(s.c_str(), "w", stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0);
		if (sz(s)) setIn(s+".in"), setOut(s+".out");
	}
}

struct mint {
  int v; explicit operator int() const { return v; }
  mint(): v(0) {}
  mint(ll _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) v += MOD;
  }
  bool operator==(const mint& o) const { return v == o.v; }
	friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }

	mint& operator+=(const mint& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
	mint& operator-=(const mint& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
	mint& operator*=(const mint& o) { v = int((ll)v * o.v % MOD); return *this; }
	mint& operator/=(const mint& o) { return (*this) *= inv(o); }
	mint& operator^=(const mint& o) { return (*this) = pow(v, o.v); }
	
	mint& operator+=(const int& o) { if ((v += mint(o).v) >= MOD) v -= MOD; return *this; }
	mint& operator-=(const int& o) { if ((v -= mint(o).v) < 0) v += MOD; return *this; }
	mint& operator*=(const int& o) { v = int((ll)v * mint(o).v % MOD); return *this; }
	mint& operator/=(const int& o) { return (*this) *= inv(mint(o)); }
	mint& operator^=(const int& o) { return (*this) = pow(v, o); }
	
	friend mint pow(mint a, ll p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
  }
	friend mint inv(const mint& a) { assert(a.v != 0); return pow(a,MOD-2); }

	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	
  friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
	friend mint operator^(mint a, const mint& b) { return a ^= b; }
	
	friend mint operator+(mint a, const int& b) { return a += mint(b); }
	friend mint operator-(mint a, const int& b) { return a -= mint(b); }
	friend mint operator*(mint a, const int& b) { return a *= mint(b); }
	friend mint operator/(mint a, const int& b) { return a /= mint(b); }
	friend mint operator^(mint a, const int& b) { return a ^= mint(b); }

	friend istream& operator>>(istream& in, mint& mi) { in >> mi.v; return in; }
	friend ostream& operator<<(ostream& os, const mint& mi) { os << mi.v; return os; }
};

int n;
vi d;

int memo[1<<20];

int dp(int mask) {
  if (mask == 0) {
    return memo[mask] = 0;
  }
  if (memo[mask] != -1) return memo[mask];
  int ans = INF;
  FOR(i,0,n) {
    int nmask = mask;
    FOR(j,0,3) {
      if ((mask >> ((i + j) % n)) & 1) {
        nmask -= (1 << ((i + j) % n));
      }
    }
    if (nmask != mask) {
      ckmin(ans, dp(nmask) + d[nmask]);
    }
  }
  return memo[mask] = ans;
}

int main() {
  setIO();

  cin >> n;
  vi a(n); cin >> a;
  memset(memo, -1, sizeof(memo));
  d.resize(1<<n);
  FOR(i,0,1<<n) {
    int sm = 0;
    FOR(j,0,n) {
      if (i>>j&1) {
        sm += a[j];
      }
    }
    d[i] = sm;
  }
  cout << dp((1<<n)-1) << "\n";

  return 0;
}