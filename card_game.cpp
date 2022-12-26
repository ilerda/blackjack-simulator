#include "cards.h"

#include <iostream>

void printCard(const Card& card)
{
    // Print the face value of a card as a two character code.
    char suitchar {};
    char rankchar {};

    switch (card.rank)
    {
        case CardRank::R2: rankchar = '2'; break;
        case CardRank::R3: rankchar = '3'; break;
        case CardRank::R4: rankchar = '4'; break;
        case CardRank::R5: rankchar = '5'; break;
        case CardRank::R6: rankchar = '6'; break;
        case CardRank::R7: rankchar = '7'; break;
        case CardRank::R8: rankchar = '8'; break;
        case CardRank::R9: rankchar = '9'; break;
        case CardRank::R10: rankchar = 'T'; break;
        case CardRank::RJ: rankchar = 'J'; break;
        case CardRank::RQ: rankchar = 'Q'; break;
        case CardRank::RK: rankchar = 'K'; break;
        case CardRank::RA: rankchar = 'A'; break;
        default: rankchar = '?'; break;
    }
    switch (card.suit)
    {
        case CardSuit::Clubs: suitchar = 'C'; break;
        case CardSuit::Diamonds: suitchar = 'D'; break;
        case CardSuit::Hearts: suitchar = 'H'; break;
        case CardSuit::Spades: suitchar = 'S'; break;
        default: suitchar = '?'; break;
    }

    std::cout << rankchar << suitchar;
}