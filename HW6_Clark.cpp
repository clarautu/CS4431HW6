// Homework 6
// Autumn Clark
// Accumulate and lambda functions

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Contains sort functions
#include <numeric> // Contains accumulate
#include "VehicleClass.h"
#include "TruckClass.h"

// Method that takes a const reference to a vector of trucks and a date
  // then returns a vector of floats of the trucks estimated values on the passed date
std::vector<float> EstVal(std::vector<Truck> const& trucks, float const& estimate_date){
  std::vector<float> values; // Create a float vector to holds values
  for(int i=0; i<trucks.size(); i++){ // Loop through each truck in trucks
    // Add the estimated value of each truck on the estimate date to values
    values.push_back(trucks.at(i).EstimateValue(estimate_date));
  }
  return values;
}

// ostream operator overload implementation -- declared as friend in TruckClass.h
std::ostream& operator<<(std::ostream& os, const Truck& t) {
  return os << t.GetName();}

int main(){
  // Part 1
  std::vector<Truck> trucks; // Create a vector of trucks
  // Add five trucks to the vector
     // Truck general info pulled from cars.com ; towing capacity was Googled and then the rough middle for the range was taken
  trucks.push_back(Truck(2019,19850,39290,"Chevy","Silverado 1500 LT",2021.045,true,8300));
  trucks.push_back(Truck(2017,17647,45998,"Chevy","Silverado 2500 LTZ",2021.045,true,13750));
  trucks.push_back(Truck(2018,33549,46995,"Ford","F-150 Lariat",2021.045,true,6000));
  trucks.push_back(Truck(2018,40052,37960,"Ram","1500 Laramie",2021.045,true,6200));
  trucks.push_back(Truck(2016,98820,47470,"GMC","Sierra 2500 Denali",2021.045,true,13000));
  trucks.push_back(Truck(2007,140900,10595,"Chevy","Silverado 1500 Work",2021.120,false,6000));
  trucks.push_back(Truck(2019,10816,27195,"Ford","Ranger XL",2021.120,false,3500));
  trucks.push_back(Truck(1994,194658,5995,"Chevy","2500 Base",2021.120,false,6000));
  trucks.push_back(Truck(2000,248900,4000,"Ford","F-150 XL Supercab Flareside",2021.120,false,8700));
  trucks.push_back(Truck(2004,206474,9490,"Toyota","Tacoma PreRunner Xtracab",2021.120,false,3500));
  // Update first five trucks to value date 04/01/2021 -- 120 days into the year
  for (int i=0; i<5; i++){
    trucks.at(i).UpdateValue(2021.120);
  }

  // Part 2 -- find the value of all 10 trucks using accumulate and a lambda function
  float total = accumulate(begin(trucks),end(trucks), 0,
    [](float total, Truck t) {return total += t.GetValue();} );
  std::cout << "The total value of the trucks is: $" << total << std::endl;

  // Part 3
  // Find the estimated values in 5 years using EstVal()
  std::vector<float> estimates = EstVal(trucks, 2026.120);
  // Find the total estimated value in 5 years using accumulate()
  float estTotal = accumulate(begin(estimates), end(estimates), 0,
    [](float total, float val) {return total += val;} );
  std::cout << "Estimated total value in five years: $" << estTotal << std::endl;

  // Part 4 -- code to test if ostream overload worked
  //std::cout << trucks.at(0) << std::endl;

  // Part 5
  // Sort truck alphabetically by GetName() -- operator< was overloaded for this
  stable_sort(begin(trucks),end(trucks));
  std::cout << "Trucks sorted by GetName(): " << std::endl;
  for(Truck truck : trucks){
    std::cout << "\t" << truck << std::endl;
  }
  // Sort trucks by mileage via lambda function
  stable_sort(begin(trucks),end(trucks),
    [](Truck t1, Truck t2){return ((t1.GetMiles() < t2.GetMiles()) ? true : false);} );
  std::cout << "Trucks sorted by mileage: " << std::endl;
  for(Truck truck : trucks){
    std::cout << "\t" << truck << std::endl;
  }

  return 0;
}
