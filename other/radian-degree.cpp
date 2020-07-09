#include <bits/stdc++.h>
using namespace std;

int main() {
    // degree -> radian
    double target_degree = 45;
    double radian = target_degree * M_PI / 180.0;
    printf("radian: %.10f\n", radian);

    // radian -> degree
    double degree = radian * 180.0 / M_PI;
    printf("degree: %.10f\n", degree);
}
