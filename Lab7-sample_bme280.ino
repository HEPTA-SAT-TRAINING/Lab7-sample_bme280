#include "src/HeptaSat.h"
#include "src/drv/bme280_bosch.h"

HeptaCdh cdh;
HeptaEps eps;
Bme280 bme;

void setup() {
  cdh.begin();
  eps.init();
  eps.switch_3V3_on();

  if (!bme.begin()) {
    cdh.println("BME280 init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.println("BME280 ready (Wire1 GP6/GP7)");
}

void loop() {
  float temp_c = 0.0f;
  float hum_pct = 0.0f;
  float press_hpa = 0.0f;

  if (bme.read(&temp_c, &hum_pct, &press_hpa)) {
    cdh.printf("Temperature: %.2f [deg C]\r\n", temp_c);
    cdh.printf("Humidity: %.2f [%%]\r\n", hum_pct);
    cdh.printf("Pressure: %.2f [hPa]\r\n", press_hpa);
  } else {
    cdh.println("BME280 read failed");
  }

  delay(1000);
}
