//
// 幾何の基本処理詰め合わせ 
//
// verified
// [B - アリの高橋くん](https://atcoder.jp/contests/arc042/tasks/arc042_b)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

using namespace std;

typedef long long ll;
const int INF = 1e8;
// const ll INF = 1LL << 60;
typedef pair<int, int> P;

class Point {
    public:
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator == (const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

struct Segment {
    Point p1, p2;
};

typedef Point Vector;
typedef Segment Line;

double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}
 
double norm(Vector a) {
    return a.x * a.x + a.y * a.y;
}

double abs(Vector a) {
    return sqrt(norm(a));
}
 
static const int COUNTER_CLOCK_WISE = 1;
static const int CLOCK_WISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if (cross(a, b) > EPS) return COUNTER_CLOCK_WISE;
    if (cross(a, b) < -EPS) return CLOCK_WISE;
    if (dot(a, b) < -EPS) return ONLINE_BACK;
    if (a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistanceLP(Line l, Point p) {
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}

double getDistance(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
        min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
 

int main() {
    ll x, y, N;
    cin >> x >> y >> N;
    Point p(x, y);

    vector<P> v;
    v.resize(N);
    rep(i, N) {
        ll x0, y0;
        cin >> x0 >> y0;
        v[i] = P(x0, y0);
        // Segment s1 = {Point(x0, y0), Point(x1, y1)};
        // Segment s2 = {Point(x2, y2), Point(x3, y3)};
        // printf("%.10f\n", getDistance(s1, p));
    }

    double ans = (double)INT_MAX;
    rep(i, N) {
        int next_idx = i + 1; 
        if (next_idx >= N) next_idx = 0;
        Segment s = {Point(v[i].first, v[i].second), Point(v[next_idx].first, v[next_idx].second)};
        ans = min(ans, getDistanceSP(s, p));
    }

    printf("%.10f\n", ans);
}