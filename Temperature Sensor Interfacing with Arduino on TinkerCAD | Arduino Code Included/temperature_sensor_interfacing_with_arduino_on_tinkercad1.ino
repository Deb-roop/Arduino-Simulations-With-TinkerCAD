void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);//set temp sensor as input
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 float anlog_reading=analogRead(A0);
 Serial.print("Analog Reading:");//read analog reading
 Serial.println(anlog_reading);

//converting analog reading to voltage
float Voltage=anlog_reading*5/1023;
//we divide by 1023 as the analog reading from the data pin is betn 0 and 1024
//into 5 because 5 volts;
 Serial.print("Voltage Reading:");//display voltage 
 Serial.println(Voltage);

//reading Celsius;
///converting from 10mV per degree with 0.5V offset 
float temp_celsius = 100 * (Voltage-0.5);
Serial.println("Celsius reading:"+String(temp_celsius)+("C"));
float temp_far=(temp_celsius*9/5)+32;
Serial.println("Fahrenheit reading:"+String(temp_far)+("F\n"));
delay(3000);// give a delay of 3 secs before repeating the loop


}
