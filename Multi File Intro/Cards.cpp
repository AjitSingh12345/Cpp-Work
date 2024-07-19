#include <iostream>
#include <cassert> // for assert
#include <cstdint> // for fixed width integers
#include <string_view>
#include <array>
#include <vector>
#include <algorithm> // for std::shuffle
#include "Random.h"  // for Random::mt

struct Card {
    enum Rank {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        max_rank
    };

    enum Suit {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,
        max_suit
    };

    // MAKE THESE STATIC SO THEYRE CREATED ONCE PER PROGRAM, NOT ONCE PER CARD OBJECT
    // STATIC MEANS 1 COPY WILL BE USED BY ALL INSTANCES OF THE CLASS
    static constexpr std::array allRanks { 
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king
    };

    static constexpr std::array allSuits {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,
    };

    static constexpr std::array<int, max_rank> rank_values {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    static constexpr std::array<char, max_rank> rank_names {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr std::array<char, max_suit> suit_names {'C', 'D', 'H', 'S'};

    // compiler automatically proces defualt construct that inits all fields to their default vals
    // by nature, all fields of a struct must be init to some value
    // struct cannot have param-less constructor
    // theres no way around paramless construc being implicitly called
    // if u need constructors, use class
    Rank rank {};
    Suit suit {};

    int getCardValue() const {
        return rank_values[rank];
    }

    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {
        out << card.rank_names[card.rank] << card.suit_names[card.suit];
        return out;
    }
};

class Deck {
public:
    static constexpr int deck_size = 52;

    Deck() {
        int card = 0;
        for (auto& suit : Card::allSuits) {
            for (auto& rank : Card::allRanks) {
                deck[card++] = Card {rank, suit};
            }
        }
    }

    Card dealCard() {
        assert(curr_card < deck_size);
        return deck[curr_card++];
    }

    void shuffle() {
        std::shuffle(deck.begin(), deck.end(), Random::mt);
        curr_card = 0;
    }
private:
    std::array<Card, deck_size> deck {};
    size_t curr_card = 0;
};

namespace Settings {
    constexpr int player_busts { 21 };
    constexpr int dealer_stop { 17 };
}

struct Player {
    int total_score {0};
};

bool playBlackjackRound() {
    Deck deck{};
    deck.shuffle();

    Player patron { deck.dealCard().getCardValue() + deck.dealCard().getCardValue() };
    Player dealer { deck.dealCard().getCardValue() };

    std::cout << "The dealer is showing: " << dealer.total_score << '\n';
    std::cout << "You have score: " << patron.total_score << '\n';

    // players turn
    while (patron.total_score <= Settings::player_busts) {
        char turn {};
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> turn;
        if (turn == 'h') {
            Card c = deck.dealCard();
            patron.total_score += c.getCardValue();
            std::cout << "You were dealt " << c << ". You now have: " << patron.total_score << '\n';
        } else {
            break;
        }
    }

    if (patron.total_score > Settings::player_busts) {
        std::cout << "You went bust!\n";
        return false;
    }

    // dealers turn
    while (dealer.total_score < Settings::dealer_stop) {
        Card c = deck.dealCard();
        dealer.total_score += c.getCardValue();
        std::cout << "The dealer flips a " << c << ". They now have: " << dealer.total_score << '\n';
    }

    if (dealer.total_score > Settings::dealer_stop) {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return patron.total_score > dealer.total_score;
}
