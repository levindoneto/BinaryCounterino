const int ledPin[] = {8, 9, 10};
const int aumenta = 3;
const int diminui = 2;
int cont = 0;
int aumentaS = 0;
int diminuiS = 0;

void setup()
{
  for(int i=0; i<3; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
  
    pinMode(aumenta, INPUT);
    pinMode(diminui, INPUT);

    Serial.begin(9600);  
}

void loop() {
    aumentaS = digitalRead(aumenta);
    diminuiS = digitalRead(diminui);
     
    if (aumentaS == HIGH){
     cont++;
     delay (1000);
    }
    if (diminuiS == HIGH){
     cont--;
     delay (1000);
    }
    Serial.println(cont);
    if (cont % 2 == 1){
     digitalWrite (ledPin[2], HIGH);
    }
    else digitalWrite (ledPin[2], LOW);
    
    if (cont > 3){
      digitalWrite (ledPin[0], HIGH);
    }
    else digitalWrite (ledPin[0], LOW);
    
    if (cont == 2 || cont == 3 || cont == 6 || cont == 7){
      digitalWrite (ledPin[1], HIGH);
    }
    else digitalWrite (ledPin [1], LOW);
    
    if ( cont < 0) cont = 0;
    if ( cont > 7) cont = 7;
    
}
