#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream ulaz;
    double rad;
    double suma_pov = 0;
    double rez;
    double unos;
    double pov;

    int br_otoka;
    int counter = 0;
    ulaz.open ("2.in");

    cout << "Upisi radius ukupne povrsine: " << endl;
    cin >> rad;
    cout << "Upisi broj otoka te njihove radiuse: " << endl;
    cin >> br_otoka;

    double rad_otoka[br_otoka-1];
    double pov_otoka[br_otoka-1];

    pov = rad * rad* M_PI;

    if (ulaz.fail())
    {
        cout << "Došlo je do greške!"<< endl;
    }

    while(ulaz>>unos)
    {
        if(counter>1)
        {
            cout <<counter<<". " << unos<< endl;
            rad_otoka[counter-2] = unos;
            pov_otoka[counter-2] = rad_otoka[counter-2]*rad_otoka[counter-2] * M_PI;
            suma_pov += pov_otoka[counter-2];
        }
        counter++;
    }

    ulaz.close();

    rez = 1 - (suma_pov / pov);

    cout << "\nSuma pov: " << suma_pov;
    cout << "\nPov: " << pov;
    cout << "\nRez: " << roundf(rez*100)/100 << endl;

    return 0;
}
