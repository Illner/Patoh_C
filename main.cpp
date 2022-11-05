#include <vector>
#include <iostream>

#include "patoh.h"

int main(int argc, char *argv[])
{
    PaToH_Parameters args;
    PaToH_Initialize_Parameters(&args, PATOH_CONPART, PATOH_SUGPARAM_QUALITY);
    args.seed = 0;
    args._k = 2;

    int c = 12;
    int n = 11;

    std::vector<int> xpinsTmp = {0, 5, 7, 11, 13, 15, 19, 21, 25, 27, 29, 31};
    int* xpins = new int[n + 1];
    for (int i = 0; i < xpinsTmp.size(); ++i)
        xpins[i] = xpinsTmp[i];

    std::vector<int> pinsTmp = {2, 3, 5, 6, 9,
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
    int* pins = new int[pinsTmp.size()];
    for (int i = 0; i < pinsTmp.size(); ++i)
        pins[i] = pinsTmp[i];

    int cut;
    int* partvec = new int[c];
    int* partweights = new int[args._k];

    int* cwghts = new int[c];
    for (int i = 0; i < c; ++i) cwghts[i] = 1;

    PaToH_Alloc(&args, c, n, 1, cwghts, NULL, xpins, pins);

    PaToH_Part(&args, c, n, 1, 0, cwghts, NULL,
               xpins, pins, NULL, partvec, partweights, &cut);

    std::cout << "cut: " << cut << std::endl;

    std::cout << "partvec: ";
    for (int i = 0; i < c; ++i)
        std::cout << partvec[i] << " ";
    std::cout << std::endl;

    std::cout << "partweights: ";
    for (int i = 0; i < args._k; ++i)
        std::cout << partweights[i] << " ";
    std::cout << std::endl;

    PaToH_Free();

    delete [] xpins;
    delete [] pins;
    delete [] partvec;
    delete [] partweights;
    delete [] cwghts;

    return 0;
}
