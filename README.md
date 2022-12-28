# Blackjack Simulator

Text based Blackjack Simulator using one deck of cards.
It includes functions for shuffling the deck, printing the output and playing one round of simplified Blackjack.

Could be used as the basis for a full Blackjack simulator with a graphical user interface.

In order to build the program, include the files blackjack.cpp, card_game.cpp and main.cpp.
For example, with gnu you should run:

`g++ -o blackjack --std=c++17 blackjack.cpp card_game.cpp main.cpp`

and then execute:

`./blackjack`

This will drop you into a text prompt for one game of Blackjack.

It has also been tested with the C++20 Standard.

The rules of Blackjack: https://en.wikipedia.org/wiki/Blackjack
