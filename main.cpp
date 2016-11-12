#include <iostream>
#include <string>

const bool DEBUGGING = true;

class Creature
{
  protected:
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
      if(DEBUGGING) std::cout << "Init Creature constructor\n";
    }

    //GET
    const std::string getName() const { return mName; }
    const char getSymbol() const      { return mSymbol; }
    const int getHealthPoints() const { return mHealthPoints; }
    const int getDamagePoints() const { return mDamagePoints; }
    const int getGold() const         { return mGold; }

    //check if the creature is dead
    bool isDead() const { return mHealthPoints <= 0; }

    //SET
    void reduceHealth(int damage) { mHealthPoints -= damage; }
    void addGold(int amount) { mGold += amount; }

};

class Player : public Creature
{
  private:
    int mLevel = 1;

  public:
    Player(std::string name) : Creature(name, '@', 10, 1, 0)
    {
      if(DEBUGGING) std::cout << "Init Player constructor\n";
    }

    //GET
    void levelUp()
    {
      ++mLevel;
      ++mDamagePoints;
    }

    bool hasWon() { return mLevel >= 20; }

    //SET
    int getLevel() { return mLevel; }

};

class Monster : public Creature
{
  private:

  public:
    enum Type
    {
      DRAGON,
      ORC,
      SLIME,
      MAX_TYPES
    };
};

int main()
{
  std::cout << "Enter your name: ";
  std::string playerName;
  std::cin >> playerName;
  Player player(playerName);

  std::cout << "Welcome, " << player.getName() << ".\nYou have " << player.getHealthPoints() << "HP and are carrying " << player.getGold() << " gold.\n";

  Creature creature("Orc", 'o', 200, 10, 30);
  creature.addGold(10);
  creature.reduceHealth(123);

  std::cout << "The creatures name is " << creature.getName() << " its symbol is " << creature.getSymbol() << " it has " << creature.getHealthPoints() << "HP, the damage it makes is " << creature.getDamagePoints() << "DPH and the amount of gold it carries is " << creature.getGold() << "G\n";

  return 0;
}
