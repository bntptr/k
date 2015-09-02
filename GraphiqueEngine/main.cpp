/**
Aides:
*http://www.bruno-garcia.net/www/Cours/heritage.html
*https://fr.wikibooks.org/wiki/Programmation_C%2B%2B/Les_classes#Pr.C3.A9sentation_3
*http://frog.isima.fr/antoine/heritage.shtml
*/
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "kadriciellib.h"
#include "src/GraphiqueEngineFactory.h"
#include "src/Business/BusinessService.h"
#include "src/View/ViewFactory.h"
#include "src/View2d/View2dFactory.h"
#include "src/View3d/View3dFactory.h"

using namespace std;
using namespace graphique;

void loadLibrary() {
    cout << "kadriciel.a !" << endl;
    int ksampleInt = kSampleAddInt(1, 2);
    cout << ksampleInt << endl;
    int resultat = 0;
    resultat = carre(3);
    printf("Le resultat est %d\n", resultat);
    printf("Appuyez sur une touche pour continuer...");
    getchar();

    cout << "liblibkutility.so !" << endl;
    //int sampleInt = SampleAddInt(1, 2);
    //cout << sampleInt << endl;
    /*int ksampleInt = kSampleAddInt(1, 2);
    cout << ksampleInt << endl;
    kadriciel::A objetA;
    objetA.setValue(2);
    objetA.print();*/
    cout << "[NOK]" << endl;
}

void viewDefaultTest(business::BusinessInterface *business, IView *view) {
    cout << "View2d Default NOW !" << endl;
    IGraphiqueEngine *engine = GraphiqueEngineFactory::createEngine();
    engine->setBusiness(business);
    engine->setView(view);

    engine->start();
    engine->run();
    cout << "[end]" << endl;
}

int main()
{
    cout << "Graphique Engine!" << endl;

    loadLibrary();

    std::cout << "Please select the driver you want for this example:\n"\
        " (a) View\n (b) View2d\n (c) View3d\n"\
        " (d) ViewMenu\n (e) Exemple1\n"\
        " (f) Exemple2\n (otherKey) exit\n\n" << std::endl;

    char i;
    IView *view;

    std::cin >> i;

    switch(i)
    {
        case 'a': view = ViewFactory::createEntity();   break;
        case 'b': view = View2dFactory::createEntity(); break;
        case 'c': view = View3dFactory::createEntity(); break;
        case 'd': view = ViewFactory::createEntity();   break;
        case 'e': view = ViewFactory::createEntity();   break;
        case 'f': view = ViewFactory::createEntity();   break;
        default:
            return 1;
    }
    business::BusinessInterface *business = new business::BusinessService();

    viewDefaultTest(business, view);

    return 0;
}
