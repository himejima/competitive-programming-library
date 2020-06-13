// 未検証です。
//
// 最大公約数
// 最小公倍数
// 素数判定
// 約数列挙
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

// 最大公約数
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// 最小公倍数
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }

// 素数判定 
bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) return false;
    }
    return true;
}

// 約数全列挙
vector<ll> calc_divisor(ll n) {
    vector<ll> res;
    for (ll i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            ll j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
}