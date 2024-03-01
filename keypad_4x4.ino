/* Keypad setup */
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;
byte rowPins[KEYPAD_ROWS] = {5, 4, 3, 2};
byte colPins[KEYPAD_COLS] = {A3, A2, A1, A0};

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup() {

  /* Serial Init for log */
  Serial.begin(115200);

  /* keypad rows as input  */
  for (char r = 0; r < KEYPAD_ROWS; r++)
  {
    pinMode(rowPins[r], INPUT_PULLUP);
    // digitalWrite(rowPins[r], HIGH);
  }

  /* keypad columns as output  */
  for (int c = 0; c < KEYPAD_COLS; c++)
  {
    pinMode(colPins[c], OUTPUT);
    digitalWrite(colPins[c], HIGH);
  }
  Serial.println("key board interface");
}

char get_keypad()
{
  char key = 0;
  for (char c = 0; c < KEYPAD_COLS; c++)
  {
    digitalWrite(colPins[c], LOW);
    for (int r = 0; r < KEYPAD_ROWS; r++)
    {
      if (digitalRead(rowPins[r]) == LOW)
      {
        delay(20);
        while (digitalRead(rowPins[r]) == LOW);
        key = keys[r][c];
      }
    }
    digitalWrite(colPins[c], HIGH);
  }
  return key;
}

void loop() {
  char key = get_keypad();

  if (key != 0)
    Serial.println(key);
}
