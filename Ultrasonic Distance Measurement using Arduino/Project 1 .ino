#define echo 9
#define trig 10

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 Serial.begin(9600);
}

void loop() {

  // trigger on producing ultra sound
  digitalWrite(trig,LOW); //trig is off
  delayMicroseconds(2);
  digitalWrite(trig,HIGH); //trig is on for 10 Ms
  delayMicroseconds(10);
  //sound receiving
  float t ;
  t=pulseIn(echo, HIGH);
  // to recieve the  transmitted signal(created in 15& 16 no line ) use pulseIn
 //d=vt//d=2s//d=0.034*t/2
 float d=0.034*t/2;
 Serial.print("distace:");
 Serial.println(d);
 delay(100);
/*mapping
 int x;
 x=map(0,20,0,100); //(0,20)--> set the range , (0,100)--> percentage range 
 Serial.println(x);*/
}
