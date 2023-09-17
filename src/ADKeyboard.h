/*
  ADKeyboard.h

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

#ifndef ADKEYBOARD_h
#define ADKEYBOARD_h

#include "Arduino.h"

class ADKeyboard
{

public:
  ADKeyboard( int pin );
  void setPin(int pin);
  unsigned pressed();
  bool pressed( unsigned btn );

private:
  int _pin;

};

#endif

