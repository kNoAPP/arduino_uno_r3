# Arduino Uno R3 Projects

A collection of Arduino Uno R3 projects built with [PlatformIO](https://platformio.org/). Each project lives in its own folder and can be opened, built, and uploaded independently.

## Projects

### P03 – Love-O-Meter
**Folder:** `p03_love_o_meter/`

Reads temperature from a **TMP36** analog sensor and lights up to three LEDs based on how warm it is. Each LED turns on when the temperature crosses a successive 2 °C threshold, giving a visual "heat meter."

| Pin | Component |
|-----|-----------|
| A0  | TMP36 temperature sensor |
| 3   | LED 1 (lowest threshold) |
| 4   | LED 2 (+2 °C) |
| 5   | LED 3 (+4 °C) |

---

### P04 – Color Mixing Lamp
**Folder:** `p04_color_mixing_lamp/`

Uses three **photoresistors** (one per color channel) to mix an RGB LED. The analog readings from the light sensors are mapped to PWM brightness values for the red, green, and blue channels of the LED.

| Pin | Component |
|-----|-----------|
| A0  | Red photoresistor |
| A1  | Green photoresistor |
| A2  | Blue photoresistor |
| 11  | Red LED channel (PWM) |
| 10  | Green LED channel (PWM) |
| 9   | Blue LED channel (PWM) |

---

### P05 – Mood Cue
**Folder:** `p05_mood_cue/`

Maps a **potentiometer** position to a **servo motor** angle (0–179°). Rotate the knob to sweep the servo, creating a physical mood indicator or pointer.

| Pin | Component |
|-----|-----------|
| A0  | Potentiometer |
| 9   | Servo motor (PWM) |

**Library dependency:** [`arduino-libraries/Servo ^1.3.0`](https://github.com/arduino-libraries/Servo)

---

## Requirements

- **Hardware:** Arduino Uno R3
- **IDE / Build tool:** [PlatformIO](https://platformio.org/) (CLI or the VS Code extension)
- **Editor (optional):** VS Code with the [PlatformIO IDE extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) — a multi-root workspace file (`arduino_uno_r3.code-workspace`) is included

## Getting Started

1. **Install PlatformIO** – follow the [official installation guide](https://docs.platformio.org/en/latest/core/installation/index.html).

2. **Open a project folder**, e.g.:
   ```bash
   cd p03_love_o_meter
   ```

3. **Build** the project:
   ```bash
   pio run
   ```

4. **Upload** to the connected Arduino Uno:
   ```bash
   pio run --target upload
   ```

5. **Open the Serial Monitor** (baud rate 9600) to view sensor readings:
   ```bash
   pio device monitor --baud 9600
   ```

> **Tip:** All projects are also available as separate folders in the VS Code workspace. Open `arduino_uno_r3.code-workspace` to work with all three projects at once.

## License

This repository is licensed under the [MIT License](LICENSE). © 2026 Alden Bansemer.
