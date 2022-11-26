#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<string> generateVotant() {

    vector<string> electeurs;


    while(true) {

        string nom;
        string prenom;
        string votantFinal;
        getline(cin, nom);
        getline(cin, prenom);
        if(cin.eof()) break;
        // Faire en sorte qu'il y est que la première lettre car sinon je peux pas ouvrir le fichier oracle
        prenom.erase(remove(prenom.begin(), prenom.end(), ' '), prenom.end());
        char initial = nom[1];
        votantFinal.push_back(initial);
        votantFinal = votantFinal + ". " + prenom;
        electeurs.push_back(votantFinal);
}


    return electeurs;
}

class Election
{
    int sb = 0, count [4] = { 0 };
public:
    //sert a afficher dans la consoles la liste des jeux a voté avec une question quel est le meilleur jeux.
    Election()
    {
        cout<<"\t\t\tQuel est le meilleur jeux";
        cout<<"\nSaisir 1 pour elir Counter Strike";
        cout<<"\nSaisir 2 pour elir Street Fighter II";
        cout<<"\nSaisir 3 pour elir Civilization VI";
        cout<<"\nSaisir 4 pour elir Mario Kart" <<endl;
    }
    void ChoisirVote(int vote)
    {
        //sert a sélectionner le jeu de notre choix.
        cout <<"\nSelectionner votre jeu preferee: ";


        if (vote >= 1 && vote <= 4)
            count [vote - 1]++;
        else
            sb++;
    }
    void ResultatVote(vector <string> Jeux)
    {
        //sert a afficher le résultat du vote après tout les participants.
        cout << "\n\t\t\tResultat des votes" << endl;
        for (int i = 0; i < Jeux.size() ; i++)
            cout << "\nJeux " << Jeux[i] << ": " << count[i];
        cout<<"\n\nVote Blanc: "<<sb<< endl;
    }
};


int main()
{
    //random pour automatiser le vote.
    string Choix;
    Election Vote;
    vector<string> electeurs = generateVotant();
    vector<string> Jeux = {"Counter Strike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    srand(1);

    int j = 0;
    while( j != electeurs.size() ) {
        cout << electeurs.at(j)[0];
        int vote = rand() %5;
        Vote.ChoisirVote(vote);{
           Choix[j] = toupper(Choix[j]);
        }
        Vote.ResultatVote(Jeux);
        ++j;
    }
    return 0;

}
