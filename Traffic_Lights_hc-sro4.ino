#define trigPin 7
#define echoPin 6

void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(10, OUTPUT);// wyjście dla diody R
  pinMode(9, OUTPUT);// wyjście dla diody Y
  pinMode(8, OUTPUT);// wyjście dla diody G
}



void loop() 
{ 
  Serial.print(zmierzOdleglosc());
  Serial.println(" cm");

  zakresRED (0, 25);
  zakresYe (25, 40);
    zakresG (41, 80);
  
  
  delay(500);
  

}

int zmierzOdleglosc()
{
  long czas, dystans;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;

  return dystans;
}

void zakresRED(int a, int b)
{
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
    digitalWrite(10, HIGH);//wlacz diode
  }else {
    digitalWrite(10, LOW);// wylacz diode
  }}

  void zakresYe(int a, int b)
{
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
    digitalWrite(9, HIGH);//wlacz diode
  }else {
    digitalWrite(9, LOW);// wylacz diode
  }}

  void zakresG(int a, int b)
{
  int jakDaleko = zmierzOdleglosc();
  if ((jakDaleko > a) && (jakDaleko < b)) {
    digitalWrite(8, HIGH);//wlacz diode
  }else {
    digitalWrite(8, LOW);// wylacz diode
  }
}
