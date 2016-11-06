#include <iostream>
#include <ctime> //for time()
#include <cstdlib> //for srand()
#include <string>

class Monster
{
  public:
    enum MonsterType
    {
      DRAGON,
      GOBLIN,
      OGRE,
      ORC,
      SKELETON,
      TROLL,
      VAMPIRE,
      ZOMBIE,
      MAX_MONSTER_TYPES
    };

    Monster(MonsterType type, std::string name, std::string roar, int hitPoints) : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints} {}

    std::string getTypeString()
    {
      switch(m_type)
      {
        case DRAGON:  return "dragon";
        case GOBLIN:  return "goblin";
        case OGRE:    return "ogre";
        case ORC:     return "orc";
        case SKELETON:return "skeleton";
        case TROLL:   return "troll";
        case VAMPIRE: return "vampire";
        case ZOMBIE:  return "zombie";
        default:      return "unknown";
      }
    }

    void print()
    {
      std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
    }

  private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

};

class MonsterGenerator
{
  private:

  public:
    //this function is static because we need to use it without a class object
    static Monster generateMonster()
    {
      //array for random names generation
      //is static to be initialized only once, otherwise they would be initiated each time
      //the generateMonster() function is called
      static std::string s_names[6] {"Blackfish", "John Snow", "Jamie Lannister", "Margaret Tyrell", "Tyrion Lannister", "Sansa Stark"};
      //array for random sounds generation
      static std::string s_sounds[6] {"*roar*", "*scream*", "*rattle*", "*growl*", "*grunt*", "*hiss*"};
      //Monster(type, name, sound, hit points)
      return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0,Monster::MonsterType::MAX_MONSTER_TYPES-1)), s_names[getRandomNumber(0,5)], s_sounds[getRandomNumber(0,5)], getRandomNumber(0,100));
    }

    static int getRandomNumber(int min, int max)
    	{
    		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    		// evenly distribute the random number across our range
    		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    	}
};

int main()
{
  srand(static_cast<unsigned int>(time(0)));

  Monster skele = MonsterGenerator::generateMonster();
  skele.print();
  return 0;
}
