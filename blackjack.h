#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "cards.h"

enum class Outcome {
    Win, Loss, Tie
};

Outcome playBlackjack(Deck shuffledDeck);

#endif
