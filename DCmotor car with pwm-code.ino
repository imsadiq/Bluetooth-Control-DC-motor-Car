// atoi function used to convert str to int
int m1a = 13;
int m1b = 12;
int m2a = 8;
int m2b = 10;
int en1 = 11;
int en2 = 9;
uint32_t resultant;
char val[10] = {0} ;

void setup()
{

  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);

  Serial.begin(9600);

  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);

}
char index = 0;
void loop()
{
  if (Serial.available())
  {
    char temp = Serial.read();
    if (temp == 0x0D ) 
    {
      val[index] = 0;
      resultant = atoi(val);

      Serial.print("resultant = ");
      Serial.println(resultant, DEC);
      index = 0;
      memset(val, 0, sizeof(val));
    }
    else
    {
      Serial.println(temp, HEX);
      //temp = temp - 48;
      val[index++] = temp;
    }
  }

  if (resultant <= 255 && resultant >= 1)
  {
    analogWrite(en1, resultant);
    analogWrite(en2, resultant);
  }
  else
  {
    analogWrite(en1, 0);
    analogWrite(en2, 0);
  }
}
