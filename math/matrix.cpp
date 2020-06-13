//
// 行列累乗
// 参考: [algorithm/matrix.cpp at master · drken1215/algorithm](https://github.com/drken1215/algorithm/blob/master/MathAlgebra/matrix.cpp)
// 
// 計算量: O(?) 
// 
// verified
// [No.526 フィボナッチ数列の第N項をMで割った余りを求める - yukicoder](https://yukicoder.me/problems/no/526)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

// matrix
template<class T> struct Matrix {
    vector<vector<T> > val;
    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)) {}
    void init(int n, int m, T v = 0) {val.assign(n, vector<T>(m, v));}
    void resize(int n, int m) {
        val.resize(n);
        for (int i = 0; i < n; ++i) val[i].resize(m);
    }
    Matrix<T>& operator = (const Matrix<T> &A) {
        val = A.val;
        return *this;
    }
    size_t size() const {return val.size();}
    vector<T>& operator [] (int i) {return val[i];}
    const vector<T>& operator [] (int i) const {return val[i];}
    friend ostream& operator << (ostream& s, const Matrix<T>& M) {
        s << endl;
        for (int i = 0; i < (int)M.size(); ++i) s << M[i] << endl;
        return s;
    }
};

template<class T> Matrix<T> operator * (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), B[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < B[0].size(); ++j)
            for (int k = 0; k < B.size(); ++k)
                R[i][j] += A[i][k] * B[k][j];
    return R;
}

template<class T> Matrix<T> pow(const Matrix<T> &A, long long n) {
    Matrix<T> R(A.size(), A.size());
    auto B = A;
    for (int i = 0; i < A.size(); ++i) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * B;
        B = B * B;
        n >>= 1;
    }
    return R;
}

template<class T> vector<T> operator * (const Matrix<T> &A, const vector<T> &B) {
    vector<T> v(A.size());
    for (int i = 0; i < A.size(); ++i)
        for (int k = 0; k < B.size(); ++k)
            v[i] += A[i][k] * B[k];
    return v;
}

template<class T> Matrix<T> operator + (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), A[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
            R[i][j] = A[i][j] + B[i][j];
    return R;
}

template<class T> Matrix<T> operator - (const Matrix<T> &A, const Matrix<T> &B) {
    Matrix<T> R(A.size(), A[0].size());
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[0].size(); ++j)
            R[i][j] = A[i][j] - B[i][j];
    return R;
}


ll N, MOD;
// modint
struct Fp {
    long long val;
    Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    int getmod() { return MOD; }
    Fp operator - () const {
        return val ? MOD - val : 0;
    }
    Fp operator + (const Fp& r) const { return Fp(*this) += r; }
    Fp operator - (const Fp& r) const { return Fp(*this) -= r; }
    Fp operator * (const Fp& r) const { return Fp(*this) *= r; }
    Fp operator / (const Fp& r) const { return Fp(*this) /= r; }
    Fp& operator += (const Fp& r) {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Fp& operator -= (const Fp& r) {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    Fp& operator *= (const Fp& r) {
        val = val * r.val % MOD;
        return *this;
    }
    Fp& operator /= (const Fp& r) {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    bool operator == (const Fp& r) const {
        return this->val == r.val;
    }
    bool operator != (const Fp& r) const {
        return this->val != r.val;
    }
    // エラーが出るのでコメントアウト
    // ostream& operator << (ostream &os, const Fp& x) {
    //     return os << x.val;
    // }
    Fp modpow(const Fp &a, long long n) {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

// const int MOD = 1000000007;

int main() {
    cin >> N >> MOD;

    Matrix<Fp> A(2, 2, 1);
    A[1][1] = 0;

    A = pow(A, N - 1);
    
    cout << A[1][0].val << endl;
    // rep(i, 2) {
    //     rep(j, 2) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}