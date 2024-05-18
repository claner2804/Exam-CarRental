//
// Created by Claudia Steiner on 18.05.24.
//

#include "carRental.h"
#include "exceptions.h"
#include <iostream>
#include <map>
#include <print>

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
    std::string carName = cars[id]->getName();

    std::cout << "Auto mit ID " << id << " und Name " << carName << " wurde aus der Verwaltungssoftware gelöscht." << std::endl;

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
           car.second->getPassengerCount() >= passengerCount) {
            try {
                if(car.second->checkCar()) {
                    int freeSeats = car.second->getPassengerCount() - passengerCount;
                    if(bestCar == nullptr || freeSeats < bestFreeSeats) {
                        bestCar = car.second;
                        bestFreeSeats = freeSeats;
                    }
                }
            } catch(BrokenMotorException &e) {
                deleteCar(car.first); // remove the car from the system
                throw; // rethrow the exception
            } catch(ElectronicsFaultException &e) {
                deleteCar(car.first); // remove the car from the system
                throw; // rethrow the exception
            } catch(EmissionsTooDirtyException &e) {
                // do not remove the car from the system
            }
        }
    }

    if(bestCar == nullptr) {
        std::cout << "Auto mit Führerscheinklasse " << licenceType << " und " << passengerCount << " nicht existent." << std::endl;
        throw NoCarFoundException("Kein passendes Auto gefunden.");
    }

    return bestCar;
}


//Simuliert die angegebene Anzahl an Mietvorgängen. Die Führerscheinklasse und die Anzahl an Passagieren soll dabei bei jedem Mietvorgang zufällig bestimmt werden.
void CarRental::simulate(int rentals) {

    std::cout << "die Mietprozesse starten!" << std::endl;

    sleep(1);

    //für die Anzahl an Mietvorgängen
    for(int i = 0; i < rentals; i++) {

        std::cout << "----------------------------------------------------" << std::endl;

        std::cout << "Mietvorgang " << i+1 << std::endl;

        std::cout << "----------------------------------------------------" << std::endl;

        sleep(1);

        //zufällige Führerscheinklasse und Anzahl an Passagieren
        int licenceType = rand() % 5 + 1;
        std::cout << "Führerscheinklasse: " << licenceType << std::endl;
        int passengerCount = rand() % 10 + 1;
        std::cout << "Passagiere: " << passengerCount << std::endl;

        std::cout << "versuche Auto zu mieten..." << std::endl;

        try {
            Car *car = rentCar(licenceType, passengerCount);
            std::cout << "Auto gemietet: " << car->getName() << ", Führerscheinklasse " << licenceType << ", Passagiere " << passengerCount << std::endl;
        } catch(NoCarFoundException &e) {
            std::cout << e.what() << std::endl;
        } catch(InvalidCarException &e) {
            std::cout << e.what() << std::endl;
        } catch(BrokenMotorException &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Auto brokenmotor wird aus dem System entfernt." << std::endl;
            i--; // retry the rental
        } catch(ElectronicsFaultException &e) {
            std::cout << e.what() << std::endl;
            std::cout << "Auto electronicsfault wird aus dem System entfernt." << std::endl;
            i--; // retry the rental
        } catch(EmissionsTooDirtyException &e) {
            std::cout << e.what() << std::endl;
        }
        }
}

CarRental::CarRental() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Die Autovermietung eröffnet feierlich seine Pforten.." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;



}


CarRental::~CarRental() {
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Die Autovermietung schließt..." << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;



}