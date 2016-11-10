#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
  private:
    double data[4][4];
  public:
    Matrix()
    {
      for(int row = 0; row < 4; ++row)
        for(int col = 0; col < 4; ++col)
          data[row][col] = 0.0;
    }

    double& operator() (int row, int col);
    const double& operator() (int row, int col) const;
};

#endif
