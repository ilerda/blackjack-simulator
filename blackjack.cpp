#include "blackjack.h"
#include "cards.h"

#include <iostream>
#include <limits>

void drawCard(Deck& deck, Index& index, int& score, int& aces)
{
    // This function draws a card. We modify the index, score and number of
    // aces drawn.
    int new_value {getCardValue(deck[index++])};
    score += new_value;
    if (new_value == 11) aces += 1;
}

void candidateTurn(Deck& deck, Index& index, int& score, int& aces, bool isPlayer)
{
    // Either the player or dealer takes one turn.
    const char* candidate {isPlayer ? "Player" : "Dealer"};
    std::cout << candidate << " draws a card: ";
    printCardHR(deck[index]);
    drawCard(deck, index, score, aces);
    
    while (score > 21 and aces > 0)
    {
        score -= 10;
        --aces;
    }
}

bool promptPlayer()
{
    // Ask if player wants to draw another card.
    std::cout << "Hit (h) or Stand (s)?";
    char answer {};
    std::cin >> answer;
    // Extraction should not fail since it is a char, but if too many characters
    // are entered, we will clear the buffer.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (answer != 'h' and answer != 'H')
    {
        return false;
    }
    return true;
}

Outcome playBlackjack(Deck shuffledDeck)
{
    return Outcome::Win;
}
