#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) {
	os << '{';
	string sep;
	for (const T &x : v) {
		os << sep << x;
		sep = ", ";
	}
	return os << '}';
}

// ramen probably should remove __FILE__ and __LINE__
#ifdef ONPC
	void dbg_out() { cerr << endl; }
	template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#else
	void dbg_out() { }
	template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { }
#endif

// sonechka
#define vt vector
typedef long double ld;
bool debug = false;
const ld eps = 1e-9;
void whattime() { cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl; }
const int mod = 1e9 + 7;

// pragmas
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt"

// thatsramen
#define eb emplace_back
#define pb push_back
#define ft first
#define sd second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(...) dbg_out(__VA_ARGS__)

using ll = long long;
using ld = long double;
using namespace std;
using namespace __gnu_pbds;
 
//Constants
const ll INF = 5 * 1e18;
const int IINF = 2 * 1e9;
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ld PI = 3.14159265359;

template<typename T> bool mins(T& x, T y) { if (x > y) { x = y; return true; } return false; }
template<typename T> bool maxs(T& x, T y) { if (x < y) { x = y; return true; } return false; }
template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
//order_of_key(k): number of elements strictly less than k
//find_by_order(k): k-th element in the set
 
void setPrec() {cout << fixed << setprecision(15);}
void unsyncIO() {cin.tie(0)->sync_with_stdio(0);}
void setIn(string s) {freopen(s.c_str(), "r", stdin);}
void setOut(string s) {freopen(s.c_str(), "w", stdout);}
void setIO(string s = "") {
	unsyncIO(); setPrec();
	if(s.size()) setIn(s + ".in"), setOut(s + ".out");
}

#define TEST_CASES

void solve() {
}

int main() {
//	cin.tie(0)->sync_with_stdio(0);
	setIO();
 
	int tt = 1;
#ifdef TEST_CASES
	cin >> tt;
#endif
 
	while (tt--)
		solve();
 
	return 0;
}