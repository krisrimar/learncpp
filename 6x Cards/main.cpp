#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <ctime>

using namespace std;

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
  cout << '\n';
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//goes throught the each element of the card deck and prints it
void printDeck(const array<Card, MAX_RANKS * MAX_SUITS> &deck)
{
  for(const auto &card : deck)
  {
    printCard(card);
  }
}

//swaps values of two cards in the deck array
void swapCards(Card &card1, Card &card2)
{
  swap(card1, card2);
}

//swaps the card at current index with a card at random index
void shuffleDeck(array<Card, MAX_RANKS * MAX_SUITS> &deck)
{
  for(int index = 0; index < MAX_RANKS * MAX_SUITS; ++index)
  {
    swapCards(deck[index], deck[getRandomNumber(1,(MAX_RANKS * MAX_SUITS -1))]);
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
  for(int suit = 0; suit < MAX_SUITS; ++suit)
  {
    for(int rank = 0; rank < MAX_RANKS; ++rank)
    {
      cardDeck[*card].rank = static_cast<CardRank>(rank);
      cardDeck[*card].suit = static_cast<CardSuit>(suit);
      ++(*card);
    }
  }

  shuffleDeck(cardDeck);
  printDeck(cardDeck);

}
