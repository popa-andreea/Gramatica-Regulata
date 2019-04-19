# Gramatica-Regulata

Nume:Popa Andreea-Denisa

Descriere: Pentru o gramatica regulata, sa se genereze toate cuvintele avand o lungime maxima data.

Input: O gramatica regulata si un numar natural,n.
Output: Lista cuvintelor de dimensiune n recunoscute de gramatica.

Observatii:
Simbolul "?" ii corespunde simbolului lambda.
Fiecare productie este de forma: neterminala1 -> terminala neterminala2 sau neterminala1->terminala. Atunci cand se neterminala2 nu exista, aceste este inlocuit cu lambda.

Functii:
void citireGramaticaRegulata(productie *&gramaticaRegulata, int &numarProductii)
-functia citeste din fisierul "gramatica.txt" elementele vectorului care reprezinta productiile gramaticii regulate;                    
-fiecare element al vectorului este construit din neterminala1,terminala si neterminala2;
-functia inlocuieste neterminala2 cu lambda,in cazul in care neterminala2 lipseste.

void afisareGramaticaRegulata(productie *gramaticaRegulata, int numarProductii)
-functia afiseaza pe ecran productiile gramaticii regulate.

void generareCuvinte(productie *gramaticaRegulata,int numarProductii, int lungimeMaxima, string *cuvant, int contorCuvant,string neterminala)
-functia afiseaza lista cuvintelor de lungime maxima recunoscute de gramatica;
-functia genereaza cuvintele de dimensiune lungimeMaxima, verifica pentru fiecare cuvant daca este recunoscut de gramatica si daca este recunoscut,il afiseaza pe ecran.
