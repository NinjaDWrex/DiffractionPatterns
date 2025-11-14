/*
  WavelengthToRGB.cpp - Library for converting wavelength (380nm - 780) to approximate RGB values.
  Created by Jamie G. Howard, September 25, 2018.
  Released into the public domain.

  Edited - Library for converting for deskop use with raylib.
  Edited by Kerem Yaprak, November 2, 2025.
  Re - Releasing to public domain.
*/
#pragma once
class WavelengthToRGB
{
  public:
    WavelengthToRGB();
	void Convert(int wavelength,double gamma, int maxint);
	int Adjust(double colour, double factor);
	int GetRed();
	int GetGreen();
	int GetBlue();

	
  private:
    int _MaxIntensity;
	double _Gamma;
	
	double _Red;
	double _Green;
	double _Blue;
	double _Factor;

	int RED_VALUE;
	int GREEN_VALUE;
	int BLUE_VALUE;	

};
