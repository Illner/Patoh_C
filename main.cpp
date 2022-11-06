#include <vector>
#include <iostream>

#include "patoh.h"

int main(int argc, char *argv[])
{
    int k = 2;
    int c = 12;
    int n = 11;

    PaToH_Parameters args;
    PaToH_Initialize_Parameters(&args, PATOH_CONPART, PATOH_SUGPARAM_QUALITY);
    args.seed = 1;
    args._k = k;

    int cut;
    std::vector<int> partvec(c, 0);
    std::vector<int> partweights(k, 0);
    std::vector<int> xpins = {0, 5, 7, 11, 13, 15, 19, 21, 25, 27, 29, 31};
    std::vector<int> pins = {2, 3, 5, 6, 9,
                             0, 1,
                             0, 1, 2, 3,
                             1, 3,
                             4, 5,
                             4, 5, 6, 7,
                             6, 7,
                             8, 9, 10, 11,
                             8, 11,
                             8, 10,
                             2, 5};

    PaToH_Alloc(&args, c, n, 1, NULL, NULL, xpins.data(), pins.data());

    PaToH_Part(&args, c, n, 1, 0, NULL, NULL,
               xpins.data(), pins.data(), NULL, partvec.data(), partweights.data(), &cut);

    std::cout << "cut: " << cut << std::endl;

    std::cout << "partvec: ";
    for (int i : partvec)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "partweights: ";
    for (int i : partweights)
        std::cout << i << " ";
    std::cout << std::endl;

    PaToH_Free();

    return 0;
}
