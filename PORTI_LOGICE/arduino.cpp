// Definirea intrărilor pentru butoane și a ieșirii pentru LED
int A = 1; // Buton 1 (apăsat sau nu)
int B = 0; // Buton 2 (apăsat sau nu)
int LED = 13; // Pinul pentru LED

void setup() {
  pinMode(LED, OUTPUT); // Setăm pinul LED ca ieșire
}

void loop() {
  // Poarta AND: LED aprins doar dacă ambele butoane sunt apăsate
  if (A && B) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }
  
  // Poarta OR: LED aprins dacă cel puțin un buton este apăsat
  if (A || B) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }

  // Poarta XOR: LED aprins dacă butoanele sunt apăsate diferit
  if (A ^ B) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }

  // Poarta NOT: LED aprins dacă primul buton nu este apăsat
  if (!A) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }

  // Poarta NAND: LED aprins dacă nu ambele butoane sunt apăsate
  if (!(A && B)) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }

  // Poarta NOR: LED aprins doar dacă niciunul dintre butoane nu este apăsat
  if (!(A || B)) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }

  // Poarta XNOR: LED aprins dacă butoanele sunt apăsate sau nu sunt apăsate la fel
  if (!(A ^ B)) {
    digitalWrite(LED, HIGH); // Aprinde LED-ul
  } else {
    digitalWrite(LED, LOW); // Stinge LED-ul
  }
}
