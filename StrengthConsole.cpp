#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::vector<int> black_cards = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
std::vector<int> white_cards = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int player_black;
int player_white;

int black_card;
int white_card;

int player_black_score = 0;
int player_white_score = 0;
int tie_score = 0;

void checkNum(int check, std::string type)
{
    if (type == "player_white")
    {
        auto it = std::find(white_cards.begin(), white_cards.end(), check);
        if (it != white_cards.end())
        {
            std::cout << "\nYou have chosen " << check << " for player white\n";
            white_cards.erase(it);
            white_card = check;
        }
        else
        {
            if (!white_cards.empty())
            {
                check = white_cards.front();
                checkNum(check, "player_white");
            }
        }
    }
    else
    {
        auto it = std::find(black_cards.begin(), black_cards.end(), check);
        if (it != black_cards.end())
        {
            std::cout << "You have chosen " << check << " for player black\n";
            black_cards.erase(it);
            black_card = check;
        }
        else
        {
            std::cout << check << " is not in the black card deck. Choose another card: ";
            while (!(std::cin >> player_black)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid number: ";
            }
            checkNum(player_black, "player_black");
        }
    }
}

int main()
{
    std::srand(std::time(0));
    std::cout << "Begin game, player black\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Enter a number for player black: ";
        while (!(std::cin >> player_black)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        checkNum(player_black, "player_black");

        if (!white_cards.empty())
        {
            player_white = white_cards[std::rand() % white_cards.size()];
            checkNum(player_white, "player_white");
        }

        if (black_card > white_card)
        {
            std::cout << "Player black scores\n";
            player_black_score++;
        }
        else if (black_card < white_card)
        {
            std::cout << "Player white scores\n";
            player_white_score++;
        }
        else
        {
            std::cout << "Tie between players\n";
            tie_score++;
        }
    }

    if (player_black_score > player_white_score)
    {
        std::cout << "Player black wins, player white loses!" << std::endl;
    }
    else if (player_black_score < player_white_score)
    {
        std::cout << "Player white wins, player black loses!" << std::endl;
    }
    else
    {
        std::cout << "Player white and black have ended in a draw!" << std::endl;
    }
    while (true)
    {

    }
    return 0;
}
