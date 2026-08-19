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

int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;

    return 0;
}