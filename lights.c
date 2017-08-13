#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include <stdint.h>
#include "lights.h"

// States
#define S_OFF 0
#define S_START 1
#define S_ON 2
#define S_END 3

// Modes
#define M_DEFAULT 0

// Defaults
#define LED_PIN 6
#define NUMPIXELS 290

// Speeds
#define START_SPEED 2
#define END_SPEED 1

uint_8 led_state = S_OFF;
uint_8 led_mode = M_DEFAULT;
uint_16 led_power = 0;
uint_16 led_counter = 0;
uint_16 led_frame = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void led_start(uint_8 mode)
{
	led_state = S_START;
	led_mode = mode;
	led_frame = 0;
	led_counter = 0;
}

void led_turn_off()
{
	for(int i = 0; i < NUMPIXELS; i++)
	{
		pixels.setPixelColor(i, pixels.Color(0, 0, 0));
	}
}

void led_start() {
	led_start(M_DEFAULT);
}

void led_end()
{
	led_state = S_END;
}

void led_update()
{
	switch(led_state)
	{
	case S_OFF:
		return;
	case S_START:
		led_update_start();
		break;
	case S_ON:
		break;
	case S_END:
		led_update_end();
		break;
	default:
		led_turn_off();
		state = S_END;
		return;
	}
	
	led_update_strip();
}

void led_update_start()
{
	if(led_counter >= START_SPEED)
	{
		led_power++;
		led_counter = 0;
		if(led_power >= NUMPIXELS)
		{
			state = S_ON;
		}
	}
	else
	{
		led_counter++;
	}
}

void led_update_end()
{
	if(led_counter >= END_SPEED)
	{
		led_power--;
		led_counter = 0;
		if(led_power <= 0)
		{
			led_state = S_OFF;
		}
	}
	else
	{
		led_counter++;
	}
}

void led_update_strip()
{
	for(int i = 0; i < NUMPIXELS; i++)
	{
		if(i <= led_power)
		{
			pixels.setPixelColor(i, pixels.Color(0, 0, 20));
		}
		else
		{
			pixels.setPixelColor(i, pixels.Color(0, 0, 0));
		}
	}
}
