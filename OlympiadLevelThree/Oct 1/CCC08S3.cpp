#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define pii std::pair<int, int>
#define printi(a) printf("%d\n", a)
#define printii(a, b) printf("%d %d\n", a, b)
#define printiii(a, b, c) printf("%d %d %d\n", a, b, c)
#define scani(a) scanf(" %d", &a)
#define scanii(a, b) scanf(" %d %d", &a, &b)
#define scaniii(a, b, c) scanf(" %d %d %d", &a, &b, &c)
#define scannewi(a) \
    int a;          \
    scanf(" %d", &a)
#define scannewii(a, b) \
    int a, b;           \
    scanf(" %d %d", &a, &b)
#define scannewiii(a, b, c) \
    int a, b, c;            \
    scanf(" %d %d %d", &a, &b, &c)
#define fi(var, initial, max) for (int var = initial; var < max; ++var)
#define fd(var, initial, min) for (int var = initial; var > min; --var)
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define in(val, minval, maxval) (val >= minval && val <= maxval)

#define tb std::tuple<byte, byte, byte>
#define get(tup, i) std::get<i>(tup)

int main()
{
    scannewi(testcases);
    int w, h;
    bool visited[25][25];
    byte x, y;
    std::string map[25];
    bool found;
    char cur;
    fi(i, 0, testcases)
    {
        scanii(h, w);
        scanf("\n");
        fi(j, 0, h)
        {
            std::getline(std::cin, map[j]);
        }

        fi(y, 0, h)
        {
            fi(x, 0, w)
            {
                visited[y][x] = false;
            }
        }
        x = 0;
        y = 0;
        visited[y][x] = true;
        std::queue<tb> bfs = std::queue<tb>();
        bfs.push(tb(x, y, 1));
        found = false;
        while (!bfs.empty())
        {
            tb next = bfs.front();
            bfs.pop();
            x = get(next, 0);
            y = get(next, 1);

            if (x == w - 1 && y == h - 1)
            {
                printi(get(next, 2));
                found = true;
                break;
            }
            else
            {
                cur = map[y][x];
                if ((cur == '-' || cur == '+') && in(x + 1, 0, w - 1) && !visited[y][x + 1] && map[y][x + 1] != '*')
                {
                    bfs.push(tb(x + 1, y, get(next, 2) + 1));
                    visited[y][x + 1] = true;
                }
                if ((cur == '-' || cur == '+') && in(x - 1, 0, w - 1) && !visited[y][x - 1] && map[y][x - 1] != '*')
                {
                    bfs.push(tb(x - 1, y, get(next, 2) + 1));
                    visited[y][x - 1] = true;
                }
                if ((cur == '|' || cur == '+') && in(y + 1, 0, h - 1) && !visited[y + 1][x] && map[y + 1][x] != '*')
                {
                    bfs.push(tb(x, y + 1, get(next, 2) + 1));
                    visited[y + 1][x] = true;
                }
                if ((cur == '|' || cur == '+') && in(y - 1, 0, h - 1) && !visited[y - 1][x] && map[y - 1][x] != '*')
                {
                    bfs.push(tb(x, y - 1, get(next, 2) + 1));
                    visited[y - 1][x] = true;
                }
            }
        }
        if (!found)
        {
            printi(-1);
        }
    }

    return 0;
}