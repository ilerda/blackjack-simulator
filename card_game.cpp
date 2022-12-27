#include "cards.h"

#include <cassert>
#include <iostream>
#include <random>
#include <string>

// This contains the logic for creating and managing a deck of cards.

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

void printCardHR(const Card& card)
{
    // Human readable implementation of printCard()
    std::string suitchar {};
    std::string rankchar {};

    switch (card.rank)
    {
        case CardRank::R2: rankchar = "2"; break;
        case CardRank::R3: rankchar = "3"; break;
        case CardRank::R4: rankchar = "4"; break;
        case CardRank::R5: rankchar = "5"; break;
        case CardRank::R6: rankchar = "6"; break;
        case CardRank::R7: rankchar = "7"; break;
        case CardRank::R8: rankchar = "8"; break;
        case CardRank::R9: rankchar = "9"; break;
        case CardRank::R10: rankchar = "10"; break;
        case CardRank::RJ: rankchar = "Jack"; break;
        case CardRank::RQ: rankchar = "Queen"; break;
        case CardRank::RK: rankchar = "King"; break;
        case CardRank::RA: rankchar = "Ace"; break;
        default: rankchar = "?"; break;
    }
    switch (card.suit)
    {
        case CardSuit::Clubs: suitchar = "Clubs"; break;
        case CardSuit::Diamonds: suitchar = "Diamonds"; break;
        case CardSuit::Hearts: suitchar = "Hearts"; break;
        case CardSuit::Spades: suitchar = "Spades"; break;
        default: suitchar = "?"; break;
    }

    std::cout << rankchar << " of " << suitchar << '\n';
}

Deck createDeck()
{
    // Create one standard 52 card deck, that will initially be sorted.
    Deck deck {};
    int max_suits {static_cast<int>(CardSuit::Max_suits)};
    int max_rank {static_cast<int>(CardRank::Max_ranks)};
    for (int i {0}; i < max_suits; ++i)
    {
        for (int j {0}; j < max_rank; ++j)
        {
            Card newCard {static_cast<CardRank>(j), static_cast<CardSuit>(i)};
            deck[static_cast<Index>(i*max_rank + j)] = newCard;
        }
    }
    return deck;
}

void printDeck(const Deck& deck)
{
    // Print all the cards in the deck.
    for (Card card : deck)
    {
        printCard(card);
        std::cout << ' ';
    }
    std::cout << '\n';
}

void shuffleDeck(Deck& deck)
{
    // Using a reference to the deck, shuffle it with a Mersenne Twister.
    static std::mt19937 mt {static_cast<std::mt19937::result_type>(std::time(nullptr))};
    std::shuffle(deck.begin(), deck.end(), mt);
}

int getCardValue(const Card& card)
{
    // Get the face value of one card.
    // Aces can have value 11 or 1, whichever is more advantageous to the player.
    // This is taken care of in the calling function.
    switch (card.rank)
    {
        case CardRank::R2: return 2;
        case CardRank::R3: return 3;
        case CardRank::R4: return 4;
        case CardRank::R5: return 5;
        case CardRank::R6: return 6;
        case CardRank::R7: return 7;
        case CardRank::R8: return 8;
        case CardRank::R9: return 9;
        case CardRank::R10: return 10;
        case CardRank::RJ: return 10;
        case CardRank::RQ: return 10;
        case CardRank::RK: return 10;
        case CardRank::RA: return 11;
        default:
            assert(false && "Should never happen");
            return 0;
    }
}
