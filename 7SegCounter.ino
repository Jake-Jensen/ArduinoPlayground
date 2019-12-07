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

// The following functions all light up a specific number when called.
// Be aware, SelectDigit(x) must be called first to specify the digit place to display.
// E*** refers to the extra 7 segment 1 digit display
// ***DEC refers to the 7 sgement 4 digit display, but the number also has the decimal pin lit.
void Zero() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void One() {
  digitalWrite(TOP, LOW);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Two() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, LOW);
  digitalWrite(DP, LOW);
}

void Three() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Four() {
  digitalWrite(TOP, LOW);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Five() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, LOW);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Six() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, LOW);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Seven() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Eight() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Nine() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, LOW);
}

void Deci()
{
  digitalWrite(TOP, LOW);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, LOW);
  digitalWrite(BL, LOW);
  digitalWrite(BR, LOW);
  digitalWrite(DP, HIGH);
}

void Off()
{
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, LOW);
  digitalWrite(EDP, LOW);
}

// External display
void EZero() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, HIGH);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void EOne() {
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void ETwo() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, HIGH);
  digitalWrite(EBR, LOW);
  digitalWrite(EDP, LOW);
}

void EThree() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void EFour() {
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void EFive() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void ESix() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, HIGH);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void ESeven() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void EEight() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, HIGH);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void ENine() {
  digitalWrite(ETOP, HIGH);
  digitalWrite(EMID, HIGH);
  digitalWrite(EBOT, HIGH);
  digitalWrite(ETL, HIGH);
  digitalWrite(ETR, HIGH);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, HIGH);
  digitalWrite(EDP, LOW);
}

void EDeci()
{
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, LOW);
  digitalWrite(EDP, HIGH);
}

void EOff()
{
  digitalWrite(ETOP, LOW);
  digitalWrite(EMID, LOW);
  digitalWrite(EBOT, LOW);
  digitalWrite(ETL, LOW);
  digitalWrite(ETR, LOW);
  digitalWrite(EBL, LOW);
  digitalWrite(EBR, LOW);
  digitalWrite(EDP, LOW);
}

void ZeroDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void OneDEC() {
  digitalWrite(TOP, LOW);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void TwoDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, LOW);
  digitalWrite(DP, HIGH);
}

void ThreeDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void FourDEC() {
  digitalWrite(TOP, LOW);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void FiveDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, LOW);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void SixDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, LOW);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void SevenDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, LOW);
  digitalWrite(BOT, LOW);
  digitalWrite(TL, LOW);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void EightDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

void NineDEC() {
  digitalWrite(TOP, HIGH);
  digitalWrite(MID, HIGH);
  digitalWrite(BOT, HIGH);
  digitalWrite(TL, HIGH);
  digitalWrite(TR, HIGH);
  digitalWrite(BL, LOW);
  digitalWrite(BR, HIGH);
  digitalWrite(DP, HIGH);
}

// Debug testing, ignore.
bool BreakTheLoop(bool Fuck) {
  if (Fuck == true) {
    return true;
  } else {
    return false;
  }
}

// The delay time value, unused.
int DelayTime = 150;

// The values being used. Redundant, as the values themselves could be used.
int CurrentValue;
int CurrentOne;
int CurrentTwo;
int CurrentThree;
int CurrentFour;
int CurrentExternal;

// The amount of time to hold that value on the display before moving to the next. Keep below 4 to avoid flickering.
int HoldTime = 3;

// The workhorse of the program.
// Takes the input from HoldValue(), splits in into switch statements, and displays the corresponding
// digit in order from right to left, then extra display.
int SplitDisplay(int Value1, int Value2, int Value3, int Value4, int External)
{
  Serial.println("Broken!");
  DigitSelect(0);
  CurrentFour = Value4;
  CurrentThree = Value3;
  CurrentTwo = Value2;
  CurrentOne = Value1;
  CurrentExternal = External;
  delay(HoldTime);
  DigitSelect(1);
  switch (CurrentOne) {
    case 0:
      Zero();
      break;
    case 1:
      One();
      break;
    case 2:
      Two();
      break;
    case 3:
      Three();
      break;
    case 4:
      Four();
      break;
    case 5:
      Five();
      break;
    case 6:
      Six();
      break;
    case 7:
      Seven();
      break;
    case 8:
      Eight();
      break;
    case 9:
      Nine();
      break;
  }
  delay(HoldTime);
  DigitSelect(2);
  switch (CurrentTwo) {
    case 0:
      Zero();
      break;
    case 1:
      One();
      break;
    case 2:
      Two();
      break;
    case 3:
      Three();
      break;
    case 4:
      Four();
      break;
    case 5:
      Five();
      break;
    case 6:
      Six();
      break;
    case 7:
      Seven();
      break;
    case 8:
      Eight();
      break;
    case 9:
      Nine();
      break;
  }
  delay(HoldTime);
  DigitSelect(3);
  switch (CurrentThree) {
    case 0:
      Zero();
      break;
    case 1:
      One();
      break;
    case 2:
      Two();
      break;
    case 3:
      Three();
      break;
    case 4:
      Four();
      break;
    case 5:
      Five();
      break;
    case 6:
      Six();
      break;
    case 7:
      Seven();
      break;
    case 8:
      Eight();
      break;
    case 9:
      Nine();
      break;
  }
  delay(HoldTime);
  DigitSelect(4);
  switch (CurrentFour) {
    case 0:
      ZeroDEC();
      break;
    case 1:
      OneDEC();
      break;
    case 2:
      TwoDEC();
      break;
    case 3:
      ThreeDEC();
      break;
    case 4:
      FourDEC();
      break;
    case 5:
      FiveDEC();
      break;
    case 6:
      SixDEC();
      break;
    case 7:
      SevenDEC();
      break;
    case 8:
      EightDEC();
      break;
    case 9:
      NineDEC();
      break;

      // Serial.println(CurrentOne);
      // Serial.println(CurrentTwo);
      // Serial.println(CurrentThree);
      // Serial.println(CurrentFour);
  }
  delay(HoldTime);
  switch (CurrentExternal) {
        case 0:
      EZero();
      break;
    case 1:
      EOne();
      break;
    case 2:
      ETwo();
      break;
    case 3:
      EThree();
      break;
    case 4:
      EFour();
      break;
    case 5:
      EFive();
      break;
    case 6:
      ESix();
      break;
    case 7:
      ESeven();
      break;
    case 8:
      EEight();
      break;
    case 9:
      ENine();
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
