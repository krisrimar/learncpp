#include <iostream>

enum MonsterType
{
  MONSTER_DRAGON,
  MONSTER_GOBLIN,
  MONSTER_OGRE,
  MONSTER_ORC,
  MONSTER_SKELETON,
  MONSTER_TROLL,
  MONSTER_VAMPIRE,
  MONSTER_ZOMBIE,
  MAX_MONSTER_TYPES
};

class Monster
{
  private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;
};

int main()
{
  return 0;
}
