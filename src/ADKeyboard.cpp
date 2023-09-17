/*
  ADKeyboard.cpp

  Copyright (c) 2023, Warp Speed Computers Ltd

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "ADKeyboard.h"

unsigned ADKeyboardState(int pin)
{
  ADKeyboard keyboard(pin);
  return keyboard.pressed();
}

/**
 * @brief Constructor sets the pin to read from
 * 
 * @param pin
 */
ADKeyboard::ADKeyboard(int pin)
{
  ADKeyboard::setPin(pin);
}

/**
 * @brief Sets the pin to read from
 * 
 * @param pin
 */
void ADKeyboard::setPin(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
}

/**
 * @brief Get the btn that was pressed
 * 
 * @return unsigned 
 */
unsigned ADKeyboard::pressed()
{
  int val = analogRead(_pin);

  // SW1 ~ 0
  // SW2 ~ 146
  // SW3 ~ 307
  // SW4 ~ 494
  // SW5 ~ 787
  // Nothing pressed ~ 1023

  if ( val < 73 )
    return 1;
  if ( val < 226 )
    return 2;
  if ( val < 400 )
    return 3;
  if ( val < 640 )
    return 4;
  if ( val < 905 )
    return 5;

  return 0;
}

/**
 * @brief Was the specified btn pressed
 * 
 * @param btn 
 * @return true 
 * @return false 
 */
bool ADKeyboard::pressed(unsigned btn)
{
  return btn == ADKeyboard::pressed();
}

