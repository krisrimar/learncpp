/* An example of a true deep copy of a dynamically created array (similar to how vector functions) */

#include <iostream>
#include <cassert>

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
      mArray = nullptr;
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

    int& operator[] (const int index)
    {
      assert(index >= 0);
      assert(index < mArrayLength);
      return mArray[index]; //will return a reference to the position of the array element in the memory, so it can be altered
    }

    IntArray& operator= (const IntArray &array)
    {
      //self-assignment guard
      if(this == &array)
        return *this;

      //if this array has been created already and carries some values - delete everything
      delete[] mArray;
      mArray = nullptr; //not really needed here, because we will assign a value in a second to this memory cell, but it's good practice to do so

      mArrayLength = array.mArrayLength;

      //allocate a new array
      mArray = new int[mArrayLength];

      //copy elements from the original array to the new array
      for(int count = 0; count < array.mArrayLength; ++count)
        mArray[count] = array.mArray[count];

      return *this;
    }
};

IntArray fillArray()
{
  IntArray a(5);
  a[0] = 5;
  a[1] = 4;
  a[2] = 3;
  a[3] = 2;
  a[4] = 1;

  return a;
}


int main()
{
  IntArray a = fillArray();

	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	return 0;
}
