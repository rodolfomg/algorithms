int maximalSquare(std::vector<std::vector<char>> matrix) {
  if (matrix.empty()) return 0;
  
  int max_square = 0, squares[100][100];
  for (int row = 0; row < matrix.size(); row++) {
    for (int column = 0; column < matrix[0].size(); column++) {
      if (matrix[row][column] == '0') squares[row][column] = 0;
      else {
        if (!row || !column) {
          squares[row][column] = 1;
          max_square = max(max_square, 1);
        }
        else {
          int side = min(
            min(squares[row - 1][column], squares[row][column-1]),
            squares[row - 1][column - 1]
          ) + 1;
          squares[row][column] = side;
          max_square = max(max_square, (side * side));
        }
      }
    }
  }
  
  return max_square;
}
