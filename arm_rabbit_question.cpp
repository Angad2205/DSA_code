#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void path(vector<vector<int>> &matrix, int no_of_row, int no_of_column,
          int row_index, int column_index,
          vector<vector<bool>> &visited,
          vector<int> &carrot_from_all_path,
          int carrot = 0)
{
    // Base conditions
    if (row_index < 0 || column_index < 0 || row_index >= no_of_row || column_index >= no_of_column)
        return;

    if (visited[row_index][column_index])
        return;

    // If destination reached
    if (row_index == no_of_row - 1 && column_index == no_of_column - 1)
    {
        carrot_from_all_path.push_back(carrot + matrix[row_index][column_index]);
        return;
    }

    // Mark visited
    visited[row_index][column_index] = true;

    // Explore 4 directions
    path(matrix, no_of_row, no_of_column, row_index - 1, column_index, visited, carrot_from_all_path, carrot + matrix[row_index][column_index]);
    path(matrix, no_of_row, no_of_column, row_index, column_index - 1, visited, carrot_from_all_path, carrot + matrix[row_index][column_index]);
    path(matrix, no_of_row, no_of_column, row_index + 1, column_index, visited, carrot_from_all_path, carrot + matrix[row_index][column_index]);
    path(matrix, no_of_row, no_of_column, row_index, column_index + 1, visited, carrot_from_all_path, carrot + matrix[row_index][column_index]);

    // Backtrack
    visited[row_index][column_index] = false;
}

int pathfinder(vector<vector<int>> &matrix, int no_of_row, int no_of_column)
{
    vector<vector<bool>> visited(no_of_row, vector<bool>(no_of_column, false));
    vector<int> carrot_from_all_path;

    path(matrix, no_of_row, no_of_column, 0, 0, visited, carrot_from_all_path, 0);

    // Find max carrot path
    if (carrot_from_all_path.empty())
        return 0;

    return *max_element(carrot_from_all_path.begin(), carrot_from_all_path.end());
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {0, 4, 5},
        {6, 7, 8}};

    int maxCarrots = pathfinder(matrix, matrix.size(), matrix[0].size());

    cout << "Maximum carrots collected = " << maxCarrots << endl;

    return 0;
}
