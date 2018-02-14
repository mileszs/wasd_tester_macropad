/*
 * This project is based on another person's basically identical project here:
 * https://imgur.com/r/MechanicalKeyboards/2B0Zt
 *
 * The code is based on their code, as well. It's here: https://pastebin.com/gLEab4wA
 *
 * I did make modifications. If it's not where you found this, you can find the updated
 * code here: [tbd]
 */

#include <Bounce2.h>
#include <Keyboard.h>

Bounce greens = Bounce(2, 10);
Bounce clears = Bounce(3, 10);
Bounce reds   = Bounce(4, 10);
Bounce blacks = Bounce(5, 10);
Bounce browns = Bounce(6, 10);
Bounce blues  = Bounce(7, 10);


void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
}

void loop() {
  updateAllButtons();

  if (greens.fell()) {
    windowLeft();
  }

  if (clears.fell()) {
    windowPreviousMonitor();
  }

  if (reds.fell()) {
    windowFullScreen();
  }

  if (blacks.fell()) {
    windowCenter();
  }

  if (browns.fell()) {
    windowNextMonitor();
  }

  if (blues.fell()) {
    windowRight();
  }
}

void updateAllButtons() {
  greens.update();
  clears.update();
  reds.update();
  blacks.update();
  browns.update();
  blues.update();
}

// The following collection of functions use SizeUp keyboard shortcuts
// to move windows around my screen(s). More here: http://www.irradiatedsoftware.com/sizeup/
void windowLeft() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
}

void windowPreviousMonitor() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
}

void windowFullScreen() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('m');
  Keyboard.releaseAll();
}

void windowCenter() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('c');
  Keyboard.releaseAll();
}

void windowNextMonitor() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_RIGHT_ARROW);
  Keyboard.releaseAll();
}

void windowRight() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_RIGHT_ARROW);
  Keyboard.releaseAll();
}
