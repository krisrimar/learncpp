#include "matrix.h"
#include <cassert>

double& Matrix::operator() (int row, int col)
{
  assert(col >= 0 && col <= 4);
  assert(row >= 0 && row <= 4);

  return data[row][col];
}

const double& Matrix::operator() (int row, int col) const
{
  assert(col >= 0 && col <= 4);
  assert(row >= 0 && row <= 4);

  return data[row][col];
}
