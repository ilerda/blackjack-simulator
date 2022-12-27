#include "blackjack.h"

#include <iostream>

int main()
{
    Deck deck {createDeck()};
    shuffleDeck(deck);
    // Uncomment this function call for debugging (or cheating!)
    // printDeck(deck);
    Outcome result {playBlackjack(deck)};
    switch (result)
    {
    case Outcome::Win:
        std::cout << "You win!\n";
        break;
    case Outcome::Loss:
        std::cout << "You lose.\n";
        break;
    case Outcome::Tie:
        std::cout << "Result is a tie.\n";
        break;
    
    default:
        std::cout << "Undefined.\n";
        break;
    }

    return 0;
}