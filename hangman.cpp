#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
const int TRIES = 5;

int guess(char letter, string answer, string &word)
{
    int correct = 0;
    for (int i = 0; i < answer.length(); ++i)
    {
        if (letter == word[i])
        {
            return 0;
        }
        if (letter == answer[i])
        {
            word[i] = letter;
            ++correct;
        }
    }
    return correct;
}

int main()
{
    string name, answer;
    char letter;
    int wrong = 0;
    string words[] = {"india",
                      "pakistan",
                      "nepal",
                      "malaysia",
                      "philippines",
                      "australia",
                      "iran",
                      "ethiopia",
                      "oman",
                      "indonesia"};
    srand(time(NULL));
    int index = rand() % 10;
    answer = words[index];
    string word(answer.length(), '_');
    printf("\t\t\t\t\t\tHangman by Aryan\n");
    printf("\t\t\t\t\tYou have %d tries to guess the country\n", TRIES);
    printf("\t\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n");
    while (wrong < TRIES)
    {
        cout << "\n\n\t\t\t\t\t\t" << word << "\n\n";
        printf("Guess: ");
        cin >> letter;
        if (guess(letter, answer, word) == 0)
        {
            printf("\n\t\t\t\t\t\tWrong guess\n");
            ++wrong;
        }
        else
        {
            printf("\n\t\t\t\t\t\tCorrect guess\n");
        }
        printf("\t\t\t\t\t\t%d guesses left\n", TRIES - wrong);
        if (answer == word)
        {
            cout << "\t\t\t\t\t" << word << " guessed correctly";
            break;
        }
    }

    if (wrong == TRIES)
    {
        printf("\n\n\t\t\t\t\tYou have been hanged by the hangman\n");
        printf("\t\t\t\t\t\tThe word was ");
        cout << answer << "\n";
    }
    cin.ignore();
    cin.get();
    return 0;
}