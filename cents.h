class Cents
{
private:
  int mCents;

public:
  Cents(int cents) : mCents{cents} {}

  int getCents() const { return mCents; }
};

//explicitly providing a prototype so other files know the overload exists
Cents operator+(const Cents &c1, const Cents &c2);
