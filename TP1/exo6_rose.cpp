#include <iostream>

using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    Noeud* dernier;
};

struct DynaTableau{
    int* donnees;
    int capacite;
    int nbVal;
};



            //          DYNATABLEAU


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->nbVal = 0;
    tableau->capacite = capacite;
    tableau->donnees = (int*) malloc(tableau->capacite*sizeof(int));
    
}

bool est_vide(const DynaTableau* liste)
{
    if(liste->nbVal == 0){
        return true;
    }
    else{
        return false;
    }
}

void affiche(const DynaTableau* tableau)
{
    for(int i = 0; i < tableau->nbVal; i++){
        cout << "Valeur " << i << " : " << tableau->donnees[i] << endl;
    }

}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->nbVal < tableau->capacite){
        tableau->donnees[tableau->nbVal] = valeur;
        tableau->nbVal++;
    }
    else{
        
        DynaTableau newTab;
        initialise(&newTab, (tableau->capacite*2));
        for(int i = 0; i < tableau->capacite; i++){
            newTab.donnees[i] = tableau->donnees[i];
            newTab.nbVal++;
        }
        newTab.donnees[newTab.nbVal] = valeur;

        tableau->donnees = newTab.donnees;
        tableau->nbVal++;
        tableau->capacite= newTab.capacite;
    }

}


int recupere(const DynaTableau* tableau, int n)
{
    return tableau->donnees[n];
}

int cherche(const DynaTableau* tableau, int valeur)
{
    int i = 0;
    while(i < tableau->nbVal && tableau->donnees[i] != valeur){
        i++;
    }
    if(i == tableau->nbVal){
        return -1;
    }
    else{
        return i;
    }
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    tableau->donnees[n] = valeur;
}



            //          LISTE


void initialise(Liste* liste)
{
    liste->premier = (Noeud*) malloc(sizeof(Noeud));
    liste->premier = NULL;
    liste->dernier = (Noeud*) malloc(sizeof(Noeud));
    liste->dernier = NULL;
}

bool est_vide(const Liste* liste)
{
    if(liste->premier == NULL){
        return true;
    }
    else{
        return false;
    }
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* nd = (Noeud*) malloc(sizeof(Noeud));
    nd->donnee = valeur;
    nd->suivant = NULL;

    if(est_vide(liste)){
        liste->premier = nd;    
    }
    else{
        liste->dernier->suivant = nd;
    }
    liste->dernier = nd;   

}

void affiche(const Liste* liste)
{
    int i = 0;
    Noeud* courant = (Noeud*) malloc(sizeof(Noeud));
    courant = liste->premier;
    while(courant != nullptr){
        cout << "Valeur " << i << " : " << courant->donnee << endl;
        courant = courant->suivant;
        i++;
    }
}

int recupere(const Liste* liste, int n)
{
    int i = 0;
    Noeud* courant = (Noeud*) malloc(sizeof(Noeud));
    courant = liste->premier;
    while(i < n){
        courant = courant->suivant;
        i++;
    }
    return courant->donnee;
}

int cherche(const Liste* liste, int valeur)
{
    int i = 0;
    Noeud* courant = (Noeud*) malloc(sizeof(Noeud));
    courant = liste->premier;
    while(courant != nullptr && courant->donnee != valeur){
        courant = courant->suivant;
        i++;
    }
    if(courant == nullptr){
        return -1;
    }
    else{
        return i;
    }
}

void stocke(Liste* liste, int n, int valeur)
{
    int i = 0;
    Noeud* courant = (Noeud*) malloc(sizeof(Noeud));
    courant = liste->premier;
    while(courant != nullptr && i < n){
        courant = courant->suivant;
        i++;
    }
    courant->donnee = valeur;
}



            //          LISTE - FILE ET PILE



void pousse_file(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
    
}

int retire_file(Liste* liste)
{
    int val = liste->premier->donnee;
    liste->premier = liste->premier->suivant;
    return val;
}

void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);
}

int retire_pile(Liste* liste)
{
    int val = liste->dernier->donnee;
    if(liste->premier != NULL && liste->premier->suivant != NULL){

        Noeud* courant = (Noeud *) malloc(sizeof(Noeud));
        courant = liste->premier;

        while(courant->suivant != liste->dernier){

            courant = courant->suivant;
        }

        courant->suivant = NULL;
        liste->dernier = courant;

        
    }
    else{
        liste->premier = NULL;
    }
    
    return val;

}







int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    cout << "Affichage de la liste : " << endl;
    affiche(&liste);
    cout << "Afichage du tableau : " << endl;
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans le tableau à " << cherche(&tableau, 15) << std::endl;
    cout << "Affichage de la liste : " << endl;
    affiche(&liste);

    cout << "Affichage du tableau : " << endl;
    affiche(&tableau);
    std::cout << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    cout << "Affichage de la liste : " << endl;
    affiche(&liste);

    cout << "Affichage du tableau : " << endl;
    affiche(&tableau);
    std::cout << std::endl;




                    //      PILE ET FILE

    
    Liste pile; 
    Liste file; 

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
        
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}