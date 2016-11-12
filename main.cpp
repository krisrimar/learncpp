#include <iostream>
#include <string>

class Creature
{
  private:
    std::string mName;
    char mSymbol;
    int mHealthPoints;
    int mDamagePoints;
    int mGold;

  public:
    //CONSTRUCTORS
    Creature(std::string name = "Unknown", char symbol = 'u', int healthPoints = 0, int damagePoints = 0, int gold = 0)
      : mName(name), mSymbol(symbol), mHealthPoints(healthPoints), mDamagePoints(damagePoints), mGold(gold)
    {
    }

    //GET
    std::string getName() { return mName; }
    char getSymbol() { return mSymbol; }
    int getHealthPoints() { return mHealthPoints; }
    int getDamagePoints() { return mDamagePoints; }
    int getGold() { return mGold; }

    //check if the creature is dead
    bool isDead()
    {
      if(mHealthPoints <= 0)
        return true;
      return false;
    }

    //SET
    void reduceHealth(int damage)
    {
      mHealthPoints -= damage;
    }

    void addGold(int amount)
    {
      mGold += amount;
    }

};

int main()
{
  Creature creature("Orc", 'o', 200, 10, 30);

  std::cout << "The creatures name is " << creature.getName() << " its symbol is " << creature.getSymbol() << " it has " << creature.getHealthPoints() << "HP, the damage it makes is " << creature.getDamagePoints() << "DPH and the amount of gold it carries is " << creature.getGold() << "G\n";

  return 0;
}
