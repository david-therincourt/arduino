
int N;
unsigned long t0;
unsigned long t;


void setup() {
  Serial.begin(9600);
}

void loop() {
  t0 = micros();
  int N = analogRead(A0);
  t = micros()-t0;
  Serial.print(N);
  Serial.print("\t");
  Serial.print(t);
  Serial.println(" µs");
  delay(1000);
}
