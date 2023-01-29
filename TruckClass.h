// Truck Class - header file
// Autumn Clark
// For HW6

#pragma once
#include <string>
#include "VehicleClass.h"

class Truck : public Vehicle {
private:
  bool awd;
  int towing_capacity;
public:
  // Constructors
  Truck(int year, long int miles, int value, std::string manufacture,
    std::string model, float value_date, bool awd, int towing_capacity);
  Truck(); // Default constructor
  // Destructor
  ~Truck();
  // ostream operator friend declaration
  std::ostream& operator<<(std::ostream& os);

// Getters
bool GetAWD() const;
int GetTowingCapacity() const;
std::string GetName() const;

// Setters
void SetAWD(bool awd);
void SetTowingCapacity(int towing_capacity);

// Operator< overload
bool operator<(const Truck& t) const;
};
