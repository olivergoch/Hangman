#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    Hangman();
    void drawGame();
    void draw();
    string update(char c);
    bool isGameOver();
    void eraseLetters(char c, int index);
    bool guessLetters(char c);
    void wordGenerator();
    bool gameWon();
private:
    bool wrong[7];
    bool letters[26];
    int count;
    double guesses;
    double right;
    double percentage;
    string top;
    string mid;
    string base;
    string head;
    string body;
    string arm1;
    string arm2;
    string leg1;
    string leg2;
    string lose;
    string letters1;
    string letters2;
    string letters3;
    string letters4;
    string letters5;
    string guess;
    string words;
};


Hangman::Hangman()
{
    wordGenerator();
    for(int i = 0; i < 7; i++)
        wrong[i] = false;
    for(int i = 0; i < 26; i++)
        letters[i] = false;
    count = 0;
    top = "       ";
    mid = " ";
    base = "     ";
    head = " ";
    body = " ";
    arm1 = " ";
    arm2 = " ";
    leg1 = "  ";
    leg2 = "  ";
    lose = "         ";
    letters1 = "abcde";
    letters2 = "fghijk";
    letters3 = "lmnop";
    letters4 = "qrstu";
    letters5 = "vwxyz";
    int guesses = 0;
    int right = 0;
    int percentage = 0;
}

void Hangman::wordGenerator()
{
    srand(time(NULL));
    int rnd = rand() % 4;
    switch (rnd)
    {
        case 0:
            words = "hello";
            break;
        case 1:
            words = "expedition";
            break;
        case 2:
            words = "andromeda";
            break;
        case 3:
            words = "mass";
            break;
        default:
            exit(1);
            break;
    }
    for(int i = 0; i < words.size(); i++)
    {
        guess += '_';
    }
}

void Hangman::drawGame()
{
    system("clear");
    cout << '\n' << "Hangman!" << endl;
    cout << "Letter Bank:" << endl;
    cout << "  " << letters1  << "     " << top << endl;;
    cout << "  " << letters2 <<"    " << head << "     " << mid << endl;
    cout << "  " << letters3 <<"    " <<  arm1 << body << arm2 << "    " << mid << endl;
    cout << "  " << letters4 << '\t' << "   " << leg1 << leg2 << " " << base << endl;
    cout << "  " << letters5 << '\t' << "   " << lose << endl;
    cout << "Guess the word:" << endl;
    cout << guess << endl;
    cout.precision(3);
    cout << "Guesses made: " << guesses << endl;
    cout << "Percentage right " << percentage << "%" << endl;
    cout << "Make a Guess: ";
}

void Hangman::draw()
{
    if(wrong[0])
    {
        top = "_______";
        mid = "|";
        base = "__|__";
    }
    if(wrong[1])
        head = "O";
    if(wrong[2])
        body = "|";
    if(wrong[3])
        arm1 = "-";
    if(wrong[4])
        arm2 = "-";
    if(wrong[5])
        leg1 = "./";
    if(wrong[6])
    {
        leg2 = "\\.";
        lose = "game over";
    }
    drawGame();
}

void Hangman::eraseLetters(char c, int index)
{
    if(index >= 0 && index <= 4)
    {
        for(int i = 0; i < 5; i++)
        {
            if(letters1[i] == c)
                letters1[i] = '_';
        }
    }
    if(index >= 5 && index <= 10)
    {
        for(int i = 0; i < 6; i++)
        {
            if(letters2[i] == c)
                letters2[i] = '_';
        }
    }
    if(index >= 11 && index <= 15)
    {
        for(int i = 0; i < 6; i++)
        {
            if(letters3[i] == c)
                letters3[i] = '_';
        }
    }
    if(index >= 16 && index <= 20)
    {
        for(int i = 0; i < 6; i++)
        {
            if(letters4[i] == c)
                letters4[i] = '_';
        }
    }
    if(index >= 21 && index <= 25)
    {
        for(int i = 0; i < 6; i++)
        {
            if(letters5[i] == c)
                letters5[i] = '_';
        }
    }
}

bool Hangman::guessLetters(char c)
{
    bool guessedRight = false;
    for(int i = 0; i < words.size(); i++)
    {
        if(words[i] == c)
        {
            guess[i] = words[i];
            guessedRight = true;
        }
    }
    return guessedRight;
}

string Hangman::update(char c)
{
    string statement = "Error!";
    c = tolower(c);
    int index = c % 97;
    if(!letters[index])
    {
        letters[index] = true;
        eraseLetters(c, index);
        if(guessLetters(c))
        {
            guesses++;
            right++;
            statement = "Correct!";
        }
        else
        {
            wrong[count] = true;
            count++;
            guesses++;
            statement = "Wrong!";
        }
    }
    else
        statement = "You already entered that letter";
    percentage = right/guesses * 100;
    return statement + "\n"+ "Press Enter to continue";
}

bool Hangman::isGameOver()
{
    return wrong[6] == true;
}

bool Hangman::gameWon()
{
    for(int i = 0; i < guess.size(); i++)
    {
        if(guess[i] == '_')
            return false;
    }
    lose = "You win!";
    return true;
}

int main()
{
    Hangman h;
    while(!h.isGameOver() && !h.gameWon())
    {
        h.draw();
        char input;
        cin >> input;
        cin.ignore(10000, '\n');
        cout << h.update(input) << endl;
        cin.ignore(10000, '\n');
    }
    if(h.isGameOver())
        h.draw();
    if(h.gameWon())
        h.draw();
    cout << endl;
}
