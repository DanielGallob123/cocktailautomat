<!-- .github/copilot-instructions.md - guidance for AI coding agents -->
# Copilot / AI Agent Instructions (concise)

Purpose: Help an AI agent be immediately productive in this PlatformIO Arduino Simon Game project.

- **Big picture:** This is a small PlatformIO Arduino project that implements a Simon game with physical buttons, LEDs, and a 7-segment score display. The firmware lives in `src/` (primary file: `src/main.cpp`). Hardware mapping and debouncing use constants and the `Bounce2` library.

- **Key files & dirs:**
  - `platformio.ini` — project env (`env:uno`), framework `arduino`, and `lib_deps` (Bounce2).
  - `src/main.cpp` — main firmware; pin constants, `setup()`, and `loop()` are here.
  - `lib/` — additional libraries (if present).
  - `README.md` — build and simulation instructions.
  - `wokwi.toml` — simulator firmware/elf paths (update if changing build target).

- **Build & simulate:**
  - Build locally with PlatformIO: run `pio run` from the project root.
  - Simulate in VS Code with Wokwi: install the Wokwi extension and use `F1` → `Wokwi: Start Simulator`.

- **Project-specific patterns & conventions:**
  - Pins and LEDs are defined as top-level `const int` values in `src/main.cpp` (e.g. `BTN_YLW`, `BTN_BLU`, `LED_PNK`, `LED_GRN`).
  - Debouncing uses `Bounce2::Button`; buttons are attached with `attach(pin, INPUT_PULLUP)` and configured as active-low with `setPressedState(LOW)`.
  - Serial debugging uses `Serial.begin(9600)` and `Serial.println(...)` for simple trace output.
  - Use `digitalWrite()` for LEDs and `delay()` sparingly — follow current code style (simple, imperative)

- **Common edits and examples:**
  - Add a new button:
    - Add a `const int` for the pin at the top of `src/main.cpp`.
    - Create a `Bounce2::Button` instance, `attach(pin, INPUT_PULLUP)`, and `setPressedState(LOW)` in `setup()`.
    - Call `.update()` in `loop()` and check `.pressed()` to react.
  - Change debouncing behavior: prefer reuse of `Bounce2` API rather than implementing manual debounce.

- **Dependencies & env guidance:**
  - Do not remove or rename `env:uno` in `platformio.ini` unless you also update `wokwi.toml` and verify build paths.
  - External deps are declared in `platformio.ini` under `lib_deps` (e.g., `thomasfredericks/Bounce2@^2.72`). Add new deps there.

- **Debugging notes:**
  - Use `Serial.println()` at 9600 baud for simple logging; the project expects `Serial.begin(9600)` in `setup()`.
  - When making hardware changes, validate in Wokwi before pushing — the simulator reads `wokwi.toml` firmware paths.

- **What not to change without verification:**
  - Altering pin assignments or `INPUT_PULLUP` semantics — cross-check with README/hardware wiring.
  - The PlatformIO build env or board name (`uno`) — this affects `wokwi.toml` and build output paths.

- **Pull request / commit hints for AI-generated changes:**
  - Keep changes small and focused (one logical change per PR).
  - Reference the affected pins or files in the commit message (e.g., "Add blue button handler in `src/main.cpp`").

If anything here is unclear or you'd like more examples (unit-testing approach, adding CI, or refactoring suggestions), tell me which area to expand.
