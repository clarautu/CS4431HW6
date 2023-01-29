// Vehicle class - header file
// Autumn Clark
// For HW6

#pragma once
#include <string>

class Vehicle {
private:
  int year;
  long int miles;
  int value;
  std::string manufacture;
  std::string model;
  // Need to change this so that I can calculate partial year percents
  float value_date; // Entered as float form Year.DayOfYear - i.e. Jan 7, 1996 = 1996.007
public:
  //Constructors
  Vehicle(int year, long int miles, int value,
    std::string manufacture, std::string model, float value_date);
  Vehicle(); // Default constructor
  // Destructor
  ~Vehicle();
  // Getters
  int GetYear() const;
  long int GetMiles() const;
  int GetValue() const;
  std::string GetManufacture() const;
  std::string GetModel() const;
  float GetValueDate() const;
  // Setters
  void SetYear(int year);
  void SetMiles(long int miles);
  void SetValue(int value);
  void SetManufacture(std::string manufacture);
  void SetModel(std::string model);
  // Methods
  void UpdateValue(float current_date);
  float EstimateValue(float estimate_date) const;
};
