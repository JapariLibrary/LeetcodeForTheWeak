class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return -1;
        int l1 = maze.size(), l2 = maze[0].size();
        vector<vector<bool>> visited(l1, vector<bool>(l2, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        q.push({0, start[0], start[1]});
        vector<vector<int>> dirs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}});
        while (!q.empty()) {
            vector<int> tmp = q.top();
            q.pop();
            int distance = tmp[0];
            int x = tmp[1];
            int y = tmp[2];
            if (x == destination[0] && y == destination[1]) return distance;
            if (visited[x][y]) continue;
            visited[x][y] = true;
            for (vector<int>& dir : dirs) {
                int nx = x, ny = y;
                int dx = dir[0];
                int dy = dir[1];
                int len = 0;
                while (0 <= nx + dx && nx + dx < l1 && 0 <= ny + dy && ny + dy < l2 && maze[nx + dx][ny + dy] == 0) {
                    nx += dx;
                    ny += dy;
                    ++len;
                }
                if (!visited[nx][ny]) {
                    q.push({distance + len, nx, ny});
                }
            }
        }
        return -1;
    }
};