#include "cards.h"

#include <array>
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

std::array<Card, 52> createDeck()
{
    // Create one standard 52 card deck, that will initially be sorted.
    std::array<Card, 52> deck {};
    int max_suits {static_cast<int>(CardSuit::Max_suits)};
    int max_rank {static_cast<int>(CardRank::Max_ranks)};
    for (int i {0}; i < max_suits; ++i)
    {
        for (int j {0}; j < max_rank; ++j)
        {
            Card newCard {static_cast<CardRank>(j), static_cast<CardSuit>(i)};
            deck[static_cast<std::array<Card, 52>::size_type>(i*max_rank + j)] = newCard;
        }
    }
    return deck;
}

void printDeck(const std::array<Card, 52>& deck)
{
    // Print all the cards in the deck.
    for (Card card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}
