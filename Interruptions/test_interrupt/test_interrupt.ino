int n = 0;
volatile byte state = LOW;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), onEvent, RISING);
}

void loop() {
}

void onEvent() {
  if (n==20){
    digitalWrite(8, state);
    n = 0;
    state = !state;
  }
  n = n + 1;
  
}
