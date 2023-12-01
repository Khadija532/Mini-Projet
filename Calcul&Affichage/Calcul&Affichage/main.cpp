//
//  main.cpp
//  Calcul&Affichage
//
//  Créé par Macbook Pro le 29/11/2023.
//

#include <iostream>
#include <vector>

// Structure pour stocker les informations sur les employés
struct TPEmploye {
    int matricule;
    std::string nomPrenom;
    float salaireBrut;
};

// Fonction pour calculer la contribution CNSS en fonction du salaire brut
float CNSS(TPEmploye employe) {
    if (employe.salaireBrut < 200) {
        return 0;
    } else {
        return 0.1 * employe.salaireBrut;
    }
}

// Fonction pour calculer l'impôt sur le revenu en fonction du salaire restant après déduction de la CNSS
float Impots(TPEmploye employe) {
    float salaireImposable = employe.salaireBrut - CNSS(employe);
    if (salaireImposable <= 200) {
        return 0.05 * salaireImposable;
    } else if (salaireImposable <= 400) {
        return 0.1 * salaireImposable;
    } else if (salaireImposable <= 600) {
        return 0.2 * salaireImposable;
    } else if (salaireImposable <= 800) {
        return 0.3 * salaireImposable;
    } else {
        return 0.4 * salaireImposable;
    }
}

// Fonction pour calculer le salaire net après déductions de la CNSS et de l'impôt sur le revenu
float SalaireNet(TPEmploye employe) {
    return employe.salaireBrut - CNSS(employe) - Impots(employe);
}

// Fonction pour calculer le salaire brut total pour une liste d'employés
float SalaireBrut(std::vector<TPEmploye> employeList) {
    float sommeSalaireBrut = 0;
    for (const auto& employe : employeList) {
        sommeSalaireBrut += employe.salaireBrut;
    }
    return sommeSalaireBrut;
}

// Fonction pour calculer la somme des contributions CNSS totales pour une liste d'employés
float SommeCNSS(std::vector<TPEmploye> employeList) {
    float sommeCNSS = 0;
    for (const auto& employe : employeList) {
        sommeCNSS += CNSS(employe);
    }
    return sommeCNSS;
}

int main() {
    // Exemple d'utilisation du programme avec un vecteur d'employés
    std::vector<TPEmploye> employes = {
        {1, "John Doe", 250},
        {2, "Jane Doe", 400},
        {3, "Bob Smith", 600}
    };

    // Affichage du salaire brut total et de la somme des contributions CNSS
    std::cout << "Salaire Brut total : " << SalaireBrut(employes) << std::endl;
    std::cout << "Somme CNSS : " << SommeCNSS(employes) << std::endl;

    return 0;
}
