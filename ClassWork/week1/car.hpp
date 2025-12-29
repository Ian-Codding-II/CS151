#pragma once
#include <iostream>

struct Car {
  Car(std::string m = "default", int y = 2000, std::string c = "red") {
    make = m;
    model = y;
    color = c;
  }
  std::string make;
  int model;
  std::string color;
};