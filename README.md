# Lab7-sample_bme280

HEPTA-SAT training sample: **Bosch BME280** environmental sensor (temperature, humidity, pressure).

## Sensor Specifications

| Item | Value |
|------|-------|
| Part | **Bosch BME280** |
| Interface | I2C (address `0x76` or `0x77`) |
| Supply | 3.3 V (payload power) |
| Temperature range | approx. −40 to +85 °C (datasheet) |
| Humidity range | 0 to 100 %RH |
| Pressure range | 300 to 1100 hPa |
| Chip ID | `0x60` |

## Wiring (HEPTA-SAT)

| BME280 | HEPTA-SAT |
|--------|-----------|
| SDA | **GP6** |
| SCL | **GP7** |
| VCC | 3.3 V payload (`eps.switch_3V3_on()`) |
| GND | GND |

> The onboard BNO055 uses the default I2C bus (`Wire`). The BME280 uses **Wire1** on **GP6/GP7**.

## Build and Upload

1. Open `Lab7-sample_bme280.ino` in the Arduino IDE
2. Board: **Raspberry Pi Pico** (HEPTA-SAT build settings)
3. Check out the `src/` submodule (`git submodule update --init`)
4. Compile and upload to HEPTA-SAT
5. Open the USB serial monitor at **9600 baud**

## Example Serial Output

```
BME280 ready (Wire1 GP6/GP7)
Temperature: 24.35 [deg C]
Humidity: 45.20 [%]
Pressure: 1013.25 [hPa]
Temperature: 24.36 [deg C]
Humidity: 45.18 [%]
Pressure: 1013.24 [hPa]
```

## Driver

- `src/drv/bme280_bosch.h` / `.cpp`
- Details: `src/docs/drivers/bme280-bosch.md`
