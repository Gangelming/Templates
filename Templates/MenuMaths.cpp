#include "MenuMaths.h"
#include "math_vector.h"
#include "matrix.h"
#include <iostream>
#include <conio.h>

MenuMath::MenuMath() : options({
    "Produit scalaire",
    "Normalisation de vecteur",
    "Addition de vecteurs",
    "Produit vectoriel",
    "Multiplication de matrices",
    "Quitter"
    }), matrixSizeOptions({
    "Matrices 2x2",
    "Matrices 3x3",
    "Matrices 4x4",
    "Retour"
    }), indexSelectionne(0) {
}

// Fonction pour lire un vecteur 
MathVector<float, 3> lireVecteur3D(const std::string& nom) {
    float x, y, z;
    std::cout << "\n Entrez les composantes du vecteur " << nom << " (x y z): ";
    std::cin >> x >> y >> z;
    return MathVector<float, 3>({ x, y, z });
}

// Fonction pour lire une matrice
template<typename T, size_t SIZE>
Matrix<T, SIZE, SIZE> lireMatriceNxN(const std::string& nom) {
    Matrix<T, SIZE, SIZE> mat;
    std::cout << "\n Entrez les elements de la matrice " << nom << " (" << SIZE*SIZE << " nombres):\n";
    for (size_t i = 0; i < SIZE; ++i) {
        for (size_t j = 0; j < SIZE; ++j) {
            std::cout << " Element (" << i << "," << j << "): ";
            float val;
            std::cin >> val;
            mat(i, j) = val;
        }
    }
    return mat;
}

// Fonction pour afficher un vecteur
void afficherVecteur3D(const MathVector<float, 3>& vec, const std::string& nom) {
    std::cout << " " << nom << " = (" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")\n";
}

// Fonction pour afficher une matrice
template<typename T, size_t SIZE>
void afficherMatriceNxN(const Matrix<T, SIZE, SIZE>& mat, const std::string& nom) {
    std::cout << " " << nom << ":\n";
    for (size_t i = 0; i < SIZE; ++i) {
        std::cout << " [";
        for (size_t j = 0; j < SIZE; ++j) {
            std::cout << " " << mat(i, j);
        }
        std::cout << " ]\n";
    }
}

void MenuMath::afficherMenu() {
    std::cout << "\n Menu Mathematiques\n\n";
    for (size_t i = 0; i < options.size(); i++) {
        if (i == indexSelectionne) {
            std::cout << " --> ";
        }
        else {
            std::cout << "     ";
        }
        std::cout << options[i] << std::endl;
    }
}

void MenuMath::afficherMenuMatrices() {
    std::cout << "\n Selection de la taille des matrices\n\n";
    for (size_t i = 0; i < matrixSizeOptions.size(); i++) {
        if (i == indexSelectionne) {
            std::cout << " --> ";
        }
        else {
            std::cout << "     ";
        }
        std::cout << matrixSizeOptions[i] << std::endl;
    }
}

int MenuMath::selectionnerTailleMatrice() {
    indexSelectionne = 0;
    while (true) {
        system("cls");
        afficherMenuMatrices();
        char key = _getch();
        if (key == 72 && indexSelectionne > 0) { // Flèche haut
            indexSelectionne--;
        }
        else if (key == 80 && indexSelectionne < matrixSizeOptions.size() - 1) { // Flèche bas
            indexSelectionne++;
        }
        else if (key == 13) { // Entrée
            return indexSelectionne;
        }
        else if (key == 27) { // Échap
            return matrixSizeOptions.size() - 1; // Retour
        }
    }
}

void MenuMath::executerProduitScalaire() {
    std::cout << "\n Calcul du Produit Scalaire\n";

    auto v1 = lireVecteur3D("1");
    auto v2 = lireVecteur3D("2");

    float resultat = v1.dot_product(v2);

    std::cout << "\n Resultats:\n";
    afficherVecteur3D(v1, "Vecteur 1");
    afficherVecteur3D(v2, "Vecteur 2");
    std::cout << " Produit scalaire = " << resultat << "\n\n";

    std::cout << " Appuyez sur une touche pour continuer...";
    _getch();
}

void MenuMath::executerNormalisation() {
    std::cout << "\n Normalisation de vecteur\n";

    auto v = lireVecteur3D("initial");
    auto normalized = v.normalized();

    std::cout << "\n Resultats:\n";
    afficherVecteur3D(v, "Vecteur initial");
    afficherVecteur3D(normalized, "Vecteur normalise");

    std::cout << "\n Appuyez sur une touche pour continuer...";
    _getch();
}

void MenuMath::executerAdditionVecteurs() {
    std::cout << "\n Addition de vecteurs\n";

    auto v1 = lireVecteur3D("1");
    auto v2 = lireVecteur3D("2");
    auto resultat = v1 + v2;

    std::cout << "\n Resultats:\n";
    afficherVecteur3D(v1, "Vecteur 1");
    afficherVecteur3D(v2, "Vecteur 2");
    afficherVecteur3D(resultat, "Somme");

    std::cout << "\n Appuyez sur une touche pour continuer...";
    _getch();
}

void MenuMath::executerProduitVectoriel() {
    std::cout << "\n Produit vectoriel\n";

    auto v1 = lireVecteur3D("1");
    auto v2 = lireVecteur3D("2");
    auto resultat = v1.cross_product(v2);

    std::cout << "\n Resultats:\n";
    afficherVecteur3D(v1, "Vecteur 1");
    afficherVecteur3D(v2, "Vecteur 2");
    afficherVecteur3D(resultat, "Produit vectoriel");

    std::cout << "\n Appuyez sur une touche pour continuer...";
    _getch();
}

template<size_t SIZE>
void MenuMath::executerMultiplicationMatricesNxN() {
    std::cout << "\n Multiplication de matrices " << SIZE << "x" << SIZE << "\n";

    auto m1 = lireMatriceNxN<float, SIZE>("1");
    auto m2 = lireMatriceNxN<float, SIZE>("2");
    auto resultat = m1 * m2;

    std::cout << "\n Resultats:\n";
    afficherMatriceNxN(m1, "Matrice 1");
    afficherMatriceNxN(m2, "Matrice 2");
    afficherMatriceNxN(resultat, "Produit");

    std::cout << "\n Appuyez sur une touche pour continuer...";
    _getch();
}

void MenuMath::executerMultiplicationMatrices() {
    int choix = selectionnerTailleMatrice();
    switch (choix) {
        case 0: 
            executerMultiplicationMatricesNxN<2>();
            break;
        case 1:
            executerMultiplicationMatricesNxN<3>();
            break;
        case 2:
            executerMultiplicationMatricesNxN<4>();
            break;
        default:
            return;
    }
}

void MenuMath::executerOperation() {
    system("cls");
    switch (indexSelectionne) {
        case 0: executerProduitScalaire(); break;
        case 1: executerNormalisation(); break;
        case 2: executerAdditionVecteurs(); break;
        case 3: executerProduitVectoriel(); break;
        case 4: executerMultiplicationMatrices(); break;
        case 5: exit(0);
    }
}

void MenuMath::executer() {
    while (true) {
        system("cls");
        afficherMenu();
        char key = _getch();
        if (key == 72 && indexSelectionne > 0) { // Flèche haut
            indexSelectionne--;
        }
        else if (key == 80 && indexSelectionne < options.size() - 1) { // Flèche bas
            indexSelectionne++;
        }
        else if (key == 13) { // Entrée
            executerOperation();
        }
        else if (key == 27) { // Échap
            if (indexSelectionne != options.size() - 1) {
                indexSelectionne = options.size() - 1;
            }
            else {
                exit(0);
            }
        }
    }
}