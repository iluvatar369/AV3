#ifndef GAME_H //se establece para la clase
#define GAME_H
#include "CHARACTER.h" //se establece para composición
#include<iostream> //para imprimir.
using namespace std;

class GAME{//CLASE JUEGO
    private://atributos
        string nameG;
        string version;
        CHARACTER character;
    public://metodos
        //SOBRECARGA
        GAME(string _nameG, string _version, string, int, int, int);
        GAME(string nameG_, string version_);
        string getname();
        string getversion();
        void welcome();
};

//Constructor 1
GAME::GAME(string _nameG, string _version, string Game, int DamagePer, int TiltAttack, int Turn){
    CHARACTER ob(Game, DamagePer, TiltAttack, Turn); //COMPOSICIÓN
    nameG=_nameG;
    version=_version;
    character=ob;
}

//Constructor 2 (SOBRECARGA)
GAME::GAME(string nameG_, string version_){
    nameG= nameG_;
    version= version_;
}

//obtener nombre
string GAME::getname(){
    return nameG;
}

//obtener version
string GAME::getversion(){
    return version;
}

//bienvenida
void GAME::welcome(){
    cout<<"¡WELCOME! \nAND THIS IS!!"<<endl;
}

#endif // GAME_H
