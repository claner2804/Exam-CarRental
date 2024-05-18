//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_CARRENTAL_H
#define KLAUSUR_CARRENTAL_H

#include <map>
#include "car.h"
#include "exceptions.h"

class CarRental {

//Die Klasse CarRental repräsentiert die Autovermietung
// selber und implementiert die zentrale Verwaltungsfunktionen.
// Da ständig neue Autos aufgenommen und alte ausgeschieden werden, wird für deren Verwaltung ein dynamischer Datencontainer
// benötigt. Bestimmen Sie selbstständig einen passenden Datencontainer.
// Autos werden durch eindeutige nummerische IDs identifiziert.


protected:
    //Datencontainer für Autos, map mit int als Schlüssel und Car* als Wert
    std::map<int, Car*> cars;

public:
    //Fügt ein neues Auto hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert.
    int addCar(Car* car);

    //gitb das Auto mit der angegebenen ID zurück
    Car* getCar(int id);


    //Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei.
    void deleteCar(int id);

    //Gibt ein passendes fahrtüchtiges Auto
    // zurück, dass mit der angegeben Führerscheinklasse
    // gefahren werden darf und mindestens die
    // angegebene Anzahl an Passagieren befördern
    // kann. Dabei sollen die frei bleibenden Passagierplätze
    // minimal sein. Das Auto darf auch nicht schon
    // an andere vermietet und muss fahrtüchtig sein.
    // Die Fahrtüchtigkeit wird mit der checkCar()-Objektfunktion
    // überprüft. Falls kein passendes Fahrzeug gefunden werden konnte,
    // soll eine NoCarFoundException geworfen werden.
    Car* rentCar(int licenceType, int passengerCount);


    //Simuliert die angegebene Anzahl an Mietvorgängen.
    // Die Führerscheinklasse und die Anzahl an Passagieren
    // soll dabei bei jedem Mietvorgang zufällig bestimmt werden.
    void simulate(int rentals);


};


#endif //KLAUSUR_CARRENTAL_H
