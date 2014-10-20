/* 
* LedPulse.cpp - Library for making an LED blink or pulse without using delay()
*
* Created: 01.09.2014 13:29:11
* Author: Alexandre Schaeffer
*/


#include "Arduino.h"
#include "LedPulse.h"

// default constructor
LedPulse::LedPulse()
{
} //Log

// default destructor
LedPulse::~LedPulse()
{
} //~Log

void LedPulse::begin(int ledPin)
{
	_ledPin = ledPin;
	pinMode(_ledPin, OUTPUT);
	_periode = 1000;
	_intervalHigh = _periode/2;
	_intervalLow = _periode/2;
}

void LedPulse::begin(int ledPin, int periode)
{
	_ledPin = ledPin;
	pinMode(_ledPin, OUTPUT);
	_periode = periode;
	_intervalHigh = _periode/2;
	_intervalLow = _periode/2;
}

void LedPulse::begin(int ledPin, int intervalLow, int intervalHigh)
{
	_ledPin = ledPin;
	pinMode(_ledPin, OUTPUT);
	_periode = intervalHigh + intervalLow;
	_intervalHigh = intervalHigh;
	_intervalLow = intervalLow;
}

void LedPulse::blink()
{
	_currentMillis = millis();
	if (_currentMillis - _previousMillis >= _intervalHigh && _ledState == HIGH)
	{
		_previousMillis = _currentMillis;
		_ledState = LOW;
		digitalWrite(_ledPin, _ledState);
	}
	else if (_currentMillis - _previousMillis >= _intervalLow && _ledState == LOW)
	{
		_previousMillis = _currentMillis;
		_ledState = HIGH;
		digitalWrite(_ledPin, _ledState); 
	}	
}

void LedPulse::pulse()
{
	_currentMillis = millis();
	int val = 128+127*cos(2*PI/_periode*_currentMillis);
	if (val != _value)
	{
		_value = val;
		analogWrite(_ledPin, _value);
	}
	
}

void LedPulse::high()
{
	_ledState = HIGH;
	digitalWrite(_ledPin, _ledState);
}

void LedPulse::low()
{
	_ledState = LOW;
	digitalWrite(_ledPin, _ledState);
}