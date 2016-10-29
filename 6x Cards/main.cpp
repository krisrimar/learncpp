#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <ctime>

using namespace std;

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
    cout << ' ';
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
    swapCards(deck[index], deck[getRandomNumber(0,(MAX_RANKS * MAX_SUITS -1))]);
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
  for(int suit = 0; suit < MAX_SUITS; ++suit)
  {
    for(int rank = 0; rank < MAX_RANKS; ++rank)
    {
      cardDeck[*card].rank = static_cast<CardRank>(rank);
      cardDeck[*card].suit = static_cast<CardSuit>(suit);
      ++(*card);
    }
  }

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
