//
// Created by Claudia Steiner on 18.05.24.
//

#include "carRental.h"
#include "exceptions.h"
#include <iostream>
#include <map>

//Fügt ein neues Auto in std::map<int, Car*> cars hinzu. Der Rückgabewert ist eine eindeutige ID, die das Auto identifiziert
int CarRental::addCar(Car *car) {
    int id = cars.size();
    cars[id] = car;
    return id;
}

//gitb das Auto mit der angegebenen ID zurück
Car *CarRental::getCar(int id) {
    if(cars.find(id) == cars.end()) {
        throw InvalidCarException("Car *CarRental::getCar Auto existiert nicht");
    }
    return cars[id];
}

//Entfernt das Auto mit der angegebenen ID und gibt alle damit verbundenen Ressourcen wieder frei
void CarRental::deleteCar(int id) {
    if(cars.find(id) == cars.end()) {
        throw InvalidCarException("Car *CarRental::deleteCar Auto existiert nicht");
    }
    cars.erase(id);
}


//Gibt ein passendes fahrtüchtiges Auto zurück,
// dass mit der angegeben Führerscheinklasse
// gefahren werden darf und mindestens die
// angegebene Anzahl an Passagieren befördern kann.
// Dabei sollen die frei bleibenden Passagierplätze minimal
// sein. Das Auto darf auch nicht schon an andere vermietet
// und muss fahrtüchtig sein. Die Fahrtüchtigkeit
// wird mit der checkCar()-Objektfunktion überprüft.
// Falls kein passendes Fahrzeug gefunden werden konnte,
// soll eine NoCarFoundException geworfen werden.

Car *CarRental::rentCar(int licenceType, int passengerCount) {
    Car *bestCar = nullptr;
    int bestFreeSeats = 0;

    for(auto &car : cars) {
        if(car.second->getRequiredDrivingLicense() <= licenceType &&
           car.second->getPassengerCount() >= passengerCount &&
           car.second->checkCar()) {
            int freeSeats = car.second->getPassengerCount() - passengerCount;
            if(bestCar == nullptr || freeSeats < bestFreeSeats) {
                bestCar = car.second;
                bestFreeSeats = freeSeats;
            }
        }
    }

    if(bestCar == nullptr) {
        throw NoCarFoundException("Car *CarRental::rentCar Kein passendes Auto gefunden");
    }

    return bestCar;
}


//Simuliert die angegebene Anzahl an Mietvorgängen. Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.
void CarRental::simulate(int rentals) {

    //für die Anzahl an Mietvorgängen
    for(int i = 0; i < rentals; i++) {

        //zufällige Führerscheinklasse und Anzahl an Passagieren
        int licenceType = rand() % 5 + 1;
        int passengerCount = rand() % 10 + 1;

        try {
            Car *car = rentCar(licenceType, passengerCount);
            std::cout << "Auto gemietet: " << car->getName() << ", Führerscheinklasse " << licenceType << ", Passagiere " << passengerCount << std::endl;
        } catch(NoCarFoundException &e) {
            std::cout << e.what() << std::endl;
        } catch(InvalidCarException &e) {
            std::cout << e.what() << std::endl;
        } catch(BrokenMotorException &e) {
            std::cout << e.what() << std::endl;
        } catch(ElectronicsFaultException &e) {
            std::cout << e.what() << std::endl;
        } catch(EmissionsTooDirtyException &e) {
            std::cout << e.what() << std::endl;
        }
    }
}