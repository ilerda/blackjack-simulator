#ifndef CARDS_H
#define CARDS_H

enum class CardRank {
    R2, R3, R4, R5, R6, R7, R8, R9, R10, RJ, RQ, RK, RA,
    Max_ranks
};

enum class CardSuit {
    Clubs, Diamonds, Hearts, Spades,
    Max_suits
};

struct Card {
    CardRank rank {};
    CardSuit suit {};
};

#endif
