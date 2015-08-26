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
#include "src/GraphiqueEngine.h"
#include "src/Business/BusinessService.h"
#include "src/View/ViewFactory.h"
#include "src/View/ViewFPS.h"

using namespace std;
using namespace graphique;

int main()
{
    cout << "Graphique Engine!" << endl;

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

    business::BusinessInterface *business = new business::BusinessService();
    IView *view = ViewFactory::createEntity();
    cout << "GraphiqueEngine NOW !" << endl;
    IGraphiqueEngine *engine = GraphiqueEngine::createEngine();
    engine->setBusiness(business);
    engine->setView(view);

    engine->start();
    engine->run();
    engine->exit();
    engine->drop();
    cout << "[end]" << endl;
    return 0;
}
