#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std ;

vector<string> generateVotant();
int selecteurDeJeu();
int main() {

    string winner;
    vector<string> jeux {"Counter strike", "Street Fighter", "Civilization V", "Mario Kart"};
    vector<int> cptjeux {0 ,0, 0, 0};
    vector<int> cpttour {0};
    vector<string> electeurs = generateVotant();
    srand(3);

    while(true) {
        int selection = selecteurDeJeu();

        if (selection == 1){
            ++cpttour[0];
        }

        for(int i = 0 ; i < electeurs.size() ; ++i) {
            int choixvote, choixjeu;
            choixjeu = rand() % 4 +1;
            choixvote = rand() % 3 +1 -2;

            while ( choixvote > 2){
                /*cout << "Veillez Recommoncez :";*/
                cin >> choixvote ;
            }

            // POSITIF
            if (choixvote  == 1){
                ++cptjeux[choixjeu-1];
            }


            // NÉGATIF
            if (choixvote  == -1){
                --cptjeux[choixjeu-1];
            }
        }


        //Afficher les résultats

        cout << "Les Résultats : " << "\n";
        cout << "Counter Strike : " << cptjeux[0] << " vote" << "\n";
        cout << "Street Fighter : " << cptjeux[1] << " vote" << "\n";
        cout << "Civilisation V : " << cptjeux[2] << " vote" << "\n";
        cout << "Mario Kart : " << cptjeux[3] << " vote" << "\n" << endl;

        if (cptjeux[3] >cptjeux[0]){
            if (cptjeux[3] >cptjeux[1])
                if (cptjeux[3] >cptjeux[2])
                    cout << "Le gagnant est Mario Kart avec " << cptjeux[3] << " vote" << endl;
            break;
        }

        if (cptjeux[0] >cptjeux[1]){
            if (cptjeux[0] >cptjeux[2])
                if (cptjeux[0] >cptjeux[3])
                    cout << "Le gagnant est Counter Strike avec " << cptjeux[3] << " vote" << endl;
            break;
        }
        if (cptjeux[2] >cptjeux[0]){
            if (cptjeux[2] >cptjeux[1])
                if (cptjeux[2] >cptjeux[3])
                    cout << "Le gagnant est Civilisation V avec " << cptjeux[3] << " vote" << endl;
            break;
        }

        if (cptjeux[1] >cptjeux[0]){
            if (cptjeux[1] >cptjeux[2])
                if (cptjeux[1] >cptjeux[3])
                    cout << "Le gagnant est Street Fighter avec " << cptjeux[3] << " vote" << endl;
            break;
        }
    }
}


int selecteurDeJeu() {
    int selection;
    vector<int> cpttour {0};

    cin >> selection ;
    return selection;
}

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



