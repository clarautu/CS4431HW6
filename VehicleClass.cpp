// Vehicle class - source file
// Autumn Clark
// For HW6

#include <iostream>
#include <string>
#include "VehicleClass.h"

// Constructors
Vehicle::Vehicle(int year, long int miles, int value,
   std::string manufacture, std::string model, float value_date):
   year(year), miles(miles), value(value), manufacture(manufacture), model(model), value_date(value_date)
   {
     // This test code clutters code, so it has been commented out
     //std::cout << "Constructing " << manufacture << " " << model << std::endl;
   }
Vehicle::Vehicle():
year(2015), miles(60000), value(20000), manufacture("Chevy"), model("Colorado"), value_date(2021.056)
{
  std::cout << "Constructing default " << manufacture << " " << model << std::endl;
}

// Destructor
Vehicle::~Vehicle()
{
  // This test code clutters code, so it has been commented out
  //std::cout << "Destructing " << manufacture << " " << model << std::endl;
}

// Getters
int Vehicle::GetYear() const {return year;}
long int Vehicle::GetMiles() const {return miles;}
int Vehicle::GetValue() const {return value;}
std::string Vehicle::GetManufacture() const {return manufacture;}
std::string Vehicle::GetModel() const {return model;}
float Vehicle::GetValueDate() const {return value_date;}

// Setters
void Vehicle::SetYear(int y){year = y;}
void Vehicle::SetMiles(long int m){miles = m;}
void Vehicle::SetValue(int v){value = v;}
void Vehicle::SetManufacture(std::string m){manufacture = m;}
void Vehicle::SetModel(std::string m){model = m;}

// Methods
// Method that updates a vehicle's value and value_date based on depreciation from year until current date
void Vehicle::UpdateValue(float current_date){
  // Find how old it is, in partial years
  float numOfYearsOld = static_cast<float>(current_date) - static_cast<float>(Vehicle::year);
  // Separate into the whole year value and the partial year value
  int wholeYears = static_cast<int>(numOfYearsOld);
  float partialYears = numOfYearsOld - wholeYears;
  // Calculate and update vehicle's depreciation for a whole year, then increment down
  float tempValue = Vehicle::value;
  while(wholeYears > 0){
    tempValue = tempValue - (tempValue * 0.15);
    wholeYears--;
  }
  // Once all whole years are done, calculate and update for the partial year
  float partialPercent = (partialYears / 365) * 0.15;
  tempValue = tempValue - (tempValue * partialPercent);
  Vehicle::value = tempValue;
  Vehicle::value_date = current_date;
}

// Method that estimates a vehicle's value based on depreciation from year until current date
// Does not change any of a vehicle's actual values - only estimates them
float Vehicle::EstimateValue(float estimate_date) const{
  // Find how old it is, in partial years
  float numOfYearsOld = static_cast<float>(estimate_date) - static_cast<float>(Vehicle::year);
  // Separate into the whole year value and the partial year value
  int wholeYears = static_cast<int>(numOfYearsOld);
  float partialYears = numOfYearsOld - wholeYears;
  // Calculate vehicle's depreciation for a whole year, then increment down
  float tempValue = Vehicle::value;
  while(wholeYears > 0){
    tempValue = tempValue - (tempValue * 0.15);
    wholeYears--;
  }
  // Once all whole years are done, calculate for the partial year
  float partialPercent = (partialYears / 365) * 0.15;
  tempValue = tempValue - (tempValue * partialPercent);
  return tempValue;
}
