#include <iostream>
#include <queue>
using namespace std;

#define N 300
#define MAX_N(t) (2*t*(2*t+1))

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int n;
bool g[4 * N + 2][4 * N + 2];

#define ROWS (4*n)
#define COLUMNS (2*(2*n+1))

void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for(int d = 0; d < 4; d++) {
            int x = u.first + dx[d], y = u.second + dy[d];
            if ((x >= 0 && x < ROWS) &&
                (y >= 0 && y < COLUMNS) && 
                !g[x][y])
            {
                Q.push(make_pair(x, y));
                g[x][y] = true;
            }
        }
    }
}

int main() {
    char b;
    int evenLine, bi, bj;
    while (cin >> n) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                g[i][j] = false;
            }
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b;
                evenLine = i % 2;
                bi = 2*i+1;
                bj = 2*(2*j + evenLine) + 1;
                if (b == 'H') {
                    g[bi][bj-1] = true;
                    g[bi][bj] = true;
                    g[bi][bj+1] = true;
                    g[bi][bj+2] = true;
                } else {
                    g[bi-1][bj] = true;
                    g[bi][bj] = true;
                    g[bi+1][bj] = true;
                    g[bi+2][bj] = true;
                }
            }
        }

        int cfcs = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (!g[i][j]) {
                    bfs(i, j);
                    cfcs++;
                }
            }
        }

        cout << cfcs-1 << endl;
    }

    return 0;
}
