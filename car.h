//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_CAR_H
#define KLAUSUR_CAR_H

#include "carRental.h"

class Car : public CarRental{ //todo: check if inheritance is correct

public:
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
