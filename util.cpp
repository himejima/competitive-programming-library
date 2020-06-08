
// 最大公約数
ll gcd(ll a, ll b) { 
    return b ? gcd(b, a%b) : a;
}

// 最小公倍数
ll lcm(ll a, ll b) { 
    return a / gcd(a, b) * b;
}

// 素数判定
bool isPrime(int x){
    int i;
    if(x < 2)return 0;
    else if(x == 2) return 1;
    if(x%2 == 0) return 0;
    for(i = 3; i*i <= x; i += 2) if(x%i == 0) return 0;
    return 1;
}

// 約数全列挙
vector<int> enum_div(int n){
    vector<int> ret;
    for(int i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
            if(i != 1 && i*i != n){
                ret.push_back(n/i);
            }
        }
    }
    return ret;
}

// 繰り返し2乗法
// xのn乗%modを計算
long long int mod_pow(long long int x, long long int n, long long int mod){
    long long int res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}

