//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_CAR_H
#define KLAUSUR_CAR_H

#include <stdexcept>
#include "exceptions.h"

class Car {



public:

    //Gibt den Namen des Autos zurück.
    virtual std::string getName() = 0;


    //Überprüft die Fahrtüchtigkeit des Autos
    // und gibt true zurück, wenn die Fahrtüchtigkeit gegeben ist.
    // Bei gefundenen Problemen wird eine Exception geworfen
    virtual bool checkCar() = 0;


    //Gibt die benötigte Führerscheinklasse zurück.
    virtual int getRequiredDrivingLicense() = 0;


    //Gibt die Anzahl der Passagierplätze zurück.
    virtual int getPassengerCount() = 0;


};


#endif //KLAUSUR_CAR_H
