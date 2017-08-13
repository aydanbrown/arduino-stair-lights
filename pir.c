#include <stdio.h>
#include <stdint.h>

#define PIR_PIN 8

uint_8 pir_status = 0;

int pir_get_status()
{
	return pir_status;
}

int pir_check()
{
	return pir_status = digitalRead(PIR_PIN);
}
