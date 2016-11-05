#include <iostream>

class Accumulator
{
  private:
    int m_value;
  public:
    Accummulator() { m_value = 0; }
    void add(int value) { m_value += value; }

    //make reset function a "friend" of the Accummulator class
    //othervise, reset() would not be able to access private members
    //of the Accummulator class
    friend void reset(Accummulator &accumulator);
};

//takes an object of class Accummulator, accesses it's member called m_value, and sets the value to 0
void reset(Acummulator &accumulator)
{
  accumulator.m_value = 0;
}

int main()
{
  Accumulator acc;
  acc.add(5);
  reset(acc); //pass the object
  return 0;
}
