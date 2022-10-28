#define ledPin 11

bool state = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  cli();
  // EICRA для управления внешними прерываниями
  EICRA = 0;
  // ISC11 и ISC10 управляют событиями для генерации прерывания
  EICRA = EICRA | (1 << ISC11);
  EICRA = EICRA | (1 << ISC10);
  // EIMSK для разрешения прерываний
  // INT1 разрешает прерывание, если записать 1
  EIMSK = EIMSK | (1 << INT1);
  sei();
}

void loop() {
  digitalWrite(ledPin, state);
}

ISR(INT1_vect){ 
  state = !state;
}
