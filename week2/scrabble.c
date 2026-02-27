#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word);
string check_winner(int score_player_1, int score_player_2);

int main(void)
{
    string word_player_1 = get_string("Player 1: ");
    string word_player_2 = get_string("Player 2: ");
    int score_player_1 = calculate_score(word_player_1);
    int score_player_2 = calculate_score(word_player_2);
    string winner = check_winner(score_player_1, score_player_2);
    printf("%s", winner);
}

int calculate_score(string word)
{
    int letter_points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                           1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    const char ASCII_TO_LETTER_UPPER = 'A';
    const char ASCII_TO_LETTER_LOWER = 'a';
    int score = 0;
    int i = 0;

    while (word[i] != '\0')
    {
        if isupper (word[i])
        {
            score += letter_points[word[i] - ASCII_TO_LETTER_UPPER];
        }
        else if islower (word[i])
        {
            score += letter_points[word[i] - ASCII_TO_LETTER_LOWER];
        }

        i++;
    }
    return score;
}

string check_winner(int score_player_1, int score_player_2)
{
    if (score_player_1 > score_player_2)
    {
        return "Player 1 wins\n";
    }
    else if (score_player_1 < score_player_2)
    {
        return "Player 2 wins\n";
    }
    else
    {
        return "Tie!\n";
    }
}
