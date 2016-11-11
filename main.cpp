#include <iostream>

class IntArray
{
  private:
    int mArrayLength = 0;
    int *mArray = nullptr; //pointer for dynamically allocating array

  public:
    IntArray(int length) : mArrayLength{length}
    {
      mArray = new int[mArrayLength] { 0 }; //initialize the array with a zero as the first item
    }

    IntArray(const IntArray &array) : mArrayLength{array.mArrayLength}
    {
      //allocate a new array
      mArray = new int[mArrayLength];

      //copy elements from the origina array to the new one
      for(int count = 0; count < array.mArrayLength; ++count)
        mArray[count] = array.mArray[count];
    }

    ~IntArray()
    {
      delete[] mArray;
    }
};

int main()
{
  IntArray a(10);
  IntArray b = a;

  return 0;
}
