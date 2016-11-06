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

  private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;

};

int main()
{
  Monster skele(Monster::MonsterType::SKELETON, "Bones", "*rattle*", 4);
  return 0;
}
