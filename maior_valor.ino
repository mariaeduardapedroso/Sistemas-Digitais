// CODIGO CONVERSOR A/D - D/A
#define quantidade_faixas 3
#define porta_saida 10
int convertido;
int leitura;
int conversaofaixabits;
int valorPWM;

void setup()
{
  Serial.begin(250000);
  pinMode(porta_saida, OUTPUT);
}

void loop()
{
  //leitura analogica do pino de entrada A0
  leitura = analogRead(A1);

  Serial.println("--------------------------");
  Serial.print("Valor analogico lido:");
  Serial.println(leitura, DEC);
  Serial.print("Valor tensão lido:");
  Serial.println(float(leitura * 5.0 / 1023), DEC);

  //QUANTIZAÇÃO E CONVERSÃO DE FAIXAS
  conversaofaixabits = 0;
  if (leitura != 0) {
    conversaofaixabits = (quantidade_faixas * leitura) / 1023;
    conversaofaixabits = conversaofaixabits + 1;
    if (conversaofaixabits > quantidade_faixas) {
      conversaofaixabits = quantidade_faixas;
    }
  }


  Serial.print("Valor quantizado com faixa de ");
  Serial.print(quantidade_faixas);
  Serial.print(" bits:");
  Serial.println(conversaofaixabits);

  //CONVERSÃO DIGITAL PARA ANALOGICO PINO PWM
  valorPWM = (255 * conversaofaixabits) / quantidade_faixas;

  Serial.print("Valor digital convertido com faixa de 255 bits:");
  Serial.println(valorPWM, DEC);
  Serial.print("Valor tensão convertido com faixa de 255 bits:");
  Serial.println(float(valorPWM * 5.0 / 255), DEC);

  digitalWrite(porta_saida, conversaofaixabits);

  Serial.print("Erro de conversão:");
  Serial.println(float(valorPWM * 5.0 / 255) - float(leitura * 5.0 / 1023), DEC);

  delay(0.005);
}
