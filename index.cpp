#include <iostream>
#include <ctime>

using namespace std;

void PrintIntro(int Difficulty){

    cout << "Voce e um agente secreto tentando entrar no nivel "<<Difficulty;
    cout << " em uma sala segura...\nA porta contem um teclado para codigo de entrada..\n";
    cout << "Voce tem apenas uma tentativa...\n\n";
}

bool PlayGame(int Difficulty){

    PrintIntro(Difficulty);
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProd = CodeA*CodeB*CodeC;

    cout << "+ o codigo tem tres digitos\n";
    cout << "+ a soma dos digitos e "<< CodeSum<<"\n";
    cout << "+ o produto dos digitos e "<< CodeProd<<"\n\n";

    // Comentario
    int GuessA,GuessB,GuessC;
    cin >> GuessA >> GuessB>> GuessC;

    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProd = GuessA*GuessB*GuessC;

    if(GuessSum == CodeSum && GuessProd==CodeProd)
    {
        cout<<"ACCESS GUARANTEE...\n";
        return true;
    }
    cout<<"ACCESS DENIED...\nAlarms go nuts and security is comming, mission failed...";
    return false;

    
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    while (LevelDifficulty<=MaxLevel)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
        if (bLevelComplete){
           ++LevelDifficulty;
           cout<<"Moving to next level...\n";
        }
        else
            return 0;
    }
    cout<<"Congratulations... you hacked the building!";
    return 0;
}