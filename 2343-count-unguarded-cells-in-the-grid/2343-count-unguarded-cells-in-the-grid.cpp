class Solution {
public:
    bool valid(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 'w' || grid[i][j] == 'g') {
            return false;
        }
        return true;
    }
    void fill(int i, int j, vector<vector<char>>& grid) {
        int x = i, y = j;
        // up -> x--
        x--;
        while (valid(x, y, grid)) {
            grid[x][y] = '#';
            x--;
        }
        // right -> y++
        x = i, y = j;
        y++;
        while (valid(x, y, grid)) {
            grid[x][y] = '#';
            y++;
        }

        // down -> x++
        x = i, y = j;
        x++;
        while (valid(x, y, grid)) {
            grid[x][y] = '#';
            x++;
        }

        // left -> y--
        x = i, y = j;
        y--;
        while (valid(x, y, grid)) {
            grid[x][y] = '#';
            y--;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for (auto p : guards) {
            grid[p[0]][p[1]] = 'g';
        }
        for (auto p : walls) {
            grid[p[0]][p[1]] = 'w';
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout<<grid[i][j]<<' ';
                if (grid[i][j] == 'g') {
                    fill(i, j, grid);
                }
            }
        }
        int count = 0;
        for (auto row : grid) {
            for (auto col : row) {
                if (col == '.') {
                    count++;
                }
                cout << col << ' ';
            }
            cout << '\n';
        }
        return count;
    }
};