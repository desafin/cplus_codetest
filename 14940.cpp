#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1001][1001];      // 입력받은 원래 지도
int dist[1001][1001];   // 목표지점으로부터의 거리를 저장할 배열
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            dist[i][j] = -1; // 거리 배열을 -1로 초기화
            if (a[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0; // 목표 지점(시작점)의 거리는 0
            }
        }
    }

    // 3. BFS 실행
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 지도 범위를 벗어나는 경우
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            // 이미 방문했거나, 원래 갈 수 없는 땅(0)인 경우
            if (dist[ny][nx] != -1 || a[ny][nx] == 0) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // 4. 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 원래 갈 수 없는 땅(0)은 0으로 출력
            if (a[i][j] == 0) {
                cout << 0 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}