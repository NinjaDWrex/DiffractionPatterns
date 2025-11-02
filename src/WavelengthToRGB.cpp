/*
  WavelengthToRGB.cpp - Library for converting wavelength (380nm - 780) to approximate RGB values.
  Created by Jamie G. Howard, September 25, 2018.
  Released into the public domain.

  Edited - Library for converting for desktop use with raylib.
  Edited by Kerem Yaprak, November 2, 2025.
  Re - Releasing to public domain.
*/
#include "WavelengthToRGB.h"
#include <cmath>

WavelengthToRGB::WavelengthToRGB(){
}

void WavelengthToRGB::Convert(int wavelength, double gamma, int maxint){
	_Gamma = gamma;
	_MaxIntensity = maxint;
	
	  switch (wavelength) {

    case 380 ... 439:
      _Red = -(wavelength - (double) 440) / ((double) 440 - (double) 380);
      _Green = 0.0;
      _Blue = 1.0;
      break;

    case 440 ... 489:
      _Red = 0.0;
      _Green = (wavelength - (double) 440) / ((double) 490 - (double) 440);
      _Blue = 1.0;
      break;

    case 490 ... 509:
      _Red = 0.0;
      _Green = 1.0;
      _Blue = -(wavelength - (double) 510) / ((double) 510 - (double) 490);
      break;

    case 510 ... 579:
      _Red = (wavelength - (double) 510) / ((double) 580 - (double) 510);
      _Green = 1.0;
      _Blue = 0.0;
      break;

    case 580 ... 644:
      _Red = 1.0;
      _Green = -(wavelength - (double) 645) / ((double) 645 - (double) 580);
      _Blue = 0.0;
      break;

    case 645 ... 780:
      _Red = 1.0;
      _Green = 0.0;
      _Blue = 0.0;
      break;
  }
  switch (wavelength) {
    case 380 ... 419:
      _Factor = 0.3 + 0.7 * (wavelength - (double) 380) / ((double) 420 - (double) 380);
      break;

    case 420 ... 700:
      _Factor = 1.0;
      break;

    case 701 ... 780:
      _Factor = 0.3 + 0.7 * ((double) 780 - wavelength) / ((double) 780 - (double)700);
      break;
  }

  RED_VALUE = Adjust(_Red, _Factor);
  GREEN_VALUE = Adjust(_Green, _Factor);
  BLUE_VALUE = Adjust(_Blue, _Factor);

}

int WavelengthToRGB::Adjust(double colour, double factor){
  if (colour == 0.0) {
    colour = 0;
  }
  else {
    colour = round(_MaxIntensity * pow(colour * factor, _Gamma));
  }
  return (int) colour;
}

int WavelengthToRGB::GetRed(){
	return RED_VALUE;
}

int WavelengthToRGB::GetGreen(){
	return GREEN_VALUE;
}

int WavelengthToRGB::GetBlue(){
	return BLUE_VALUE;
}
