#include <iostream>
#include <string>
using namespace std;

//Declarations
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
    bool doneAndDone(char &c);
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

//Constuctor
Hangman::Hangman()
{
    //generate word for game
    wordGenerator();
    //set all wrong and letters to false
    //wrong is number of guesses
    //letters is the letters you can guess
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
    //this shows percentages
    int guesses = 0;
    int right = 0;
    int percentage = 0;
}

//Word Generator
void Hangman::wordGenerator()
{
    srand(time(NULL));
    int rnd = rand() % 26;
    switch (rnd)
    {
        case 0:
            words = "awkward";
            break;
        case 1:
            words = "expedition";
            break;
        case 2:
            words = "knowledge";
            break;
        case 3:
            words = "leading";
            break;
        case 4:
            words = "beautiful";
            break;
        case 5:
            words = "goodbye";
            break;
        case 6:
            words = "flowers";
            break;
        case 7:
            words = "cheese";
            break;
        case 8:
            words = "yellow";
            break;
        case 9:
            words = "beekeeper";
            break;
        case 10:
            words = "espionage";
            break;
        case 11:
            words = "fluffiness";
            break;
        case 12:
            words = "brother";
            break;
        case 13:
            words = "sister";
            break;
        case 14:
            words = "question";
            break;
        case 15:
            words = "answer";
            break;
        case 16:
            words = "abruptly";
            break;
        case 17:
            words = "exodus";
            break;
        case 18:
            words = "haphazard";
            break;
        case 19:
            words = "jawbreaker";
            break;
        case 20:
            words = "keyhole";
            break;
        case 21:
            words = "microwave";
            break;
        case 22:
            words = "pnuemonia";
            break;
        case 23:
            words = "subway";
            break;
        case 24:
            words = "unknown";
            break;
        case 25:
            words = "whatever";
            break;
        case 26:
            words = "vegetable";
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

//Draw Game
void Hangman::drawGame()
{
    //draw all the things
    system("clear");
    cout << "\t" <<"  ___ ___" << endl
    << "\t"<< " /   |   \\_____    ____    ____   _____ _____    ____" << endl
    << "\t"<<"/    ~    \\__  \\  /    \\  / ___\\ /     \\\\__  \\  /    \\" << endl
    << "\t"<<"\\    Y    // __ \\|   |  \\/ /_/  >  Y Y  \\/ __ \\|   |  \\" << endl
    << "\t"<<" \\___|_  /(____  /___|  /\\___  /|__|_|  (____  /___|  /" << endl
    << "\t" <<"       \\/      \\/     \\//_____/       \\/     \\/     \\/" << endl;
    cout << "\t\t\t" << "Letter Bank:" << endl;
    cout << "\t\t\t" << "  " << letters1  << "     " << top << endl;;
    cout << "\t\t\t" << "  " << letters2 <<"    " << head << "     " << mid << endl;
    cout << "\t\t\t" << "  " << letters3 <<"    " <<  arm1 << body << arm2 << "    " << mid << endl;
    cout << "\t\t\t" << "  " << letters4 << '\t' << "   " << leg1 << leg2 << " " << base << endl;
    cout << "\t\t\t" << "  " << letters5 << '\t' << "   " << lose << endl;
    cout << "\t\t\t" << "Guess the word:" << endl;
    cout << "\t\t\t" << guess << endl;
    cout.precision(3);
    cout << "\t\t\t" << "Guesses made: " << guesses << endl;
    cout << "\t\t\t" << "Percentage right " << percentage << "%" << endl;
    cout << "\t\t\t" << "Make a Guess: ";
}

//Draw the Hangman
void Hangman::draw()
{
    //this is the hangman itself
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

//Erase Letters
void Hangman::eraseLetters(char c, int index)
{
    //this is a bit convoluted
    //but basically when a letter is typed
    //and it hasn't already been typed
    //it gets erased
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

//Guess Letters
bool Hangman::guessLetters(char c)
{
    //check if the letter guessed is correct
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

//Update
string Hangman::update(char c)
{
    //basically cheats so I can skip around
    if(c == '0')
    {
        wrong[6] = true;
        return "\t\t\tSKIP!";
    }
    if(c == '1')
        exit(1);
    string statement = "\t\t\tError!";
    c = tolower(c);
    int index = c % 97;
    //if the letter hasn't been guessed already
    if(!letters[index])
    {
        //set the index to true and erase it from word bank
        letters[index] = true;
        eraseLetters(c, index);
        //check if word is actually there
        if(guessLetters(c))
        {
            guesses++;
            right++;
            statement = "\t\t\tCorrect!";
        }
        else
        {
            wrong[count] = true;
            count++;
            guesses++;
            statement = "\t\t\tWrong!";
        }
    }
    else
        statement = "\t\t\tYou already entered that letter";
    percentage = right/guesses * 100;
    return statement + "\n"+ "\t\t\tPress Enter to continue";
}

//Is Game Over
bool Hangman::isGameOver()
{
    return wrong[6] == true;
}

//Game Won
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

//Done and Done
bool Hangman::doneAndDone(char &c)
{
    if(tolower(c) == 'a')
        return false;
    else if (tolower(c) == 'b')
        return true;
    else
    {
        cout << "Enter A or B" << endl;
        c = 'x';
    }
    return false;
}

int main()
{
    system("clear");
    string titleScreen = "a";
    while(!titleScreen.empty())
    {
        //cout << "\t\t\tWelcome to Hangman!" << endl
        cout <<
        " __      __       .__" << endl
        <<"/  \\    /  \\ ____ |  |   ____  ____   _____   ____" << endl
        <<"\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\" << endl
        << " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/" << endl
        <<"  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >" << endl
        <<"       \\/       \\/          \\/            \\/     \\/" << endl
        <<"___________" << endl
        <<"\\__    ___/___" << endl
        <<"  |    | /  _ \\" << endl
        <<"  |    |(  <_> )"<< endl
        <<"  |____| \\____/" << endl
        
        <<"  ___ ___" << endl
        <<" /   |   \\_____    ____    ____   _____ _____    ____" << endl
        <<"/    ~    \\__  \\  /    \\  / ___\\ /     \\\\__  \\  /    \\" << endl
        <<"\\    Y    // __ \\|   |  \\/ /_/  >  Y Y  \\/ __ \\|   |  \\" << endl
        <<" \\___|_  /(____  /___|  /\\___  /|__|_|  (____  /___|  /" << endl
        <<"       \\/      \\/     \\//_____/       \\/     \\/     \\/" << endl;
        
        cout<< "\t\t      Press enter to continue"<< endl;
        getline(cin, titleScreen);
    }
    
RESTART:
    Hangman h;
    bool doneForever = false;
    while(!h.isGameOver() && !h.gameWon() && !doneForever)
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
    string line = "A";
    while(!line.empty())
    {
        cout << "Press Enter to continue";
        getline(cin, line);
    }
    if(h.isGameOver() || h.gameWon())
    {
        system("clear");
        cout << "\t\t\tDo you want to play again" << endl;
        cout << "\t\t\t  Enter A to play again" << endl;
        cout << "\t\t\t    Enter B to quit" << endl;
        cout << "\t\t\tEnter your choice here: ";
        char otherinput;
    INPUT:
        cin >> otherinput;
        if(h.doneAndDone(otherinput))
            doneForever = true;
        else if (otherinput == 'a')
            goto RESTART;
        else
            goto INPUT;
    }
}
