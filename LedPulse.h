
/* 
* Log.h - Library for making an LED blink or pulse without using delay()
*
* Created: 01.09.2014 13:29:17
* Author: Alexandre Schaeffer
*/


#ifndef LedPulse_h
#define LedPulse_h

#include "WString.h"
#include "Arduino.h"

class LedPulse
{
//variables
public:
protected:
private:	
	unsigned long _previousMillis = 0;  // will store last time the LED's state was switched
	unsigned long _intervalLow;			// how long the LED stays off (milliseconds)
	unsigned long _intervalHigh;		// how long the LED stays on (milliseconds)
	int _periode;						// length of a pulse (milliseconds)
	int _ledState = LOW;
	int _value;
	int _ledPin;
	unsigned long _currentMillis;
//functions
public:
	LedPulse();
	/**
	 * \brief 
	 * Initializes the LedPulse class (use in the setup method)
	 * \param 
	 * \return void
	 */
	void begin(int ledPin);
	void begin(int ledPin, int periode);
	void begin(int ledPin, int intervalLow, int intervalHigh);
	void blink();
	void pulse();
	void high();
	void low();
	~LedPulse();
protected:
private:
}; //LedPulse

#endif //LedPulse_h
