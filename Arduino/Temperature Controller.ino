//Temperature Sensor Control limit
//Turn red led if hotter than upper limit
//Blue light if colder than lower limit
//Green light within limit
//LED attached digitally as array
//Analog sensor

int sensorPin = 0; 

//the analog pin the TMP36's Vout (sense) pin is connected to   
//the resolution is 10 mV / degree centigrade with a
//500 mV offset to allow for negative temperatures
/*
* setup() - this function runs once when you turn your Arduino on
* We initialize the serial connection with the computer
*/

void setup() {
  //comments behind the slashes to set up variables
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
}

void loop() 
{
  //getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);      // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = reading * 3.3;
  voltage /= 1024.0;
  Serial.print(voltage); Serial.println(" volts");         // print out the voltage
  float temperatureC = (voltage - 0.5) * 100 ;
  Serial.print(temperatureC); Serial.println(" degrees C"); // now print out the temperature
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;   //converting from 10 mv per degree wit 500 mV offset
  Serial.print(temperatureF); Serial.println(" degrees F"); // 
  float control=temperatureF;
  if (temperatureF<65)  {
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    }
    if (temperatureF>=65 && temperatureF<=75) {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    }
    if (temperatureF>75) {
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    }
  delay(5000); //waiting a second
}
