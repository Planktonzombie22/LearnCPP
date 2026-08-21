#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include "Random.h"

struct Card
{
    static constexpr std::array ranks { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
    static constexpr std::array suits { 'C', 'D', 'H', 'S' };

        enum Rank
    {
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
        
        max_ranks
    };

    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    static constexpr std::array allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
    static constexpr std::array allSuits { suit_club, suit_diamond, suit_heart, suit_spade };

    Rank rank {};
    Suit suit {};

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        return std::cout << ranks[card.rank] << suits[card.suit];
    }

    int value() const
    {
        std::array values {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        return values[rank];
    }
};

class Deck
{
private:
    std::array<Card, 52> m_deck {};
    std::size_t m_deck_index { 0 };

public:
    Deck()
    {
        std::size_t count { 0 };
        for (auto suit: Card::allSuits)
            for (auto rank: Card::allRanks)
                m_deck[count++] = Card{rank, suit};
    }

    void shuffle()
    {
        std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
        m_deck_index = 0;
    }

    Card& dealCard()
    {
        assert(m_deck_index != 52 && "Deck::dealCard ran out of cards");
        return m_deck[++m_deck_index];
    }
};

namespace Settings
{
    constexpr int dealer_stand { 17 };
    constexpr int bust { 21 };
}

struct Player
{
    int score{};
};

bool playBlackjack()
{
    Deck deck{};
    deck.shuffle();

    Player dealer{ deck.dealCard().value() };

    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player { deck.dealCard().value() + deck.dealCard().value() };

    std::cout << "You have score: " << player.score << '\n';

    while (player.score < Settings::bust)
    {
        char action {};
        std::cout << "(h) to hit, or (s) to stand: ";
        std::cin >> action;
        if (action == 's')
        {
            break;
        }

        Card card_dealt { deck.dealCard() };
        std::cout << "You flip a " << card_dealt << ".  ";
        player.score += card_dealt.value();
        std::cout << "You now have: " << player.score << '\n';
    }

    if (player.score > Settings::bust)
    {
        std::cout << "You went bust!\n";
        return false;
    }

    while (dealer.score < Settings::dealer_stand)
    {
        Card card_dealt { deck.dealCard() };
        std::cout << "The dealer flips a " << card_dealt << ".  ";
        dealer.score += card_dealt.value();
        std::cout << "They now have: " << dealer.score << '\n';
    }

    if (dealer.score > Settings::bust)
    {
        std::cout << "The dealer went bust!\n";
        return true;
    }

    return (player.score > dealer.score);
}

int main()
{
    if (playBlackjack())
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}