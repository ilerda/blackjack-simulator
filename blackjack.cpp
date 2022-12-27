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
    // All the steps for for one round of Blackjack
    int player_score {0};
    int dealer_score {0};
    int player_aces {0};
    int dealer_aces {0};
    Index draw_index {0};

    // Starting draws
    std::cout << "Dealer draws the first card: ";
    printCardHR(shuffledDeck[draw_index]);
    drawCard(shuffledDeck, draw_index, dealer_score, dealer_aces);

    std::cout << "Player draws their first card: ";
    printCardHR(shuffledDeck[draw_index]);
    drawCard(shuffledDeck, draw_index, player_score, player_aces);

    // Player turn
    bool keep_playing {true};
    while (keep_playing)
    {
        candidateTurn(shuffledDeck, draw_index, player_score, player_aces, true);
        std::cout << "Your Score: " << player_score << ". Dealer Score: " << dealer_score << ".\n";

        if (player_score == 21)
        {
            return Outcome::Win;
        }
        else if (player_score > 21)
        {
            return Outcome::Loss;
        }
        else
        {
            keep_playing = promptPlayer();
        }
    }

    // Dealer turn
    std::cout << "Dealer's turn.\n";
    while (dealer_score < 17)
    {
        candidateTurn(shuffledDeck, draw_index, dealer_score, dealer_aces, false);
        std::cout << "Your Score: " << player_score << ". Dealer Score: " << dealer_score << ".\n";
    }

    // Final score checking.
    if (dealer_score > 21)
    {
        return Outcome::Win;
    }

    if (dealer_score > player_score)
    {
        return Outcome::Loss;
    }
    else if (dealer_score == player_score)
    {
        return Outcome::Tie;
    }
    return Outcome::Win;
}
