#include <iostream>

const bool DEBUGGING = true;

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
      if(DEBUGGING) std::cout << "Copy constructor for object of class IntArray initialized" << '\n';

      //allocate a new array
      mArray = new int[mArrayLength];

      //copy elements from the origina array to the new one
      for(int count = 0; count < array.mArrayLength; ++count)
        mArray[count] = array.mArray[count];
    }

    ~IntArray()
    {
      if(DEBUGGING) std::cout << "Destructor for object of class IntArray initialized" << '\n';
      delete[] mArray;
    }

    //for printing the array elements
    friend std::ostream& operator<< (std::ostream &out, const IntArray &array)
    {
      for(int count = 0; count < array.mArrayLength; ++count)
      {
        out << array.mArray[count] << ' ';
      }
      return out;
    }
};


int main()
{
  IntArray a(10);
  IntArray b = a;

  std::cout << a;

  return 0;
}
