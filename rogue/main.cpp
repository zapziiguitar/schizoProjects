#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

string assignFaction(string chosenClass)
{
    string uclass, assignedFaction;
    ifstream faction("classFactions.txt");
    faction.seekg(0, ios_base::beg);
    while(getline(faction, uclass))
    {
        if(chosenClass == uclass)
        {
            getline(faction, assignedFaction);
        }
    }
    return assignedFaction;
}

int assignSpecial(string chosenClass)
{
    string uclass;
    int num = 0;
    ifstream numerical("numerical.txt");
    numerical.seekg(0, ios_base::beg);

    while(getline(numerical, uclass))
    {
        if(chosenClass == uclass)
        {
            numerical >> num;
        }
    }
    return num;
}

vector<int> assignStats(vector<int> player, string chosenClass)
{
    string uclass;
    ifstream stats("classStats.txt");
    stats.seekg(0, ios_base::beg);
    while(getline(stats, uclass))
    {
        if(chosenClass == uclass )
        {
            for(int i = 0; i < 4; i++)
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

    srand(time(0));
    int num = rand() % 6 + 1;
    switch(num)
    {
    case 1:
        PlaySound(TEXT("isle of eth menu combat.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 2:
        PlaySound(TEXT("mage hideout menu.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 3:
        PlaySound(TEXT("snail menu.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 4:
        PlaySound(TEXT("viniferas menu.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 5:
        PlaySound(TEXT("sans.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 6:
        PlaySound(TEXT("Harmony.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    }


    ifstream classes("classInfo.txt");

    char answer = 'N';
    //               hp, dmg, spd, rng, rgn 3 - highest 1- lowest
    vector<int> player1 = {0, 0, 0, 0};
    vector<int> player2 = {0, 0, 0 ,0};

    bool silver1 = false, silver2 = false, dodge1 = false, dodge2 = false, grapple1 = false, grapple2 = false;
    string tempclass, p1class, p2class, uclass, classQuote, classInfo, classStrengths, classWeaknesses, classSpecial, faction1, faction2, p1move, p2move;
    int sp1 = 0, sp2 = 0, toxicity1 = 0, toxicity2 = 0, dmg, maxhp1, maxhp2, spcd1 = 1, spcd2 = 1, dodgechance1, dodgechance2, spturns1 = 0, spturns2 = 2, potion, potion2;

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
        cout << "Player 1, please choose your class (case sensitive): " << endl;
        getline(cin,tempclass);
        while(getline(classes, uclass))
        {
            if(tempclass == uclass)
            {
                getline(classes, classQuote);
                getline(classes, classInfo);
                getline(classes, classSpecial);
                getline(classes, classStrengths);
                getline(classes, classWeaknesses);
                break;

            }
        }
        cout << "Info about your chosen class: " << uclass << endl;
        cout << endl;
        cout << classQuote << endl;
        cout << classInfo << endl;
        cout << classSpecial << endl;
        cout << classStrengths << endl;
        cout << classWeaknesses << endl;
        cout << endl;
        cout << "Would you like to lock in your choice? Y/N." << endl;
        cin >> answer;
    }
    answer = 'N';
    p1class = tempclass;
    cout << endl;
    cout << "Player 1 has chosen: " << p1class << endl;
    cin.ignore();
    system("cls");
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
    classes.seekg(0, ios_base::beg);
    while(answer == 'N')
    {
        cout << "Player 2, please choose your class(case sensitive): " << endl;
        getline(cin,tempclass);
        while(getline(classes, uclass))
        {
            if(tempclass == uclass)
            {
                getline(classes, classQuote);
                getline(classes, classInfo);
                getline(classes, classSpecial);
                getline(classes, classStrengths);
                getline(classes, classWeaknesses);
                break;

            }
        }
        cout << "Info about your chosen class: " << uclass << endl;
        cout << endl;
        cout << classQuote << endl;
        cout << classInfo << endl;
        cout << classSpecial << endl;
        cout << classStrengths << endl;
        cout << classWeaknesses << endl;
        cout << endl;
        cout << "Would you like to lock in your choice? Y/N." << endl;
        cin >> answer;
        cin.ignore();
    }
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
    sp1 = assignSpecial(p1class);
    sp2 = assignSpecial(p2class);
    faction1 = assignFaction(p1class);
    faction2 = assignFaction(p2class);

    if ( p1class == "Ronin" && p2class == "Ronin")
    {
        cout << "As the sound of scabbards clashing in the crowded city streets rings their ears, they unsheathe their swords with intent to kill eachother." << endl;
    }

    if ( faction1 == "orderly" && faction2 == "orderly" )
    {
        cout << "A servant of The Order has gone rogue... May the " << p1class << " slay the rogue " << p2class << " to keep Gaia safe!" << endl;
    }

    if ( p1class == p2class && p1class != "Ronin" && p2class != "Ronin" )
    {
        cout << "A rogue " << p1class << " faces their own kind... May the best " << p2class << " in all of Gaia prevail!" << endl;
    }
    if ( (faction1 == "orderly" && faction2 == "chaotic") || (faction1 == "chaotic" && faction2 == "orderly") )
    {
        cout << "The greatest " << p1class << " in all of Gaia faces the All-Mighty " << p2class <<". Who may prevail?" << endl;
    }
    if ( faction1 == "chaotic" && faction2 == "chaotic")
    {
        cout << "As one is looking for greater power so is the other... Who will achieve greater power? The " << p1class << " or " << p2class << "?" << endl;
    }
    sleep(5);
    system("cls");

    srand(time(0));
    int num2 = rand() % 9 + 1;
    switch(num2)
    {
    case 1:
        PlaySound(TEXT("isle of eth menu combat.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 2:
        PlaySound(TEXT("emerald combat.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 3:
        PlaySound(TEXT("sky castle combat.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 4:
        PlaySound(TEXT("Dummy!.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 5:
        PlaySound(TEXT("Rude Buster.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 6:
        PlaySound(TEXT("ASGORE.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 7:
        PlaySound(TEXT("Hopes And Dreams.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 8:
        PlaySound(TEXT("Battle Against A True Hero.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 9:
        PlaySound(TEXT("Last Surprise.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    }
    maxhp1 = player1[0];
    maxhp2 = player2[0];

    bool gameOver = false;
    while(!gameOver)
    {
         if (player1[0] < 0 || player2[0] < 0)
        {
            gameOver = true;
        }
        if( spturns1 == 2 )
        {
            switch(sp1)
            {
            case 1:
                cout << "The White Flames, once on your sword, fade. Your damage output is back to normal." << endl;
                cout << endl;
                player1[1]--;
                break;
            case 2:
                cout << "The curse lifts off of your opponent. Your damage output is back to normal." << endl;
                cout << endl;
                player1[1]--;
                break;
            case 3:
                cout << "Your opponent fights off the shriekers and is able to focus on the battle at hand. Your opponent's agility is back to normal." << endl;
                cout << endl;
                player1[2]--;
                break;
            case 4:
                player1[2]--;
                cout << "Your opponent comes to their senses and their thoughts are back to normal. Your opponent's agility is back to normal." << endl;
                cout << endl;
                break;
            case 5:
                grapple1 = false;
                cout << "Your opponent breaks out of the ropes and may fight again. Your opponent may no longer skip turns." << endl;
                cout << endl;
                break;
            case 6:
                player2[3]++;
                cout << "Your opponent stopped the bleeding. Your opponent may use potions to regain more health." << endl;
                cout << endl;
                break;
            case 7:
                silver1 = false;
                cout << "The silver vanishes from your armor. You take the same ammount of damage as you did." << endl;
                cout << endl;
                break;
            case 8:
                player1[2]--;
                cout << "You remember that you left the stove on! Your agility is back to normal." << endl;
                cout << endl;
                break;
            }
        }
        if(spcd1 < 0) spcd1 = 0;
        system("cls");
        if(grapple2)
        {
            cout << "You're enveloped in the opponent's grapple! You skip this turn" << endl;
            sleep(4);
            system("cls");
        }
        else{
        cout << p1class << " makes their move!" << endl;
        cout << p1class << " max HP: " << maxhp1 << endl;
        cout << p1class << " current HP: " << player1[0] << endl;
        cout << "POTION TOXICITY: " << toxicity1 << endl;
        cout << "SPECIAL COOLDOWN: " << spcd1 << " turns." << endl;
        cout << "ATTACK            HEAL            SPECIAL" << endl;
        cin >> p1move;
        while(p1move != "ATTACK" || p1move != "HEAL" || p1move != "SPECIAL")
        {
            cin.ignore();
            cout << "Please re-enter your move" << endl;
            cin >> p1move;
        }

        if(p1move == "ATTACK")
        {
            switch(player1[1])
            {
            case 1:
                dmg = 37;
                break;
            case 2:
                dmg = 47;
                break;
            case 3:
                dmg = 57;
                break;
            case 4:
                dmg = 67;
                break;
            }
            switch(player2[2])
            {
            case 1:
                srand(time(0));
                dodgechance1 = rand() % 20 + 1;
                break;
            case 2:
                srand(time(0));
                dodgechance1 = rand() % 4  + 1;
                break;
            case 3:
                srand(time(0));
                dodgechance1 = rand() % 2 + 1;
                break;
            }
            if(dodgechance1 == 1)
            {
                dodge1 = true;
            }
            if(dodge1)
            {
                cout << "Your opponent has dodged the attack!" << endl;
                dodge1=false;
                cin.ignore();
                sleep(3);
            }
            else
            {
                srand(time(0));
                int num3 = rand() % 10 + 1;
                dmg-=num3;
                if(silver2) dmg = dmg/2;
                cout << p1class << " strikes their opponent dealing " << dmg << "HP!" << endl;
                player2[0] -= dmg;
                cin.ignore();
                sleep(3);
            }
        }
        if (p1move == "HEAL")
        {
            if( toxicity1 == 4)
            {
                cout << "You spit out your health potion, it tastes disgusting! You will not gain HP, your body can't handle another potion!" << endl;
                cin.ignore();
                sleep(3);
            }
            else
            {
                switch(player1[3])
                {
                case 0:
                    potion=10;
                    break;
                case 1:
                    potion=20;
                    break;
                case 2:
                    potion=30;
                    break;
                case 3:
                    potion=40;
                    break;
                }
                player1[0]+=potion;
                if(player1[0] > maxhp1)
                {
                    player1[0] = maxhp1;
                }
                cout << "The potion tasted like a cool beer and a pack of ciggarettes on a calm friday evening! You healed: " << potion << "HP." << endl;
                toxicity1++;
                cin.ignore();
                sleep(3);
            }
        }
        if (p1move == "SPECIAL")
        {
            if(spcd1 != 0)
            {
                cout << "You were caught off guard trying to use your special ability and were disarmed! You skip this turn." << endl;
                cin.ignore();
                sleep(3);
            }
            else
            {
                switch(sp1)
                {
                case 1:
                    player1[1]++;
                    cout << "As White Flames engulf your swords, you feel yourself get stronger. Your damage output is now higher." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 2:
                    player1[1]++;
                    cout << "As you take a Wrathful Leap, you curse your opponent and watch as they feel obsolete. Your damage output is now higher." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 3:
                    player1[2]++;
                    cout << "You cast a dark spell summoning the undead shriekers, once noble warriors and watch as your opponent struggles to get near you. Your speed has gone up." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 4:
                    player1[2]++;
                    cout << "You drive your opponent insane, their footworks getting slobbish and they're having a harder time hitting you. Your speed has gone up." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 5:
                    grapple1 = true;
                    cout << "You envelop your opponent in your grappling hook, as they struggle to move you may now land free hits on them. Your opponent skips a turn." << endl;
                    spturns1 = 0;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 6:
                    player2[3]--;
                    cout << "Your slash and stab your opponent multiple times, causing hemorrhaging. They take 60HP of damage and hinder their regenerating capabilities." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 7:
                    silver1 = true;
                    cout << "You cover your armor in silver, rendering enemy damage obsolete. You take 50% less damage." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 8:
                    player1[2]++;
                    cout << "The ronin calms his mind, grips his katana tighter, they feel at peace, ready to weave any ability. Your speed has gone up." << endl;
                    spturns1 = -1;
                    spcd1 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                }
            }
        }}


        if (player1[0] < 0 || player2[0] < 0)
        {
            gameOver = true;
        }
        spturns1++;
        spcd1--;

        if(!gameOver)
        {


        if( spturns2 == 2 )
        {
            switch(sp2)
            {
            case 1:
                cout << "The White Flames, once on your sword, fade. Your damage output is back to normal." << endl;
                cout << endl;
                player2[1]--;
                break;
            case 2:
                cout << "The curse lifts off of your opponent. Your damage output is back to normal." << endl;
                cout << endl;
                player2[1]--;
                break;
            case 3:
                cout << "Your opponent fights off the shriekers and is able to focus on the battle at hand. Your opponent's agility is back to normal." << endl;
                cout << endl;
                player2[2]--;
                break;
            case 4:
                player2[2]--;
                cout << "Your opponent comes to their senses and their thoughts are back to normal. Your opponent's agility is back to normal." << endl;
                cout << endl;
                break;
            case 5:
                grapple2 = false;
                cout << "Your opponent breaks out of the ropes and may fight again. Your opponent may no longer skip turns." << endl;
                cout << endl;
                break;
            case 6:
                player1[3]++;
                cout << "Your opponent stopped the bleeding. Your opponent may use potions to regain more health." << endl;
                cout << endl;
                break;
            case 7:
                silver2 = false;
                cout << "The silver vanishes from your armor. You take the same ammount of damage as you did." << endl;
                cout << endl;
                break;
            case 8:
                player2[2]--;
                cout << "You remember that you left the stove on! Your agility is back to normal." << endl;
                cout << endl;
                break;
            }
        }
        if(spcd2 < 0) spcd2 = 0;
        system("cls");
        if(grapple1)
        {
            cout << "You're enveloped in the opponent's grapple! You skip this turn" << endl;
            sleep(4);
            system("cls");
        }
        else{
        cout << p2class << " makes their move!" << endl;
        cout << p2class << " max HP: " << maxhp2 << endl;
        cout << p2class << " current HP: " << player2[0] << endl;
        cout << "POTION TOXICITY: " << toxicity2 << endl;
        cout << "SPECIAL COOLDOWN: " << spcd2 << " turns." << endl;
        cout << "ATTACK            HEAL            SPECIAL" << endl;
        cin >> p2move;
        while(p2move != "ATTACK" || p2move != "HEAL" || p2move != "SPECIAL")
        {
            cin.ignore();
            cout << "Please re-enter your move" << endl;
            cin >> p2move;
        }
        if(p2move == "ATTACK")
        {
            switch(player2[1])
            {
            case 1:
                dmg = 37;
                break;
            case 2:
                dmg = 47;
                break;
            case 3:
                dmg = 57;
                break;
            case 4:
                dmg = 67;
                break;
            }
            switch(player1[2])
            {
            case 1:
                srand(time(0));
                dodgechance2 = rand() % 20 + 1;
                break;
            case 2:
                srand(time(0));
                dodgechance2 = rand() % 4  + 1;
                break;
            case 3:
                srand(time(0));
                dodgechance2 = rand() % 2 + 1;
                break;
            case 4:
                dodgechance2 = 1;
                break;
            }
            if(dodgechance2 == 1)
            {
                dodge2 = true;
            }
            if(dodge2)
            {
                cout << "Your opponent has dodged the attack!" << endl;
                dodge2 = false;
                cin.ignore();
                sleep(3);
            }
            else
            {
                srand(time(0));
                int num4 = rand() % 10 + 1;
                dmg-=num4;
                if(silver1) dmg = dmg/2;
                cout << p2class << " strikes their opponent dealing " << dmg << "HP!" << endl;
                player1[0] -= dmg;
                cin.ignore();
                sleep(3);
            }
        }
        if (p2move == "HEAL")
        {
            if( toxicity2 == 4)
            {
                cout << "You spit out your health potion, it tastes disgusting! You will not gain HP, your body can't handle another potion!" << endl;
                cin.ignore();
                sleep(3);
            }
            else
            {
                switch(player2[3])
                {
                case 0:
                    potion2=10;
                    break;
                case 1:
                    potion2=20;
                    break;
                case 2:
                    potion2=30;
                    break;
                case 3:
                    potion2=40;
                    break;
                }
                player2[0]+=potion2;
                if(player2[0] > maxhp2)
                {
                    player2[0] = maxhp2;
                }
                cout << "The potion tasted like a cool beer and a pack of ciggarettes on a calm friday evening! You healed " << potion2 << "HP." << endl;
                toxicity2++;
                cin.ignore();
                sleep(3);
            }
        }
        if (p2move == "SPECIAL")
        {
            if(spcd2 != 0)
            {
                cout << "You were caught off guard trying to use your special ability and were disarmed! You skip this turn." << endl;
                cin.ignore();
                sleep(3);
            }
            else
            {
                switch(sp2)
                {
                case 1:
                    player2[1]++;
                    cout << "As White Flames engulf your swords, you feel yourself get stronger. Your damage output is now higher." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 2:
                    player2[1]++;
                    cout << "As you take a Wrathful Leap, you curse your opponent and watch as they feel obsolete. Your damage output is now higher." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 3:
                    player2[2]++;
                    cout << "You cast a dark spell summoning the undead shriekers, once noble warriors and watch as your opponent struggles to get near you. Your speed has gone up." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 4:
                    player2[2]++;
                    cout << "You drive your opponent insane, their footworks getting slobbish and they're having a harder time hitting you. Your speed has gone up." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 5:
                    grapple2 = true;
                    cout << "You envelop your opponent in your grappling hook, as they struggle to move you may now land free hits on them. Your opponent skips a turn." << endl;
                    spturns2 = 0;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 6:
                    player1[3]--;
                    cout << "Your slash and stab your opponent multiple times, causing hemorrhaging. They take 60HP of damage and hinder their regenerating capabilities." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 7:
                    silver2 = true;
                    cout << "You cover your armor in silver, rendering enemy damage obsolete. You take 50% less damage." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                case 8:
                    player2[2]++;
                    cout << "The ronin calms his mind, grips his katana tighter, they feel at peace, ready to weave any ability. Your speed has gone up." << endl;
                    spturns2 = -1;
                    spcd2 = 5;
                    cin.ignore();
                    sleep(3);
                    break;
                }
            }
        }}
    }
        spturns2++;
        spcd2--;

        if (player1[0] < 0 || player2[0] < 0)
        {
            gameOver = true;
        }
    }
    system("cls");
    srand(time(0));
    int num6 = rand() % 4 + 1;
    switch(num6)
    {
    case 1:
        PlaySound(TEXT("ending.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 2:
        PlaySound(TEXT("An Ending.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 3:
        PlaySound(TEXT("once upon a time.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    case 4:
        PlaySound(TEXT("Home.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
        break;
    }

    if(player1[0] >= 0)
    {
        if(faction1 == "orderly") cout << p1class << " has been slain in battle by the likes of the " << p2class << ". Tragic loss for all of Gaia as they have lost a true warrior..." << endl;
        if(faction1 == "chaotic") cout << p1class << " has at last fallen. No more will they terrorise Gaia. May peace live on." << endl;
        if(faction1 == "neutral") cout << "Is this... peace..?" << endl;
    }
    if(player2[0] <= 0)
    {
        if(faction1 == "orderly") cout << "The Great " << p1class << " has saved Gaia once again from the likes of " << p2class << ". May news of this Hero spread all over these beautiful lands." << endl;
        if(faction1 == "chaotic") cout << "Stronger and more bloodthirsty than ever " << p1class << " is looking for another fight to finally bring all of Gaia to their KNEES!" << endl;
        if(faction1 == "neutral") cout << "The Ronin, sheathing their blade covered in blood, looks up at the sun setting, reminiscing of how far they've come... but mostly they want to go out for a drink, about DAMN TIME. Oh, and I guess You saved the world, good job, well done You." << endl;
    }
    return 0;
}