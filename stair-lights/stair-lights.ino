#include "lights.h"

int main(void)
{
	led_start();

	while(1)
	{
		led_update();
	}
}
