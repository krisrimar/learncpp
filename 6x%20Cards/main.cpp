#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

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

void printDeck(const array<Card, MAX_RANKS * MAX_SUITS> &deck)
{
  for(const auto &card : deck)
    printCard(card);
    cout << ' ';
}

void swapCards(Card &card1, Card &card2)
{
  printCard(card1);
  printCard(card2);
  swap(card1, card2);
  cout << "\n\n";
  printCard(card1);
  printCard(card2);
}

int main()
{

  array<Card, MAX_RANKS * MAX_SUITS> cardDeck;
  int *card = new int;
  *card = 0;

  for(int suit = 0; suit < MAX_SUITS; ++suit)
  {
    for(int rank = 0; rank < MAX_RANKS; ++rank)
    {
      cardDeck[*card].rank = static_cast<CardRank>(rank);
      cardDeck[*card].suit = static_cast<CardSuit>(suit);
      ++(*card);
    }
  }

  cout << "\n\n";

  printDeck(cardDeck);

  cout << "\n\n";

  swapCards(cardDeck[0], cardDeck[1]);

}
