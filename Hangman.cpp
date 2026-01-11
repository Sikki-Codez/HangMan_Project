#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Global Variables
int MistakeCount = 0, GuessedChars = 0;
char LetterArray[26] = {}; // Tracks guessed letters
const string IncorrectGuess = " _ ";
string OutStr = "";

// Function Prototypes
bool LetterCheck(char Guess);
bool CheckingCharacter(string Country, char Guess, int CountryLength);
void DrawHangman(int mistakes); // <--- NEW FUNCTION

int main()
{
    int RandomChoice, LengthCountry;
    string Temp;
    char Guess;
    bool GuessCheck, UsedCheck;

    // List of countries
    string Countries[195] = {
        "afghanistan", "albania", "algeria", "andorra", "angola", "antigua and barbuda",
        "argentina", "armenia", "australia", "austria", "azerbaijan", "bahamas", "bahrain",
        "bangladesh", "barbados", "belarus", "belgium", "belize", "benin", "bhutan", "bolivia",
        "bosnia and herzegovina", "botswana", "brazil", "brunei", "bulgaria", "burkina faso",
        "burundi", "cabo verde", "cambodia", "cameroon", "canada", "central african republic",
        "chad", "chile", "china", "colombia", "comoros", "congo", "costa rica",
        "croatia", "cuba", "cyprus", "czechia", "denmark", "djibouti", "dominica",
        "dominican republic", "ecuador", "egypt", "el salvador", "equatorial guinea", "eritrea",
        "estonia", "eswatini", "ethiopia", "fiji", "finland", "france", "gabon",
        "gambia", "georgia", "germany", "ghana", "greece", "grenada", "guatemala", "guinea",
        "guinea-bissau", "guyana", "haiti", "honduras", "hungary", "iceland", "india", "indonesia",
        "iran", "iraq", "ireland", "israel", "italy", "jamaica", "japan", "jordan", "kazakhstan",
        "kenya", "kiribati", "korea, north", "korea, south", "kosovo", "kuwait", "kyrgyzstan", "laos",
        "latvia", "lebanon", "lesotho", "liberia", "libya", "liechtenstein", "lithuania", "luxembourg",
        "madagascar", "malawi", "malaysia", "maldives", "mali", "malta", "marshall islands", "mauritania",
        "mauritius", "mexico", "micronesia", "moldova", "monaco", "mongolia", "montenegro", "morocco",
        "mozambique", "myanmar (burma)", "namibia", "nauru", "nepal", "netherlands", "new zealand",
        "nicaragua", "niger", "nigeria", "north macedonia", "norway", "oman", "pakistan", "palau",
        "palestine state", "panama", "papua new guinea", "paraguay", "peru", "philippines", "poland",
        "portugal", "qatar", "romania", "russia", "rwanda", "saint kitts and nevis", "saint lucia",
        "saint vincent and the grenadines", "samoa", "san marino", "sao tome and principe", "saudi arabia",
        "senegal", "serbia", "seychelles", "sierra leone", "singapore", "slovakia", "slovenia",
        "solomon islands", "somalia", "south africa", "spain", "sri lanka", "sudan", "suriname",
        "sweden", "switzerland", "syria", "tajikistan", "tanzania", "thailand", "timor-leste", "togo",
        "tonga", "trinidad and tobago", "tunisia", "turkey", "turkmenistan", "tuvalu", "uganda",
        "ukraine", "united arab emirates", "united kingdom", "united states", "uruguay", "uzbekistan",
        "vanuatu", "vatican city", "venezuela", "vietnam", "yemen", "zambia", "zimbabwe"};

    // Choose a random country
    srand(time(0));
    RandomChoice = rand() % 195;
    Temp = Countries[RandomChoice];
    string Country = Temp;
    LengthCountry = Country.length();

    // Special handling: If the country has spaces (like "united states"), 
    // reveal them immediately so the user doesn't have to guess them.
    OutStr = string(LengthCountry, '_');
    for(int i=0; i < LengthCountry; i++) {
        if(Country[i] == ' ') {
            OutStr[i] = ' ';
            GuessedChars++;
        }
    }

    cout << "Welcome to a game of HANG-MAN!" << endl;
    
    // Draw initial empty gallows
    DrawHangman(MistakeCount);

    cout << endl << OutStr << endl << endl;

    while (true)
    {
        cout << "Take a guess for the letter: ";
        cin >> Guess;
        cout << endl;

        // Checks if guess is repeated
        UsedCheck = LetterCheck(Guess);
        if (UsedCheck)
        {
            cout << "You already guessed that letter!" << endl;
            // We redraw here to keep the screen looking consistent
            DrawHangman(MistakeCount);
            cout << OutStr << endl;
            continue;
        }

        // Check guess
        GuessCheck = CheckingCharacter(Country, Guess, LengthCountry);
        
        if (!GuessCheck)
        {
            MistakeCount++;
            cout << "Incorrect guess! Mistakes: " << MistakeCount << "/10" << endl;
        }
        else 
        {
            cout << "Correct!" << endl;
        }

        // --- DISPLAY ART HERE ---
        DrawHangman(MistakeCount);
        // ------------------------

        // Checks if all characters have been guessed
        if (GuessedChars >= LengthCountry)
        {
            cout << "You have guessed the country: " << Country << ". Congratulations!!!!!" << endl;
            break;
        }

        // If number of mistakes exceed 10, Game is over
        if (MistakeCount >= 10)
        {
            cout << "Game over! The country was: " << Country << endl;
            break;
        }
    }

    return 0;
}

// Checks if the character is in the country and replaces it from every position
bool CheckingCharacter(string Country, char Guess, int LengthCountry)
{
    bool Guessed = false;
    for (int i = 0; i < LengthCountry; i++)
    {
        if (Country[i] == Guess && OutStr[i] == '_')
        {
            OutStr[i] = Guess;
            GuessedChars++;
            Guessed = true;
        }
    }
    cout << OutStr << endl;
    return Guessed;
}

// Function used to check if letter entered has been entered before.
bool LetterCheck(char Guess)
{
    static int index = 0;
    for (int i = 0; i < index; i++)
    {
        if (LetterArray[i] == Guess)
            return true;
    }
    LetterArray[index++] = Guess; // Store guessed letter
    return false;
}

// Function to draw the ASCII Art based on MistakeCount
void DrawHangman(int mistakes) {
    // We use an array of strings. 
    // "R" allows us to create Raw Strings so we don't have to use \n for every line.
    
    string stages[11] = {
        // 0 Mistakes: Empty
        R"(
           
              
              
              
              
        =========
        )",
        
        // 1 Mistake: Base
        R"(
           
              |
              |
              |
              |
        =========
        )",

        // 2 Mistakes: Pole
        R"(
              +
              |
              |
              |
              |
        =========
        )",

        // 3 Mistakes: Top Bar
        R"(
           ---+
              |
              |
              |
              |
        =========
        )",
        
        // 4 Mistakes: Rope
        R"(
           ---+
           |  |
              |
              |
              |
        =========
        )",

        // 5 Mistakes: Head
        R"(
           ---+
           |  |
           O  |
              |
              |
        =========
        )",

        // 6 Mistakes: Body
        R"(
           ---+
           |  |
           O  |
           |  |
              |
        =========
        )",

        // 7 Mistakes: Left Arm
        R"(
           ---+
           |  |
           O  |
          /|  |
              |
        =========
        )",

        // 8 Mistakes: Right Arm
        R"(
           ---+
           |  |
           O  |
          /|\ |
              |
        =========
        )",

        // 9 Mistakes: Left Leg
        R"(
           ---+
           |  |
           O  |
          /|\ |
          /   |
        =========
        )",

        // 10 Mistakes: Right Leg (Dead)
        R"(
           ---+
           |  |
           O  |
          /|\ |
          / \ |
        =========
        )"
    };

    // Safety check to prevent crashing if mistakes go over 10
    if (mistakes >= 0 && mistakes <= 10) {
        cout << stages[mistakes] << endl;
    }
}