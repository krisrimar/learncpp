#include <iostream>

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
    static Monster generateMonster()
    {
      return Monster(Monster::MonsterType::SKELETON, "Bones", "*rattle*", 4);
    }
};

int main()
{
  Monster skele = MonsterGenerator::generateMonster();
  skele.print();
  return 0;
}
