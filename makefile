AVRDUDEFLAGS=
#ARDUINODIR:=/Applications/Arduino.marlin.app/Contents/Resources/Java
#ARDUINODIR:=/Applications/Arduino.1.0.5.app/Contents/Resources/Java
ARDUINODIR:=/Applications/Arduino.app/Contents/Java
AVRTOOLSPATH := $(ARDUINODIR)/hardware/tools/avr/bin
#SOURCES := kart.ino
LIBRARIES := NeoPixel
BOARD := uno
#BOARD := a-star32U4
#EXTRA_LIBRARIES = NeoPixel
include ./arduino.mk
