#include <iostream>



using namespace std;


int main ()
{
    int gagnant ;

    srand(1);
    gagnant = rand() % 4;


    int choixjeux,Counterstrike=0,StreetFighterII=0,CivilizationVI=0,MarioKart=0;

    int j = 0 ;
    while(j!= 112) {
        choixjeux = rand() % 4;
        switch(choixjeux)
        {

            case 1:
                cout<<"\nUn electeur as voté pour Counter strike\n";
                (Counterstrike)++;
            break;
            case 2:
                cout<<"\nUn electeur as voté pour Street Fighter II\n";
                (StreetFighterII)++;
            break;
            case 3:
                cout<<"\nUn electeur as voté pour Civilization VI\n";
                (CivilizationVI)++;
            break;
            case 4:
                cout<<"\nUn electeur as voté pour Mario Kart\n";
                (MarioKart)++;
            break;

            default:
                cout<<"\nUn electeur as voté pour personne\n";

        }
        ++j;
    }
    switch(gagnant)
    {

        case 1:
            cout<<"\nLe gagnant est : Counter strike\n";
            (Counterstrike)++;
        break;
        case 2:
            cout<<"\nLe gagnant est : Street Fighter II\n";
            (StreetFighterII)++;
        break;
        case 3:
            cout<<"\nLe gagnant est : Civilization VI\n";
            (CivilizationVI)++;
        break;
        case 4:
            cout<<"\nLe gagnant est : Mario Kart\n";
            (MarioKart)++;
        break;

        default:
            cout<<"\nTu as voté pour personne, il n'y a pas de gagnant\n";

    }

    return 0;
}

