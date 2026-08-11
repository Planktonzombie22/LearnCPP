#include <iostream>
#include <vector>
#include "Random.h"

namespace Rules
{
    constexpr int guesses { 6 };
}

namespace WordList
{
    std::vector<std::string_view> words { "mystery", "broccoli" , "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

    std::string_view randomWord()
    {
        return words[Random::get<std::size_t>(0, words.size()-1)];
    }
}

template <typename T>
constexpr std::size_t toUZ(T value)
{
    static_assert(std::is_integral<T>() || std::is_enum<T>());

    return static_cast<std::size_t>(value);
}

class Session
{
private:
    std::string_view m_word { WordList:: randomWord() };
    std::vector<bool> m_guesses { std::vector<bool>(26) };
    std::vector<char> m_guesses_made {};

public:
    std::string_view getWord() const { return m_word; }
    std::vector<bool> getGuesses() const { return m_guesses; }
    std::vector<char> getGuessesMade() const { return m_guesses_made; }
    void updateGuesses(char c) { m_guesses[(c % 32) - 1] = true; m_guesses_made.push_back(c); }
};

void displayState(const Session& s)
{
    std::cout << "The word: ";
    for ([[maybe_unused]] auto c : s.getWord())
    {
        if (s.getGuesses()[(c % 32) - 1])
            std::cout << c;
        else
            std::cout << "_";
    }
    std::cout << "   Wrong guesses: ";

    for (int i {}; i < 6 - s.getGuessesMade().size(); ++i)
        std::cout << "+";
    for (auto c : s.getGuessesMade())
        std::cout << c;
    
    std::cout << '\n';
}


char getGuess(Session& s)
{
    while (true)
    {
        std::cout << "Enter your next letter: ";

        char c{};
        std::cin >> c;

        // If user did something bad, try again
        if (!std::cin)
        {
            // Fix it
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // If the user entered an invalid char, try again
        if (c < 'a' || c > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        if (s.getGuesses()[(c % 32) - 1])
        {
            std::cout << "You already guessed that.  Try again.\n";
            continue;
        }

        return c;
    }
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the word.  To lose: run out of pluses.\n\n";

    Session s {};

    while (s.getGuessesMade().size() <= 6)
    {
        displayState(s);
        char c { getGuess(s) };
        s.updateGuesses(c);
        std::cout << '\n';
    }

    return 0;
}