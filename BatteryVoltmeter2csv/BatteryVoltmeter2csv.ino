/* Voltmètre à pile

   Communication par le port série de la valeur mesurée
   valeur envoyé après 1/2s pour stabilisation
   envoie de la valeur 1 seule fois
   remise à 0 dès que les sondes ne mesurent plus de tension
*/

int niv = 0;
int seuilBas = 0;
int seuilHaut = 0;
float Umax = 5.0;
double time0;
double start;

boolean mes1 = false;
boolean plage = true;
boolean envoye = false;
boolean fin = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Voltmetre a pile - COM");
}

void loop() {
  if (not(fin)) {
    // lecture de la tension
    niv = analogRead(A0);
    time0 = millis();
    if (niv > 2) {
      // si la première mesure n'a pas été déjà faite
      if (not(mes1)) {
        // on stocke une date
        start = millis();
        // on crée une plage de tension
        seuilBas = niv - 2;
        seuilHaut = niv + 2;
        mes1 = true;
      } else {
        // si la valeur mesurée est bien dans la plage de tension
        if (seuilBas < niv && niv < seuilHaut) {
          // si la valeur est bien dans la plage et n'a pas encore été envoyée
          if (time0 > start + 500 && not(envoye)) {
            Serial.println(niv / 1024.0 * Umax, 4);
            envoye = true;
          }
        } else {
          //si on sort de la plage on recommence la première mesure
          mes1 = false;
        }
      }
    } else {
      mes1 = false;
      envoye = false;
    }

    if (digitalRead(2) == LOW) {
      fin = true;
      Serial.println("stop");
    }

  }
}
