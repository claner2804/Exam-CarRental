#include <iostream>
#include "car.h"
#include "carRental.h"
#include "vwBus.h"
#include "smallBus.h"
#include "ferrariF40.h"
#include "fordFocus.h"


int main() {

    CarRental carRental;
    carRental.addCar(new VwBus);
    carRental.addCar(new SmallBus);
    carRental.addCar(new FerrariF40);
    carRental.addCar(new FordFocus);

    carRental.simulate(3);

}
