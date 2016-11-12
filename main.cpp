//Using IDs to refrence other objects

#include <iostream>
#include <string>

class Car
{
  private:
    std::string mName;
    int mID;

  public:
    Car(std::string name, int ID) : mName(name), mID(ID) {}

    std::string getName() { return mName; }
    int getID() { return mID; }
};

//car lot is essentially just a static array or Cars and a lookup function to retreive them
//because it's static, we don't need to allocate an object of type CarLot to use it

class CarLot
{
  private:
    static Car sCarLot[4];

    CarLot() = delete; //ensure we don't try to allocate a CarLot

  public:
    static Car* getCar(int ID)
    {
      for(int count = 0; count < 4; ++count)
        if(sCarLot[count].getID() == ID)
          return &(sCarLot[count]);

      return nullptr; //in case the ID cannot be fount
    }
};

Car CarLot::sCarLot[4] = { Car("Prius", 4), Car("Corolla", 17), Car("Accord", 84), Car("Matrix", 62) };

class Driver
{
  private:
    std::string mName;
    int mCarID; //will be associated with a Car by ID ratether than pointer

  public:
    Driver(std::string name, int carID) : mName(name), mCarID(carID) {}

    std::string getName() { return mName; }
    int getCarID() { return mCarID; }
};

int main()
{
  Driver d("Franz", 17); // Franz is driving the car with ID 17

  Car *car = CarLot::getCar(17); // Get that car from the car lot
  //using direct access here, because the class is static, and we don't have several objects of that class

  if(car)
    std::cout << d.getName() << " is driving a " << car->getName() << '\n';
  else
    std::cout << d.getName() << " couldn't find his car\n";

    return 0;
}
