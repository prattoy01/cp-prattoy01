#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> extractLayers(const std::vector<std::vector<int>>& matrix) {
  vector<vector<int>>v;
  if (matrix.empty()) return v;

  int rows = matrix.size();
  int cols = matrix[0].size();
  int layers = (std::min(rows, cols) + 1) / 2;
  for (int layer = 0; layer < layers; ++layer) {

    vector<int>temp;

    for (int i = layer; i < cols - layer; ++i) {
      // std::cout << matrix[layer][i] << " ";
      temp.push_back(matrix[layer][i]);
    }


    for (int i = layer + 1; i < rows - layer; ++i) {

      temp.push_back(matrix[i][cols - layer - 1]);
    }


    if (rows - layer - 1 > layer) {
      for (int i = cols - layer - 2; i >= layer; --i) {
        temp.push_back(matrix[rows - layer - 1][i]);

      }
    }


    if (cols - layer - 1 > layer) {
      for (int i = rows - layer - 2; i > layer; --i) {

        temp.push_back(matrix[i][layer]);

      }
    }

    v.push_back(temp);
  }
  return v;
}

int main() {
  int rows, cols;

  std::cin >> rows >> cols;

  std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  auto a = extractLayers(matrix);
  for (auto i : a) {
    for (auto it : i)cout << it << " ";
    cout << '\n';
  }

  return 0;
}
