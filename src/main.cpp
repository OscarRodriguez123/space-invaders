#include<iostream>
#include<string>
#include<thread>
#include<ftxui/dom/elements.hpp>
#include<ftxui/screen/screen.hpp>
#include<ftxui/screen/string.hpp>
#include<ftxui/screen/terminal.hpp>
#include<fstream>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    fstream archivo;

    archivo.open("./assets/images/canon.txt");
    string canon;
    archivo >> canon;
    archivo.close();

    archivo.open("./assets/images/alien.txt");
    string alien;
    archivo.close();


    int fotograma=0;
    while(true){

        fotograma++;
        Element tanque = text(canon) | bold | color(Color::Green1) | bgcolor(Color::Blue1) ;
        Element personaje = spinner(21,fotograma) | bold | color(Color::Blue1) | bgcolor(Color::Green1);
        Element lienzo = hbox({personaje , tanque});

        Screen pantalla = Screen::Create(
            Dimension::Full(),
            Dimension::Fit(lienzo)
             );



        Render(pantalla,lienzo);
        pantalla.Print();
        cout<<pantalla.ResetPosition();

        this_thread::sleep_for(0.1s);
     }
    return 0;
}
