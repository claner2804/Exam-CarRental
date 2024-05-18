//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_SMALLBUS_H
#define KLAUSUR_SMALLBUS_H

#include "car.h"
#include "exceptions.h"
#include <iostream>

//	• Kleinbus
//		○ 20 Passagierplätze
//		○ Führerscheinklasse: 4
//		○ Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
//		○ Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
//Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.

class SmallBus : public Car{

    int passengerSeats = 20;

    int requiredDriversLicense = 4;

    std::string name = "Small Bus";

public:

    //konstruktoren und destruktoren
    SmallBus() {
        std::cout << "Small Bus hinzugefügt" << std::endl;
    }

    ~SmallBus() {
        std::cout << "Small Bus verkauft" << std::endl;
    }

    virtual std::string getName() override {
        return name;
    }

    int getRequiredDrivingLicense() override {
        return requiredDriversLicense;
    }

    int getPassengerCount() override {
        return passengerSeats;
    }

    //Hat eine 15% Wahrscheinlichkeit eine BrokenMotorException zu werfen.
    bool isBrokenMotor()  {
        if (rand() % 100 < 15) {
            return true;
        } else {
            return false;
        }
    }

    //Hat eine 10% Wahrscheinlichkeit eine ElectronicsFaultException zu werfen.
    bool isElectronicsFault()  {
        if (rand() % 100 < 10) {
            return true;
        } else {
            return false;
        }
    }

    //Hat eine 5% Wahrscheinlichkeit eine EmissionsTooDirtyException zu werfen.
    bool isEmissionsTooDirty()  {
        if (rand() % 100 < 5) {
            return true;
        } else {
            return false;
        }
    }

    bool checkCar() override {
        if (isBrokenMotor()) {
            throw BrokenMotorException("SmallBus hat einen Motorschaden");
        }
        if (isElectronicsFault()) {
            throw ElectronicsFaultException("SmallBus hat einen Elektronikschaden");
        }
        if (isEmissionsTooDirty()) {
            throw EmissionsTooDirtyException("SmallBus hat zu dreckige Emissionen");
        }
        return true;
    }



};


#endif //KLAUSUR_SMALLBUS_H
