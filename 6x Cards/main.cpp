#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <ctime>

//set to true to enter debugging mode and see conditions in the logs
bool debugMode = false;

//TEXT STRINGS

const std::string dealer_gets_card   = "The dealer gets card ";
const std::string player_gets_card   = "You get card ";
const std::string player_gets_cards  = "You get cards ";
const std::string dealer_skips_turn  = "The dealer skips his turn";
const std::string player_skips_turn  = "You skip your turn";

//END TEXT STRINGS

class Card
{
  public:
    enum CardRank
    {
      RANK_2,
      RANK_3,
      RANK_4,
      RANK_5,
      RANK_6,
      RANK_7,
      RANK_8,
      RANK_9,
      RANK_10,
      RANK_JACK,
      RANK_QUEEN,
      RANK_KING,
      RANK_ACE,
      MAX_RANKS
    };

    enum CardSuit
    {
      SUIT_CLUBS,
      SUIT_DIAMONDS,
      SUIT_HEARTS,
      SUIT_SPADES,
      MAX_SUITS
    };

    Card(CardRank rank = RANK_2, CardSuit suit = SUIT_CLUBS) : m_rank{rank}, m_suit{suit} {}

    void printCard() const
    {
      switch (m_rank)
      {
        case RANK_2:      std::cout << '2';  break;
        case RANK_3:      std::cout << '3';  break;
        case RANK_4:      std::cout << '4';  break;
        case RANK_5:      std::cout << '5';  break;
        case RANK_6:      std::cout << '6';  break;
        case RANK_7:      std::cout << '7';  break;
        case RANK_8:      std::cout << '8';  break;
        case RANK_9:      std::cout << '9';  break;
        case RANK_10:     std::cout << 'T';  break;
        case RANK_JACK:   std::cout << 'J';  break;
        case RANK_QUEEN:  std::cout << 'Q';  break;
        case RANK_KING:   std::cout << 'K';  break;
        case RANK_ACE:    std::cout << 'A';  break;

        default:          std::cout << 'X';
      }
      switch (m_suit)
      {
        case SUIT_SPADES:   std::cout << "♠";  break;
        case SUIT_HEARTS:   std::cout << "♥";  break;
        case SUIT_CLUBS:    std::cout << "♣";  break;
        case SUIT_DIAMONDS: std::cout << "♦";  break;

        default:            std::cout << 'x';
      }
    }

    int getCardValue() const
    {
      switch (m_rank) {
        case RANK_2:      return 2;
        case RANK_3:      return 3;
        case RANK_4:      return 4;
        case RANK_5:      return 5;
        case RANK_6:      return 6;
        case RANK_7:      return 7;
        case RANK_8:      return 8;
        case RANK_9:      return 9;
        case RANK_10:
        case RANK_JACK:
        case RANK_QUEEN:
        case RANK_KING:   return 10;
        case RANK_ACE:    return 11;

        default:          return 0;
      }
    }

    friend class Deck;

  private:
    CardRank m_rank;
    CardSuit m_suit;
};

class Deck
{
  private:

    int m_cardIndex = 0; //current card in the deck

    std::array <Card, Card::MAX_RANKS * Card::MAX_SUITS> m_deck;

    //function for generating a random number
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
        // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    //swaps values of two cards in the deck array
    static void swapCards(Card &card1, Card &card2)
    {
      std::swap(card1, card2);
    }

  public:
    //the default constructor creates an array of cards
    //no need to have other constructors (with parameters)
    Deck()
    {
      static int card = 0;
      for(int suit = 0; suit < Card::MAX_SUITS; ++suit)
      {
        for(int rank = 0; rank < Card::MAX_RANKS; ++rank)
        {
          m_deck[card] = Card(static_cast<Card::CardRank>(rank), static_cast<Card::CardSuit>(suit));
          ++card;
        }
      }
      card = 0;
    }

    //goes throught the each element of the card deck and prints it
    void printDeck() const
    {
      for(const auto &card : m_deck)
      {
        card.printCard();
        std::cout << ' ';
      }
    }

    //shuffles the deck of cards randomly
    Deck& shuffleDeck()
    {
      m_cardIndex = 0; //reset the current card index, as the deck has been shuffled

      for(int index = 0; index < Card::MAX_RANKS * Card::MAX_SUITS; ++index)
      {
        swapCards(m_deck[index], m_deck[getRandomNumber(0,(Card::MAX_RANKS * Card::MAX_SUITS -1))]);
      }

      return *this; //done to be able to concatenate members deck.shuffleDeck().printDeck()
    }

    //returning the current card (based on the m_cardIndex)
    const Card& dealCard()
    {
      ++m_cardIndex;
      return m_deck[m_cardIndex - 1];
    }

};

//checks the game condition (if player won or if dealer won or it its a tie)
//game over - returns false
//game continues - returns true
bool checkGameCondition(int &playerScore, int &dealerScore)
{

  if(debugMode) std::cout << "Comparing p: " << playerScore << " and d: " << dealerScore << '\n';

  if(playerScore <= 21 && dealerScore <= 21 && playerScore == dealerScore)
  {
    std::cout << "\nIt's a tie! :D\n";
    return false;
  }
  else if(playerScore > 21 || dealerScore == 21)
  {
    std::cout << "\nYou lost :(\n";
    return false;
  }
  else if(dealerScore > 21 || playerScore == 21)
  {
    std::cout << "\nYou won! :D\n";
    return false;
  }
  else
  {

    if(debugMode) std::cout << "No condition matched\n";

    return true;
  }
}

//taking user input to determine whether to take a card or skip the turn
bool hitOrStand()
{
  char *option = new char;
  while(true)
  {
    std::cout << "Do you wish to hit or stand? (h/s): ";
    std::cin >> *option;

    if(std::cin.fail() || (*option != 'h' && *option != 's'))
    {
      std::cin.clear();
      std::cin.ignore(32767,'\n');
      std::cout << "\nWrong input!\n\n";
    }
    else
    {
      std::cin.ignore(32767,'\n');
      std::cout << '\n';
      if(*option == 'h')
        return true; //in case of a hit
      else
        return false; //in case of a stand
    }
  }
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));

  Deck deck;
	deck.shuffleDeck();
	//deck.printDeck();

  std::cout << '\n' << '\n';

  //initialize player and dealer scores
  int *playerScore = new int;
  int *dealerScore = new int;

  //player makes first move
  std::cout << player_gets_cards;
  Card currentCard = deck.dealCard();
  currentCard.printCard();
  *playerScore = currentCard.getCardValue();
  std::cout << ' ';
  currentCard = deck.dealCard();
  currentCard.printCard();

  if(debugMode) std::cout << "\nAdding p: " << *playerScore << " + " << currentCard.getCardValue() << '\n';

  *playerScore += currentCard.getCardValue();
  std::cout << " (score: " << *playerScore << ")\n";

  //dealer makes move
  std::cout << dealer_gets_card;
  currentCard = deck.dealCard();
  currentCard.printCard();
  *dealerScore = currentCard.getCardValue();
  std::cout << " (score: " << *dealerScore << ")\n";

  if(!checkGameCondition(*playerScore, *dealerScore))
    return 0;

    while(true)
    {
      //players move
      if(hitOrStand())
      {
        std::cout << player_gets_card;
        Card currentCard = deck.dealCard();
        currentCard.printCard();

        if(debugMode) std::cout << "\nAdding p: " << *playerScore << " + " << currentCard.getCardValue() << '\n';

        *playerScore += currentCard.getCardValue();
        std::cout << " (score: " << *playerScore << ")\n";
      }
      else
      {
        std::cout << player_skips_turn << " (score: " << *playerScore << ")\n";
      }

      if(!checkGameCondition(*playerScore, *dealerScore))
        return 0;

      //dealers move
      if(*dealerScore < 17)
      {
        std::cout << dealer_gets_card;
        currentCard = deck.dealCard();
        currentCard.printCard();

        if(debugMode) std::cout << "\nAdding d: " << *dealerScore << " + " << currentCard.getCardValue() << '\n';

        *dealerScore += currentCard.getCardValue();
        std::cout << " (score: " << *dealerScore << ")\n";
      }
      else
      {
        std::cout << dealer_skips_turn;
        std::cout << " (score: " << *dealerScore << ")\n";
      }

      if(*dealerScore > 21)
      {
        std::cout << "You won! :D";
        break;
      }

      std::cout << '\n';
    }

  return 0;
};

/*using namespace std;

const string dealer_gets_card   = "The dealer gets card ";
const string player_gets_card   = "You get card ";
const string player_gets_cards  = "You get cards ";
const string dealer_skips_turn  = "The dealer skips his turn";
const string player_skips_turn  = "You skip your turn";

enum CardRank
{
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
  RANK_9,
  RANK_10,
  RANK_JACK,
  RANK_QUEEN,
  RANK_KING,
  RANK_ACE,
  MAX_RANKS
};

enum CardSuit
{
  SUIT_CLUBS,
  SUIT_DIAMONDS,
  SUIT_HEARTS,
  SUIT_SPADES,
  MAX_SUITS
};

struct Card
{
  CardRank rank;
  CardSuit suit;
};

void printCard(const Card &card)
{
  switch (card.rank)
  {
    case RANK_2:      cout << '2';  break;
    case RANK_3:      cout << '3';  break;
    case RANK_4:      cout << '4';  break;
    case RANK_5:      cout << '5';  break;
    case RANK_6:      cout << '6';  break;
    case RANK_7:      cout << '7';  break;
    case RANK_8:      cout << '8';  break;
    case RANK_9:      cout << '9';  break;
    case RANK_10:     cout << 'T';  break;
    case RANK_JACK:   cout << 'J';  break;
    case RANK_QUEEN:  cout << 'Q';  break;
    case RANK_KING:   cout << 'K';  break;
    case RANK_ACE:    cout << 'A';  break;

    default:          cout << 'X';
  }
  switch (card.suit)
  {
    case SUIT_SPADES:   cout << 'S';  break;
    case SUIT_HEARTS:   cout << 'H';  break;
    case SUIT_CLUBS:    cout << 'C';  break;
    case SUIT_DIAMONDS: cout << 'D';  break;

    default:            cout << 'x';
  }
}







//returns the point value of a card depending on its rank
int getCardValue(const Card &card)
{
  switch (card.rank) {
    case RANK_2:      return 2;
    case RANK_3:      return 3;
    case RANK_4:      return 4;
    case RANK_5:      return 5;
    case RANK_6:      return 6;
    case RANK_7:      return 7;
    case RANK_8:      return 8;
    case RANK_9:      return 9;
    case RANK_10:
    case RANK_JACK:
    case RANK_QUEEN:
    case RANK_KING:   return 10;
    case RANK_ACE:    return 11;

    default:          return 0;
  }
}

//taking user input to determine whether to take a card or skip the turn
bool hitOrStand()
{
  char *option = new char;
  while(true)
  {
    cout << "Do you wish to hit or stand? (h/s): ";
    cin >> *option;

    if(cin.fail() || (*option != 'h' && *option != 's'))
    {
      cin.clear();
      cin.ignore(32767,'\n');
      cout << "\nWrong input!\n\n";
    }
    else
    {
      cin.ignore(32767,'\n');
      cout << '\n';
      if(*option == 'h')
        return true; //in case of a hit
      else
        return false; //in case of a stand
    }
  }
}

int main()
{

  //set up the random number generator
  srand(static_cast<unsigned int>(time(0)));

  //array for the card deck
  array<Card, MAX_RANKS * MAX_SUITS> cardDeck;
  int *card = new int;
  *card = 0;

  //create the cards for the deck


  cout << "Shuffling cards...\n\n";

  shuffleDeck(cardDeck);
  printDeck(cardDeck);

  //initialize the card index that will be used to receive card value
  int *currentCardIndex = new int;
  *currentCardIndex = 0;

  //initialize player and dealer score
  int *playerScore = new int;
  int *dealerScore = new int;

  cout << "\n\n";

  //set initial player cards and score
  cout << player_gets_cards;
  printCard(cardDeck[*currentCardIndex]);
  *playerScore = getCardValue(cardDeck[*currentCardIndex]);
  ++*currentCardIndex;
  cout << ' ';
  printCard(cardDeck[*currentCardIndex]);
  *playerScore += getCardValue(cardDeck[*currentCardIndex]);
  cout << " (score: " << *playerScore << ")\n";
  ++*currentCardIndex;

  //set initial dealer cards and score
  cout << dealer_gets_card;
  printCard(cardDeck[*currentCardIndex]);
  *dealerScore = getCardValue(cardDeck[*currentCardIndex]);
  cout << " (score: " << *dealerScore << ")\n";
  ++*currentCardIndex;

  //initial check for draw
  if(*playerScore <= 21 && *dealerScore <= 21 && *playerScore == *dealerScore)
  {
    cout << "\nIt's a draw! :D";
    return 0;
  }

  //initial check for lost
  if(*playerScore > 21 || *dealerScore == 21)
  {
    cout << "\nYou lost :(";
    return 0;
  }

  //initial check for win
  if(*dealerScore > 21 || *playerScore == 21)
  {
    cout << "\nYou won! :D";
    return 0;
  }

  cout << '\n';

  while(true)
  {

    //players move
    if(hitOrStand())
    {
      cout << player_gets_card;
      printCard(cardDeck[*currentCardIndex]);
      *playerScore += getCardValue(cardDeck[*currentCardIndex]);
      cout << " (score: " << *playerScore << ")\n";
      ++*currentCardIndex;
    }
    else
    {
      cout << player_skips_turn << " (score: " << *playerScore << ")\n";
    }

    //game draw for player check
    if(*playerScore <= 21 && *dealerScore <= 21 && *playerScore == *dealerScore)
    {
      cout << "It's a draw! :D";
      break;
    }

    //game lost for player check
    if(*playerScore > 21)
    {
      cout << "You lost :(";
      break;
    }

    //game won for player check
    if(*playerScore > *dealerScore && *dealerScore >= 17)
    {
      cout << "You won! :D";
      break;
    }

    //dealers move
    if(*dealerScore < 17)
    {
      cout << dealer_gets_card;
      printCard(cardDeck[*currentCardIndex]);
      *dealerScore += getCardValue(cardDeck[*currentCardIndex]);
      cout << " (score: " << *dealerScore << ")\n";
      ++*currentCardIndex;
    }
    else
    {
      cout << dealer_skips_turn;
      cout << " (score: " << *dealerScore << ")\n";
      ++*currentCardIndex;
    }

    if(*dealerScore > 21)
    {
      cout << "You won! :D";
      break;
    }

    cout << '\n';
  }

}

*/
