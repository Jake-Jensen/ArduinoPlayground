// Jake Jensen, 2019
// 7 segement 4 digit + 7 segment 1 digit + LED code
// Notes: Code is messy and mechanical due to 0 optimization. Next versions will be cleaner and shorter.

// These defines correspond to the pins on the Mega
// Identifier before it corresponds to the segment being lit
// Notes; DP/ EDP refer to the decimal segment
// E** refers to the 7 segment 1 digit display
// For instance, ETL is extra, top left segment
// LED refers to the LED.
// D* refers to the digit place, on the 7 seg 4 dig, it looks like this:
// [D1][D2][D3][D4]
// Total schematic should look like
// [D1][D2][D3][D4] [E]
#define D1 52
#define TOP 50
#define TL 48
#define D2 46
#define D3 44
#define TR 42
#define BL 40
#define BOT 38
#define DP 36
#define BR 34
#define MID 32
#define D4 30
#define EMID 28
#define ETL 26
#define ETOP 24
#define ETR 22
#define EBL 35
#define EBOT 33
#define EBR 31
#define EDP 47
#define LED 43

bool ReadyToBreakTheLoop = true;

void setup() {
  // Set all pins to output, minus the ones we aren't using.
  for (int i = 22; i < 52; i++) {
    if (i == 23 || i == 25 || i == 27 || i == 29 || i == 39 || i == 41 || i == 43 || i == 45 || i == 49 || i == 51) {

    } else {
      pinMode(i, OUTPUT);
    }
    pinMode(D1, OUTPUT);
    pinMode(LED, OUTPUT);
    // Debug serial
    // Serial.begin(9600);
  }
}

// Selects which digit to display the character on
void DigitSelect(int WhichPin) {
  if (WhichPin == 1) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  if (WhichPin == 2) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  if (WhichPin == 3) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  if (WhichPin == 4) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }

  if (WhichPin < 1 || WhichPin > 4) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
}

// Turns the LED on.
void LED_On()
{
  digitalWrite(LED, HIGH);
}

// Turns the LEd off.
void LED_Off()
{
  digitalWrite(LED, LOW);
}

// SelectDigit: The digit to display
// UseDecimal: Show the decimal point
// UseExternal: Show digit on external display
void SelectDigit(int Digit, bool UseDecimal = false, bool UseExternal = false)
{
  // Deactivate the display to remove ghosting
  digitalWrite(TOP, LOW);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, LOW);
  digitalWrite(BL, LOW);
  digitalWrite(BR, LOW);
  digitalWrite(DP, LOW);
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, LOW);
  digitalWrite(EDP, LOW);
  // Break the result and build the digit.
  // Comparison check time is negligable, so no need to further optimize as time of execution never
  // exceeds 4 milliseconds.
  if (Digit == 0 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BL, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 1 && UseExternal != true) {
    digitalWrite(TR, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 2 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BL, HIGH);
  }
  if (Digit == 3 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 4 && UseExternal != true) {
    digitalWrite(MID, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 5 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 6 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(BL, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 7 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 8 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BL, HIGH);
    digitalWrite(BR, HIGH);
  }
  if (Digit == 9 && UseExternal != true) {
    digitalWrite(TOP, HIGH);
    digitalWrite(MID, HIGH);
    digitalWrite(BOT, HIGH);
    digitalWrite(TL, HIGH);
    digitalWrite(TR, HIGH);
    digitalWrite(BR, HIGH);
  }

  // External
  if (Digit == 0 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBL, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 1 && UseExternal == true) {
    digitalWrite(ETR, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 2 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBL, HIGH);
  }
  if (Digit == 3 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 4 && UseExternal == true) {
    digitalWrite(EMID, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 5 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 6 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(EBL, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 7 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 8 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBL, HIGH);
    digitalWrite(EBR, HIGH);
  }
  if (Digit == 9 && UseExternal == true) {
    digitalWrite(ETOP, HIGH);
    digitalWrite(EMID, HIGH);
    digitalWrite(EBOT, HIGH);
    digitalWrite(ETL, HIGH);
    digitalWrite(ETR, HIGH);
    digitalWrite(EBR, HIGH);
  }

  // Decimal point
  if (UseDecimal == true && UseExternal == true) {
    digitalWrite(EDP, HIGH);
  }
  if (UseDecimal == true && UseExternal != true) {
    digitalWrite(DP, HIGH);
  }
}

// The amount of time to hold that value on the display before moving to the next. Keep below 4 to avoid flickering.
int HoldTime = 3;

// The workhorse of the program.
// Takes the input from HoldValue(), splits in into switch statements, and displays the corresponding
// digit in order from right to left, then extra display.
int SplitDisplay(int Value1, int Value2, int Value3, int Value4, int External)
{
  Serial.println("Broken!");
  DigitSelect(0);
  delay(HoldTime);
  DigitSelect(1);
  switch (Value1) {
    case 0:
      SelectDigit(0);
      break;
    case 1:
      SelectDigit(1);
      break;
    case 2:
      SelectDigit(2);
      break;
    case 3:
      SelectDigit(3);
      break;
    case 4:
      SelectDigit(4);
      break;
    case 5:
      SelectDigit(5);
      break;
    case 6:
      SelectDigit(6);
      break;
    case 7:
      SelectDigit(7);
      break;
    case 8:
      SelectDigit(8);
      break;
    case 9:
      SelectDigit(9);
      break;
  }
  delay(HoldTime);
  DigitSelect(2);
  switch (Value2) {
    case 0:
      SelectDigit(0);
      break;
    case 1:
      SelectDigit(1);
      break;
    case 2:
      SelectDigit(2);
      break;
    case 3:
      SelectDigit(3);
      break;
    case 4:
      SelectDigit(4);
      break;
    case 5:
      SelectDigit(5);
      break;
    case 6:
      SelectDigit(6);
      break;
    case 7:
      SelectDigit(7);
      break;
    case 8:
      SelectDigit(8);
      break;
    case 9:
      SelectDigit(9);
      break;
  }
  delay(HoldTime);
  DigitSelect(3);
  switch (Value3) {
    case 0:
      SelectDigit(0);
      break;
    case 1:
      SelectDigit(1);
      break;
    case 2:
      SelectDigit(2);
      break;
    case 3:
      SelectDigit(3);
      break;
    case 4:
      SelectDigit(4);
      break;
    case 5:
      SelectDigit(5);
      break;
    case 6:
      SelectDigit(6);
      break;
    case 7:
      SelectDigit(7);
      break;
    case 8:
      SelectDigit(8);
      break;
    case 9:
      SelectDigit(9);
      break;
  }
  delay(HoldTime);
  DigitSelect(4);
  switch (Value4) {
    case 0:
      SelectDigit(0, true);
      break;
    case 1:
      SelectDigit(1, true);
      break;
    case 2:
      SelectDigit(2, true);
      break;
    case 3:
      SelectDigit(3, true);
      break;
    case 4:
      SelectDigit(4, true);
      break;
    case 5:
      SelectDigit(5, true);
      break;
    case 6:
      SelectDigit(6, true);
      break;
    case 7:
      SelectDigit(7, true);
      break;
    case 8:
      SelectDigit(8, true);
      break;
    case 9:
      SelectDigit(9, true);
      break;
  }
  delay(HoldTime);
  switch (External) {
    case 0:
      SelectDigit(0, false, true);
      break;
    case 1:
      SelectDigit(1, false, true);
      break;
    case 2:
      SelectDigit(2, false, true);
      break;
    case 3:
      SelectDigit(3, false, true);
      break;
    case 4:
      SelectDigit(4, false, true);
      break;
    case 5:
      SelectDigit(5, false, true);
      break;
    case 6:
      SelectDigit(6, false, true);
      break;
    case 7:
      SelectDigit(7, false, true);
      break;
    case 8:
      SelectDigit(8, false, true);
      break;
    case 9:
      SelectDigit(9, false, true);
      break;
  }
  delay(HoldTime);
  return 1;
}


int Val1;
int Val2;
int Val3;
int Val4;
int Val5;

// The second workhorse of the program.
// Calls millis(), splits the values into rank digits
// eg 1234 becomes 1 2 3 4, or in our case, 4 3 2 1
// Then calls the SplitDisplay() function with the values.
// Some variables here are redundant or not used at all.
void HoldValue()
{
  int Counter = 0;
  while (true) {
    // delay(5);
    ReadyToBreakTheLoop = true;
    Val5 = millis() / 100 % 10;
    Val4 = millis() / 1000 % 10;
    Val3 = millis() / 10000 % 10;
    Val2 = millis()  / 100000 % 10;
    Val1 = millis() / 1000000 % 10;
    SplitDisplay(Val1, Val2, Val3, Val4, Val5);

    ReadyToBreakTheLoop = false;
  }
}
// Redundant
double time;

// Turns the LED on, and starts the display.
void loop() {
  LED_On();
  HoldValue();
}
