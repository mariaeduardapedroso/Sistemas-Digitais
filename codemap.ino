// CODIGO CONVERSOR A/D
//
void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(250000);
}

int transmitido;
int convertido;
int leitura;
int conversao4bits;
int bits[3];

void loop()
{
  //leitura analogica do pino de entrada A0
    leitura = analogRead(A0);
    Serial.print("Valor analogico lido:");
    Serial.println(leitura, DEC);
    Serial.print("Valor voltagem lido:");
    Serial.println(leitura*5/1023);
    
    //fazer a conversão dos valores em 16 faixas 0-15
    conversao4bits = map(leitura, 0, 1023, 0, 255);

    
      //conversão de binario para decimal
      Serial.print("Valor digital convertido com faixa de 255 bits:");
      Serial.println(conversao4bits, DEC);
      Serial.print("Valor digital convertido com faixa de 255 bits:");
      Serial.println(conversao4bits*5/255);
      digitalWrite(10,conversao4bits);
      
      delay(5);
}
