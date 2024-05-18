//
// Created by Claudia Steiner on 18.05.24.
//

#ifndef KLAUSUR_FERRARIF40_H
#define KLAUSUR_FERRARIF40_H

#include "car.h"
#include <iostream>
#include "exceptions.h"



//	• Ferrari F40
//		○ 1 Passagierplatz
//		○ Führerscheinklasse: 3
//Ein Ferrari kann nicht kaputt gehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.

class FerrariF40 : public Car{

        int passengerSeats = 1;

        int requiredDriversLicense = 3;

    public:

            int getRequiredDrivingLicense() override {
                return requiredDriversLicense;
            }

            int getPassengerCount() override {
                return passengerSeats;
            }

            //Ein Ferrari kann nicht kaputt gehen, daher kommt es bei diesem Fahrzeug zu keiner Exception.
            bool checkCar() override {
                return true;
            }

            bool isBrokenMotor()  {
                return false;
            }

            bool isElectronicsFault()  {
                return false;
            }

            bool isEmissionsTooDirty()  {
                return false;
            }

};


#endif //KLAUSUR_FERRARIF40_H
