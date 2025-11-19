#include <iostream>
#include <vector>
#include <queue>

int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<std::vector<int>> a(m, std::vector<int>(n));
    std::queue<std::pair<int,int>> q;

    int mushrooms = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];

            if (a[i][j] == 1) mushrooms++;
            if (a[i][j] == 2) q.push({i, j});
        }
    }

    if (mushrooms == 0) {
        std::cout << 0;
        return 0;
    }

    int minutes = -1;

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int sz = q.size();
        minutes++;

        while (sz--) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    mushrooms--;
                    q.push({nx, ny});
                }
            }
        }
    }

    if (mushrooms > 0) std::cout << -1;
    else std::cout << minutes;

    return 0;
}
