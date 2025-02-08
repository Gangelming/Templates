#pragma once
#include <vector>
#include <string>

class MenuMath {
private:
    std::vector<std::string> options;
    std::vector<std::string> matrixSizeOptions;
    int indexSelectionne;

    void afficherMenu();
    void afficherMenuMatrices();
    int selectionnerTailleMatrice();
    void gererTouchePressee();
    void executerOperation();

    void executerProduitScalaire();
    void executerNormalisation();
    void executerAdditionVecteurs();
    void executerProduitVectoriel();
    void executerMultiplicationMatrices();


    template<size_t SIZE>
    void executerMultiplicationMatricesNxN();

public:
    MenuMath();
    void executer();
};