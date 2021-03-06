/**
Datos
Proyecto SIMULACI�N DE PELEA
Diego Emilio Barrera Hern�ndez
A01366802


Descripci�n: Esta es la tercera entrega de la clase Programaci�n Orientado a Objetos.
El programa nos muestra una simulaci�n de un juego de pelea, d�nde tu eres el que
interact�a para que la batalla siga avanzando.
Ser�s un h�roe de cualquier juego(En este caso solamente de ZELDA) y vencer�s al Jefe Final de ese juego.
Solo tienes un Tilt Attack y un Smash Attack
El Tilt Attack puede ser un ataque cr�tico, pero solo es un 50% tener eso
Y el Smash Attack se cargar� cada tres turnos.
Si t� y tu oponente alcanzan el% 300 de su da�o, el juego terminar�
El ganador ser� el jugador que tenga menos porcentaje de da�o al final de la partida.
*/

//se llaman las clases creadas
#include"GAME.h"
#include"CHARACTER.h"
#include"TLOZELDA.h"
#include"GANONDORF.h"
#include<conio.h>
#include<iostream>//para imprimir.

using namespace std; //para no utilizar nuevamete std

int main(){
    //SE CREA EL OBJETO DE LA CLASE SMASH Y SE DA LA BIENVENIDA
    GAME smash("--PokeSmash--", "version:POO2");
    smash.welcome();
    cout<<smash.getname()<<"\n";
    cout<<smash.getversion()<<"\n"<<endl;
    cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __"<<endl;
    cout<<"|                                   RULES:                                             |"<<endl;
    cout<<"|You will be a hero of any game and you will need to defeat the Final Boss of that game|"<<endl;
    cout<<"|You only have a Tilt Attack and Smash Attack                                          |"<<endl;
    cout<<"|The Tilt Attack can be a Critic Attack, but it is only a 50% of having that           |"<<endl;
    cout<<"|And the Smash Attack will be charged every three turns                                |"<<endl;
    cout<<"|If you and your opponent reach the %300 of damage the game will end                   |"<<endl;
    cout<<"|The winner will be the player that has less damage percentage                         |"<<endl;
    cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __|"<<endl;

    cout<<"\n";
    cout<<"L E T - S T A R T!"<<endl;
    cout<<"\n";

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///SE CREAN LOS OBJETOS CPN BASE EN EL POLIMORFISMO CREADO DEL METDODO ShowInfoGame() DE LA CLASE CHARACTER
    CHARACTER *muestraInf[1];///APUNTADOR PARA EL POLIMORFISMO
    muestraInf[0] = new TLOZELDA ("THE LEGEND OF ZELDA", "Best Game in the world","The hero of time");///OBJETO DE TLOZELDA
    muestraInf[0] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)
    cout<<"\n";

    muestraInf[1] = new GANONDORF ("THE LEGEND OF ZELDA", "Dark master");///OBJETO DE GANONDORF
    muestraInf[1] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout<<"\n";
    cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

    int GD=0;
    int LD=0;//variables para el ciclo y el ataque especial
    int turn=0;

    while(GD<300||LD<300){//CICLO PARA LA SOMULACI�N DE PELEA
        turn++;
        TLOZELDA link ("The Legend Of Zelda", LD, 15, turn, "LINK", false, 0);//se utiliz� el primer constructor(SOBRECARGA)
        GANONDORF ganon ("The Legend Of Zelda", GD, 15, turn, "GANONDORF", false, 0);
        cout<<"--TURN:"<<link.GetTurn()<<"--"<<endl;
        cout<<"\n";
        cout<<"It is your turn"<<endl;
        link.GetMagicBar();//Llamada para el ataque especial
        link.Triforce(ganon);//Llamada para el ataque especial

        GD=ganon.DamageRecive(link.GetTiltAttack());

        cout<<"\n";
        cout<<"Now Ganondorfs Turn"<<endl;
        ganon.GetMagicG();//Llamada para el ataque especial
        ganon.Punch(link);//Llamada para el ataque especial

        LD=link.DamageRecive(ganon.GetTiltAttack());

        cout<<" _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
        cout<<"|GANONDORFs DAMAGE %"<<ganon.GetDamagePer()<<"  |"<<endl;
        cout<<"|LINKs DAMAGE %"<<link.GetDamagePer()<<"       |"<<endl;
        cout<<"|_ _ _ _ _ _ _ _ _ _ _ _|";
        cout<<"\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------";

        }

    if(GD<LD){//Si gana el jefe
        cout<<"GAME!\n";
        cout<<"You have met with a terrible fate!!\nHavent you?\nTHE DARK MASTER WINS!!"<<endl;
    }

    else if(LD<GD){//si gana el heroe
        cout<<"GAME!\n";
        cout<<"One more time you save Hyrule!! YOU WIN!!"<<endl;
    }
    else{
        cout<<"\n";
        cout<<"OH MY GOSH!! IT WAS A TIE!\nMay be you can win in the next game"<<endl;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    delete muestraInf[0];
    delete muestraInf[1];
    getch();
    return 0;
}
