#ifndef CHARACTER_H
#define CHARACTER_H
#include<iostream> //para imprimir.
#include<cstdlib>//para Random
#include<ctime>//para afirmar el Random
using namespace std;

class CHARACTER{//CLASE PERSONAJE (PAPÁ)
    private://Atributos privados
        int TiltAttack;
    protected://Atributos protegidos
        string Game;
        string info;
        int DamagePer;
        int Turn;
    public://Metodos
        CHARACTER(string, int, int, int);
        CHARACTER(string);
        CHARACTER(){}//Constructor para composición
        virtual void ShowInfoGame();///metodo para polimorfismo
        int DamageRecive(int DamageRecive);
        int GetTiltAttack();
        int GetTurn();
        int GetDamagePer();
        void SetDamagePer(int DP);

};

//Constructor
CHARACTER::CHARACTER(string _Game, int _DamagePer, int _TiltAttack, int _Turn){
    Game=_Game;
    DamagePer=_DamagePer;
    TiltAttack=_TiltAttack;
    Turn=_Turn;
}

CHARACTER::CHARACTER(string Gam){
    Game=Gam;
}

//Información del juego
void CHARACTER::ShowInfoGame(){///metodo polimorfismo que manda juego
    cout<<"You chose ";
    cout<<Game;
}

//Obtener turno
int CHARACTER::GetTurn(){
    return Turn;
}

//Metodo para reducir la vida dependiendo el ataque
int CHARACTER::DamageRecive(int DamageRecive){
    DamagePer = DamagePer + DamageRecive;
    return DamagePer;
}

//Para obtener el ataque normal dependiendo el random
int CHARACTER::GetTiltAttack(){
    if(Turn%3!=0){
        srand(time(0));//Número random
        int num;
        num=0;
        int cont;//Variable para la seleccion
        cout<<"Choose number 1 to attack!"<<endl;
        cout<<"attack? 1)YES"<<endl;
        cin>>cont;
        cout<<"\n";

        if(cont==1){//si la selección sí es 1
            num=rand()%11;//Variable para random
            if(num%2==0){//si el random es par entonces vale 25
                TiltAttack=25;
                cout<<"<Critic Tilt Attack of ";
                cout<<TiltAttack<<">\n";
                return TiltAttack;
            }
            else{//Sino vale 15
                TiltAttack=15;
                cout<<"<Tilt Attack of ";
                cout<<TiltAttack<<">\n";
                return TiltAttack;
            }
        }
    }
}

//obtener porcentaje de daño
int CHARACTER::GetDamagePer(){
    return DamagePer;
}

//Para modificar el daño
void CHARACTER::SetDamagePer(int DP){
    DamagePer=DP;
}

#endif // CHARACTER_H
