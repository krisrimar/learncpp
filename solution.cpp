#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(std::string name, char symbol, int health, int damage, int gold) :
		m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
	{
	}

	char getSymbol() { return m_symbol; }
	const std::string& getName() { return m_name; }
	bool isDead() { return m_health <= 0; }
	int getGold() { return m_gold; }
	void addGold(int gold) { m_gold += gold;  }
	void reduceHealth(int health) { m_health -= health;  }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage;  }
};

class Player : public Creature
{
	int m_level = 1;

public:
	Player(std::string name)
		: Creature(name, '@', 10, 1, 0)
	{
	}

	void levelUp()
	{
		++m_level;
		++m_damage;
	}

	int getLevel() { return m_level; }
	bool hasWon() { return m_level >= 20; }
};



class Monster : public Creature
{
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
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];
	Type m_type;

	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold), m_type(type)
	{
	}

	static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 6, 2, 25 },
	{ "slime", 's', 1, 1, 5 },
};

// This function handles the player attacking the monster
void attackMonster(Player &p, Monster &m)
{
	// If the player is dead, we can't attack the monster
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	// Reduce the monster's health by the player's damage
	m.reduceHealth(p.getDamage());

	// If the monster is now dead, level the player up
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

// This function handles the monster attacking the player
void attackPlayer(Monster &m, Player &p)
{
	// If the monster is dead, it can't attack the player
	if (m.isDead())
		return;

	// Reduce the player's health by the monster's damage
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

// This function handles the entire fight between a player and a randomly generated monster
void fightMonster(Player &p)
{
	// First randomly generate a monster
	Monster m = Monster::getRandomMonster();
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	// While the monster isn't dead and the player isn't dead, the fight continues
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input;
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50% chance of fleeing successfully
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // success ends the encounter
			}
			else
			{
				// Failure to flee gives the monster a free attack on the player
				std::cout << "You failed to flee.\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			// Player attacks first, monster attacks second
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << '\n';

	// If the player isn't dead and hasn't won yet, the game continues
	while (!p.isDead() && !p.hasWon())
		fightMonster(p);

	// At this point, the player is either dead or has won
	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << p.getGold() << " gold!\n";
	}
}
