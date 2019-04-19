#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

typedef struct
{
    string neterminala1;
    string terminala;
    string neterminala2;

}productie;

void citireGramaticaRegulata(productie *&gramaticaRegulata, int &numarProductii)
{
	ifstream f("gramatica.txt");

	int i;
	f >> numarProductii;
	gramaticaRegulata = new productie[numarProductii];

	for( i = 0; i < numarProductii; i++)
	{
	    f >> gramaticaRegulata[i].neterminala1;
		if (gramaticaRegulata[i].neterminala1 >= "a" && gramaticaRegulata[i].neterminala1 <= "z")
        {
			gramaticaRegulata[i].terminala = gramaticaRegulata[i].neterminala1;
			gramaticaRegulata[i].neterminala1 = gramaticaRegulata[i - 1].neterminala2;
			gramaticaRegulata[i - 1].neterminala2 = "?";
			f >> gramaticaRegulata[i].neterminala2;

        }
        else
        {
            f >> gramaticaRegulata[i].terminala;
            f >> gramaticaRegulata[i].neterminala2;
        }

	}

	f.close();
}

void afisareGramaticaRegulata(productie *gramaticaRegulata, int numarProductii)
{
    int i;

	cout << "Simbolul '?' ii corespunde simbolului lambda.\nGramatica regulata este:\n";

    for( i = 0; i < numarProductii; i++)
    {
		cout << gramaticaRegulata[i].neterminala1 << "->";
		cout << gramaticaRegulata[i].terminala;

		if (gramaticaRegulata[i].neterminala2 != "?")
			cout << gramaticaRegulata[i].neterminala2;

		cout << endl;
    }
}

bool cuvantAcceptat(productie *gramaticaRegulata, int numarProductii, string neterminala)
{
    int i;

    for(i =0; i < numarProductii; i++)
        if(gramaticaRegulata[i].neterminala1 == neterminala && gramaticaRegulata[i].terminala == "?")
           return true;

    return false;
}

void generareCuv(productie *gramaticaRegulata, int numarProductii, int lungimeMaxima, string *cuvant, int contorCuvant, string neterminala)
{
    int i;

	if (lungimeMaxima == contorCuvant && (neterminala == "?" || cuvantAcceptat(gramaticaRegulata,numarProductii,neterminala)))
    {
		for (i = 0; i < lungimeMaxima; i++)
			cout << cuvant[i];
		cout << endl;
    }

	if (contorCuvant < lungimeMaxima)
    {
		for (i = 0; i < numarProductii; i++)
			if (gramaticaRegulata[i].neterminala1 == neterminala && gramaticaRegulata[i].terminala != "?")
            {
				cuvant[contorCuvant] = gramaticaRegulata[i].terminala;
				generareCuv(gramaticaRegulata, numarProductii, lungimeMaxima, cuvant, contorCuvant + 1, gramaticaRegulata[i].neterminala2);
            }
    }
}


int main()
{
	productie *gramaticaRegulata;
    string *cuvant;
	int numarProductii, n, i;
	citireGramaticaRegulata(gramaticaRegulata, numarProductii);
	afisareGramaticaRegulata(gramaticaRegulata, numarProductii);
	cout << "Tastati lungimea maxima a cuvintelor:";
	cin >> n;
	cout << "Cuvintele de lungime " << n << " sunt:\n";
	cuvant = new string[n];
	generareCuv(gramaticaRegulata, numarProductii, n, cuvant, 0, "S");
	return 0;
}

