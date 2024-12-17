#include <bits/stdc++.h>

using namespace std;

bool touchingSegments(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    double m1, m2, b1, b2, xi, yi;
    if (x1 == x2) {
        m1 = numeric_limits<double>::max();
        b1 = 0;
    } else {
        m1 = static_cast<double>(y1 - y2) / (x1 - x2);
        b1 = -m1 * x2 + y2;
    }
    if (x3 == x4) {
        m2 = numeric_limits<double>::max();
        b2 = 0;
    } else {
        m2 = static_cast<double>(y3 - y4) / (x3 - x4);
        b2 = -m2 * x4 + y4;
    }

    if (m1 == m2) {
        if (m1 != numeric_limits<double>::max() && m2 != numeric_limits<double>::max())
            return b1 == b2 && ((x3 >= min(x1, x2) && x3 <= max(x1, x2)) || (x4 >= min(x1, x2) && x4 <= max(x1, x2)));
        else
            return x1 == x3 && ((y3 >= min(y1, y2) && y3 <= max(y1, y2)) || (y4 >= min(y1, y2) && y4 <= max(y1, y2)));
    } else {
        if (m1 != numeric_limits<double>::max() && m2 != numeric_limits<double>::max()) {
            xi = (b2 - b1) / (m1 - m2);
            yi = m1 * xi + b1;
            return (xi >= min(x1, x2) && xi <= max(x1, x2)) && (yi >= min(y1, y2) && yi <= max(y1, y2)) && (xi >= min(x3, x4) && xi <= max(x3, x4)) && (yi >= min(y3, y4) && yi <= max(y3, y4));
        } else {
            if (m1 == numeric_limits<double>::max()) {
                xi = x1;
                yi = m2 * xi + b2;
            } else {
                xi = x3;
                yi = m1 * xi + b1;
            }
            return (xi >= min(x1, x2) && xi <= max(x1, x2)) && (yi >= min(y1, y2) && yi <= max(y1, y2)) && (xi >= min(x3, x4) && xi <= max(x3, x4)) && (yi >= min(y3, y4) && yi <= max(y3, y4));
        }
    }
}

int main() {
    int xr, yr, xj, yj;
    int n, corners;
    int x0, y0, x1, y1, x2, y2;
    bool touching;
    int touch = 0;
    cin >> xr >> yr >> xj >> yj;
    cin >> n;
    for (int i = 0; i < n; i++) {
        touching = false;
        cin >> corners;
        cin >> x0 >> y0;
        x1 = x0;
        y1 = y0;
        for (int j = 1; j < corners; j++) {
            cin >> x2 >> y2;
            touching = touching || touchingSegments(xr, yr, xj, yj, x1, y1, x2, y2);
            x1 = x2;
            y1 = y2;
        }
        touching = touching || touchingSegments(xr, yr, xj, yj, x1, y1, x0, y0);
        if (touching)
            touch++;
    }
    cout << touch << endl;
    return 0;
}