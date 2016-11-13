#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const bool DEBUGGING = false;
const bool MORE_INFO = false;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

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

    struct MonsterData
    {
      std::string mName;
      char mSymbol;
      int mHealthPoints;
      int mDamagePoints;
      int mGold;
    };

    static MonsterData monsterData[MAX_TYPES];

    //COSNTRUCTOR
    Monster(Type type)
      : Creature(monsterData[type].mName, monsterData[type].mSymbol, monsterData[type].mHealthPoints, monsterData[type].mDamagePoints, monsterData[type].mGold)
    {
    }

    //GET
    static Monster getRandomMonster()
    {
      return Monster(static_cast<Type>(getRandomNumber(0,MAX_TYPES-1)));
    }
    //SET
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 },
};

void attackMonster(Player &player, Monster &monster)
{
  if(MORE_INFO)
  {
    std::cout << "You choose to fight!\n";
    std::cout << "You:\t Lvl " << player.getLevel() << "\t" << player.getHealthPoints() << "HP\t" << player.getDamagePoints() << "DPH\n";
    std::cout << monster.getName() << ":\t" << monster.getHealthPoints() << "HP\t" << monster.getDamagePoints() << "DPH\n";
  }
  monster.reduceHealth(player.getDamagePoints());
  std::cout << "You hit the " << monster.getName() << " for " << player.getDamagePoints() << " damage\n";
}

void attackPlayer(Player &player, Monster &monster, bool playerFleeing)
{
  //check if player was fleeing when the monster attacked him (chose 'r')
  if(playerFleeing)
  {
    //calculate the chance of user fleeing without being attacked by the monster
    bool succeededToFlee = static_cast<bool>(getRandomNumber(0,1));
    if(succeededToFlee)
    {
      std::cout << "You successfully fled.\n";
      return;
    }
    else
    {
      std::cout << "You failed to flee.\n";
    }
  }
  player.reduceHealth(monster.getDamagePoints());
  std::cout << "The " << monster.getName() << " hit you for " << monster.getDamagePoints() << " damage.\n";
}

void fightMonster(Player &player, Monster &monster)
{
  static char userChoice;
  //this loop will run until either the monster or the player is dead
  //until that moment, it will ask the user for his choice: wither to fight or to run
  do
  {
    //this loop simply ensures the user enters 'f' or 'r' and not smth else
    do
    {
      std::cout << "(R)un or (F)ight: ";
      std::cin >> userChoice;
    }
    while(userChoice != 'f' && userChoice != 'r');

    //check what the user has entered and based on his choice:
    //either fight the monster or run away
    //running away will cause the monster to attack you
    //but only with a 50% chance of hitting you
    if(userChoice == 'f')
    {
      attackMonster(player, monster);
    }
    else
    {
      attackPlayer(player, monster, true);
      break;
    }

    attackPlayer(player, monster, false);

    if(DEBUGGING)
    {
      std::cout << "Player dead (1 - yes, 0 - no):\t" << player.isDead() << "\n";
      std::cout << "Monster dead (1 - yes, 0 - no):\t" << monster.isDead() << "\n";
    }
  }
  while(!monster.isDead() && !player.isDead());
  if(DEBUGGING) std::cout << "Exiting while loop\n";

  //check whether you killed the monster or the monster killed you
  if(monster.isDead())
  {
    std::cout << "You killed the " << monster.getName() << " and looted it for " << monster.getGold() << " gold\n";
    player.addGold(monster.getGold());
    player.levelUp();
    std::cout << "You are now level " << player.getLevel() << "\n";
    if(MORE_INFO)
    {
      std::cout << "You:\t Lvl " << player.getLevel() << "\t" << player.getHealthPoints() << "HP\t" << player.getDamagePoints() << "DPH\n";
    }
  }
  if(player.isDead())
  {
    std::cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold\n";
  }
}


void playGame(Player &player)
{
  while(!player.isDead())
  {
    Monster monster = Monster::getRandomMonster();
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";
    fightMonster(player, monster);
  }
  return;
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  getRandomNumber(0,Monster::Type::MAX_TYPES);


  std::cout << "Enter your name: ";
  std::string name;
  std::cin >> name;

  Player player(name);

  std::cout << "Welcome " << player.getName() << "\n";

  playGame(player);

  return 0;
}
