#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <vector>
using namespace std;

vector<int> assignStats(vector<int> player, string chosenClass)
{
    string uclass;
    ifstream stats("classStats.txt");

    while(getline(stats, uclass))
    {
        if(chosenClass == uclass )
        {
            for(int i = 0; i < 5; i++)
            {
                stats >> player[i];
            }
            break;
        }
    }

    return player;
}

int main()
{

    ifstream classes("classInfo.txt");

    char answer = 'N';
    //               hp, dmg, spd, rng, rgn 3 - highest 1- lowest
    vector<int> player1 = {0, 0, 0, 0, 0};
    vector<int> player2 = {0, 0, 0, 0 ,0};

    string tempclass, p1class, p2class, uclass, classQuote, classInfo, classStrengths, classWeaknesses;

    cout << "Class list:" << endl;
    cout << "Sigil Knight Commander" << endl;
    cout << "Abyss Walker" << endl;
    cout << "Master Necromancer" << endl;
    cout << "Master Illusionist" << endl;
    cout << "Shinobi" << endl;
    cout << "Faceless One" << endl;
    cout << "Whisperer" << endl;
    cout << "Ronin" << endl;
    cout << endl;



    while(answer == 'N')
    {
        cout << "Player 1, please choose your class: " << endl;
        getline(cin,tempclass);
        while(getline(classes, uclass))
        {
            if(tempclass == uclass)
            {
                getline(classes, classQuote);
                getline(classes, classInfo);
                getline(classes, classStrengths);
                getline(classes, classWeaknesses);
                //getline(classes, classSpecial);
                break;

            }
        }
        cout << "Info about your chosen class: " << uclass << endl;
        cout << classQuote << endl;
        cout << classInfo << endl;
        cout << classStrengths << endl;
        cout << classWeaknesses << endl;
        cout << endl;
        cout << "Would you like to lock in your choice? Y/N." << endl;
        cin >> answer;
        cin.ignore();
    }
    answer = 'N';
    p1class = tempclass;
    cout << endl;
    cout << "Player 1 has chosen: " << p1class << endl;

    while(answer == 'N')
    {
        cout << "Player 2, please choose your class: " << endl;
        getline(cin,tempclass);
        while(getline(classes, uclass))
        {
            if(tempclass == uclass)
            {
                getline(classes, classQuote);
                getline(classes, classInfo);
                getline(classes, classStrengths);
                getline(classes, classWeaknesses);
                break;

            }
        }
        cout << "Info about your chosen class: " << uclass << endl;
        cout << classQuote << endl;
        cout << classInfo << endl;
        cout << classStrengths << endl;
        cout << classWeaknesses << endl;
        cout << endl;
        cout << "Would you like to lock in your choice? Y/N." << endl;
        cin >> answer;
        cin.ignore();
    }
    answer = 'N';
    p2class = tempclass;
    cout << endl;
    cout << "Player 2 has chosen: " << p2class << endl;
    sleep(2);
    system("cls");
cout << R"(
   *               )             )                                 (                  )    *      *           )
 (  `    (      ( /(    *   ) ( /(         (    (      *   )  *   ))\ )         (  ( /(  (  `   (  `       ( /(   (
 )\))(   )\     )\()) ` )  /( )\())(     ( )\   )\   ` )  /(` )  /(()/( (       )\ )\()) )\))(  )\))(  (   )\())  )\  (
((_)()((((_)(  ((_)\   ( )(_)|(_)\ )\    )((_|(((_)(  ( )(_))( )(_))(_)))\    (((_|(_)\ ((_)()\((_)()\ )\ ((_)\ (((_) )\
(_()((_)\ _ )\__ ((_) (_(_()) _((_|(_)  ((_)_ )\ _ )\(_(_())(_(_()|_)) ((_)   )\___ ((_)(_()((_|_()((_|(_) _((_))\___((_)
|  \/  (_)_\(_) \ / / |_   _|| || | __|  | _ )(_)_\(_)_   _||_   _| |  | __| ((/ __/ _ \|  \/  |  \/  | __| \| ((/ __| __|
| |\/| |/ _ \  \ V /    | |  | __ | _|   | _ \ / _ \   | |    | | | |__| _|   | (_| (_) | |\/| | |\/| | _|| .` || (__| _|
|_|  |_/_/ \_\  |_|     |_|  |_||_|___|  |___//_/ \_\  |_|    |_| |____|___|   \___\___/|_|  |_|_|  |_|___|_|\_| \___|___|

)" << endl;
    sleep(2);
    system("cls");

    player1 = assignStats(player1, p1class);
    player2 = assignStats(player2, p2class);


    while( player1[0] >= 0 || player2[0] >=0 )
    {

    }



    return 0;
}
