#include <iostream>
#include <vector>
#include <queue>

int main () {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    int start, end, cnt = 0;
    std::cin >> start >> end;
    start--; end--;

    std::queue<int> q;
    std::vector<bool> visited(n, false);
    std::vector<int> dist(n, 0);

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        
        int v = q.front();
        q.pop();

        if (v == end) {
            std::cout << dist[v];
            return 0;
        }
 
        for (int i = 0; i < n; i++) {
            if (matrix[v][i] && !visited[i]) {
                visited[i] = true;
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }

    std::cout << -1;    
}