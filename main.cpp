/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
class secLeds {
private:
  int numLeds;
  int delay;

public:
  void numeroLeds(int nleds) {
    if ((nleds < 1) && (nleds > 4)) {
      nleds = 4;
    }
    numLeds = nleds - 1;
  }
  void tiemDelay(int ndelay) {
    if ((ndelay < 1)) {
      ndelay = 1;
    }
    delay = ndelay;
  }
  void secuenciaLeds(int repSecuencia, int sentido) {
    BusOut leds(PA_0, PA_1, PA_4, PB_0);
    for (int j = 0; j <= repSecuencia - 1; j++) {
      if (sentido == 0) {
        for (int i = numLeds; i >= 0; i--) {
          leds = pow(2, i);
          ThisThread::sleep_for(std::chrono::milliseconds(delay));
        }
        continue;
      }
      for (int i = 0; i <= numLeds; i++) {
        leds = pow(2, i);
        ThisThread::sleep_for(std::chrono::milliseconds(delay));
      }
    }
  }
};

int main() {

  secLeds secRapida;

  while (1) {
    secRapida.numeroLeds(4);
    secRapida.tiemDelay(500);
    secRapida.secuenciaLeds(5, 0); // 5 corriminetos de derecha a izquierda
    secRapida.secuenciaLeds(5, 1); // 5 corriminetos de izquierda a derecha
  }
}