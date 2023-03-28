#include <iostream>
#include <string.h>
#include <cstring>
#include <ctype.h>


using namespace std;

int password_checker(char*s)
{
    int lower=1; //variabila daca trebuie sa adaugam o litera mica (o schimbare necesara)
    int upper=1; ////variabila daca trebuie sa adaugam o litera mare (o schimbare necesara)
    int nr=1;   //variabila daca trebuie sa adaugam un numar (o schimbare necesara)
    int change=0;   //numarul de schimbari necesare parolei pentru a deveni puternica
    int add=0;      //numarul de caractere pe care trebuie sa-l adaugam parolei
    int delete1=0;  //numarul de caractere pe care trebuie sa-l stergem din parola

    for(int i=0; i<strlen(s); i++) // in acest "for" verificam aparitia a 3 caractere consecutive si daca gasim litere mici,mari sau numere in parola
    {

        if(islower(s[i]))
            lower=0;
        else if(isupper(s[i]))
            upper=0;
        else if(isdigit(s[i]))
            nr=0;

        int j=i;
        int counter=0;
//avem nevoie sa rezolvam prezenta a 3 caractere consecutive dar avem nevoie de o solutie minima si daca sunt mai mult de 3 caractere consecutive "11111"
//vom numara cate caractere consecutive sunt si apoi vom impartii la 3 deoarece pentru un grup de 3 caractere avem nevoie de o singura schimbare
        while(s[j]==s[j+1])
        {
            counter++;
            j++;
        }
        i=j; // se va continua de la urmatorul caractere diferit de cel precedent
        change=change+(counter/3);
    }

    int missingtypes=nr+lower+upper; //tipurile de caractere care lipsesc

    if(strlen(s)<6) // daca parola are mai putin de 6 caractere inseamna ca trebuie sa adaugam caractere pana cand lungimea ei ajunge la 6
    {
        add=6-strlen(s);
        if(add>=missingtypes) //vom introduce in parola ce avem nevoie pentru a face parola puternica
            change=change+add;  //cand introducem caractere putem introduce litere mici,mari sau numere pentru a ne asigura ca parola respecta conditia 2
        else
            change=change-add+missingtypes;
    }
    else if(strlen(s)>20) // daca parola are mai mult de 20 caractere inseamna ca trebuie sa stergem caractere pana cand lungimea ei ajunge la 20
    {
        delete1=strlen(s)-20;
        if(change<missingtypes) //verificam cate tipuri de caractere avem nevoie sa introducem in parola
            change=missingtypes;    //pentru a ne asigura ca nu sunt 3 caractere consecutive la fel putem sa minimizam schimbarile prin inlocuire cu tipurile de caractere lipsa (EX "aaa"->"aaA")
        change=change+delete1; //apoi adaugam la numarul de schimbari necesare cate caractere trebuie sa stergem
    }
    else if(change<missingtypes) //daca parola respecta numarul de caractere atunci trebuie sa ne asiguram ca respecta conditiile 3 si 2
        change=missingtypes;

    return change;
}

int main()
{
    char *s=(char*)calloc(100,sizeof(char));
    cin>>s;
    cout<<"numarul de schimbari: "<<password_checker(s);

    return 0;
}
