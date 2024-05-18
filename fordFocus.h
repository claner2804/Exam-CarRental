//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_FORDFOCUS_H
#define KLAUSUR_FORDFOCUS_H

#include "car.h"
#include "exceptions.h"
#include  <iostream>

//	• Ford Focus
//		○ 4 Passagierplätze
//		○ Führerscheinklasse: 1
//		○ Hat eine 8% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
//		○ Hat eine 6% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
//Hat eine 15% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.


class FordFocus : public Car{

    int passengerSeats = 4;

    int requiredDriversLicense = 1;

    std::string name = "Ford Focus";

public:

    virtual std::string getName() override {
        return name;
    }

    int getRequiredDrivingLicense() override {
        return requiredDriversLicense;
    }

    int getPassengerCount() override {
        return passengerSeats;
    }

    //Hat eine 8% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
    bool isBrokenMotor()  {
        if (rand() % 100 < 8) {
            return true;
        } else {
            return false;
        }
    }

    //Hat eine 6% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
    bool isElectronicsFault()  {
        if (rand() % 100 < 6) {
            return true;
        } else {
            return false;
        }
    }

    //Hat eine 15% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
    bool isEmissionsTooDirty()  {
        if (rand() % 100 < 15) {
            return true;
        } else {
            return false;
        }
    }

    bool checkCar() override {
        if (isBrokenMotor()) {
            throw BrokenMotorException("Ford Fokus hat einen Motorschaden");
        } else if (isElectronicsFault()) {
            throw ElectronicsFaultException("Ford Focus hat einen Elektronikschaden");
        }  else if (isEmissionsTooDirty()) {
            throw EmissionsTooDirtyException("Ford Focus hat zu dreckige Emissionen");
        }
        else {
            return true;
        }
    }

    FordFocus() {
        std::cout << "Ford Focus hinzugefügt" << std::endl;
    }

    ~FordFocus() {
        std::cout << "Ford Focus verkauft" << std::endl;
    }
};


#endif //KLAUSUR_FORDFOCUS_H
