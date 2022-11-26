/*
==========================
Fait par Damien Stroppiana
==========================
*/

#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void lireChoix(vector<string> & vChoix) {
    while (true) {
        string entree;
        getline(cin, entree);
        if (entree == "") break;
        vChoix.push_back(entree);
    }
}

void lireVotes(vector<vector<unsigned>> & vVote) {
    while (true) {
        string entreenom;
        string Buf;
        //vector <string> votant;
        unsigned vote;
        getline(cin, entreenom);
        if (entreenom == "") break;
        //votant.push_back(entreenom);
        for (unsigned i = 0; i<size(vVote) ; ++i) {
            cin >> vote;
            vVote[i].push_back(vote);
        }
        getline(cin,Buf);
    }
}

void calcActions(vector<vector<unsigned>> & vVote, vector<unsigned> & tabScore) {
    for (unsigned i=0 ; i<size(vVote);++i)
        for (unsigned j=0; j<size(vVote[i]); ++j)
            tabScore[i] += vVote[i][j];
}

void affResultats(vector<unsigned> & tabScore, vector<string> & vChoix) {
    cout << "les résultats sont :" << endl;
    for (unsigned i=0 ; i<size(tabScore); ++i){
        cout << vChoix[i] << " : " << tabScore[i] << endl;
    }
    unsigned iMax = 0, max = 0;
    for (unsigned i=0 ; i<size(tabScore); ++i){
        if(tabScore[i] > max){
            iMax = i;
            max = tabScore[i];
        }
    }
    cout << "Le gagnant est : " << vChoix[iMax] << " avec " << tabScore[iMax];
    cout << " voix." << endl;
}

int main()
{
    vector<string> vChoix;
    lireChoix(vChoix);
    if(size(vChoix) <= 1 || size(vChoix) > 10000) {
        cerr << "Erreur : Merci de spécifier un nombre de choix entre 2 et 10000" ;
        return 1;
    }

    vector <vector<unsigned>> mVote(size(vChoix));
    vector<unsigned> tabScore(size(vChoix));
    lireVotes(mVote);
    calcActions(mVote, tabScore);
    affResultats(tabScore, vChoix);

    return 0;
}
