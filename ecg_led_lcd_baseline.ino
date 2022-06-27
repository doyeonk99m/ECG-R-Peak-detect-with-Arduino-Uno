#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);


int ledPin =12;
int analoginput = 0;
int Sensor_pin = A0;
float EMA_a = 0.3;
int EMA_S = 0;
int highpass = 0;
int R_peak = 0;
int measuring = 0;
double heartrate = 0;
float timing[100];
int sec = 0;

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
 
  
  pinMode(ledPin,INPUT);
  Serial.begin(9600);
  EMA_S = analogRead(Sensor_pin);
}

void loop()
{
  // put your main code here, to run repeatedly:
  analoginput = analogRead(Sensor_pin);

  EMA_S = (EMA_a*analoginput) + ((1-EMA_a)*EMA_S);
  highpass = analoginput - EMA_S;
  
  Serial.println(highpass);
  
  if (highpass < -5)
  {
    digitalWrite(ledPin, HIGH);
    R_peak = 1;
  }

  else
  {
    digitalWrite(ledPin, LOW);
  }
  
  if ((R_peak == 1)&&(highpass >-5))
  {
    R_peak = 0;
    measuring += 1;
  }

  sec = 1000*millis();
  
  heartrate = (measuring * 60) / sec;
  
  lcd.setCursor(0,0);
  lcd.print("Heart rate is");
  lcd.setCursor(0,1);
 
  lcd.print(heartrate);
  
  lcd.setCursor(10,1);
  lcd.print("bpm");

  /*if(millis() < 60000) 
  {
    
  lcd.setCursor(0,0);
  lcd.print("measuring ...");
  lcd.setCursor(10,0);
  
  }

  lcd.setCursor(0,1);
  lcd.print(measuring);

  
 if(millis() == 60000)
   { 
    lcd.setCursor(0,0);
    lcd.clear();
   }
  
  if(millis() > 60000)
  
  {
    
    lcd.setCursor(0,0);
    lcd.print("Heartrate is ");
    
    lcd.setCursor(0,1);
    lcd.print(heartrate);
    
    lcd.setCursor(6,1);
    lcd.print("bpm ");
    
  }*/
  
}
