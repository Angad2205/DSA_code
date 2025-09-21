#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &matrix, int row, int col,
           vector<vector<bool>> &visited, string path, vector<string> &ans) {
    int n = matrix.size();

    // Base conditions (out of bounds or blocked or already visited)
    if (row < 0 || col < 0 || row >= n || col >= n ||
        matrix[row][col] == 0 || visited[row][col]) {
        return;
    }

    // Destination reached
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark visited
    visited[row][col] = true;

    // Explore all 4 directions
    solve(matrix, row + 1, col, visited, path + "D", ans); // Down
    solve(matrix, row - 1, col, visited, path + "U", ans); // Up
    solve(matrix, row, col + 1, visited, path + "R", ans); // Right
    solve(matrix, row, col - 1, visited, path + "L", ans); // Left

    // Backtrack
    visited[row][col] = false;
}

vector<string> findPath(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    if (matrix[0][0] == 0) return ans; // start blocked

    solve(matrix, 0, 0, visited, "", ans);
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(matrix);

    if (paths.empty()) {
        cout << "No path exists\n";
    } else {
        cout << "Paths:\n";
        for (string &p : paths) {
            cout << p << endl;
        }
    }

    return 0;
}
