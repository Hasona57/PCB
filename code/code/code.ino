int BUT1 = 26;
int BUT2 = 27;
int BUT3 = 28;
int BUT4 = 29;

int LED1 = 6;
int LED2 = 7;
int LED3 = 0;
int LED4 = 1;

unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long t3 = 0;
bool h3 = false;

unsigned long t4 = 0;
int c4 = 0;

void setup() {
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);
  pinMode(BUT4, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (digitalRead(BUT1) == LOW) {
    t1 = now;
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == LOW) {
    t2 = now;
  }

  if (t2 - t1 <= 2000 && t2 != 0 && t1 != 0) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(BUT3) == LOW) {
    if (!h3) {
      t3 = now;
      h3 = true;
    } else if (now - t3 >= 800) {
      digitalWrite(LED3, HIGH);
    }
  } else {
    h3 = false;
    digitalWrite(LED3, LOW);
  }

  if (digitalRead(BUT4) == LOW) {
    if (now - t4 < 400) {
      c4++;
    } else {
      c4 = 1;
    }
    t4 = now;
    delay(200);
  }

  if (c4 == 2) {
    digitalWrite(LED4, HIGH);
    c4 = 0;
  } else {
    digitalWrite(LED4, LOW);
  }
}