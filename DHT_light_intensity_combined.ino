//Κώδικας γραμμένος από τον Γιώργιο Αντωνόπουλο - 8160010
//Libraries
#include <dht.h>
dht DHT;
//Constants
#define DHT22_PIN 2     // DHT 22  (AM2302) - what pin we're connected to

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
const int LED_PIN = 5;
int vote;
int interval_1;
int interval_2;
int interval_3;
int interval_4;
int interval_5;
int interval_6;
 int duty = 170;
int upper = 30;
int lower = -30;
int interval = 10;
String Question = "How would you like to modify the brightness?";
String Answer = "Press 1 for Very Dark , 2 for Dark , 3 for Slightly Dark , 4 for Slightly Bright , 5 for Bright , 6 for Very Bright";
void setup()
{    
    pinMode( LED_PIN, OUTPUT );
    Serial.begin(9600);
}

void loop()
{
    int chk = DHT.read22(DHT22_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    Serial.println(Question);
  Serial.println(Answer);
  vote = Serial.parseInt();
  interval_1= ((duty + lower) + (duty + lower+interval))/2;
  interval_2= ((interval_1) + (interval_1 + interval))/2;
  interval_3= ((interval_2) + (interval_2 + interval))/2;
  interval_4= ((duty + upper) + (duty + interval))/2;
  interval_5= ((interval_4) + (interval_4 + interval))/2;
  interval_6= ((interval_5) + (interval_5 + interval))/2;
  

  if (interval_1<0){
     interval_1=1;
    }
    if (interval_2<0){
     interval_2=1;
    }
    if (interval_3<0){
     interval_3=1;
    }
    if (interval_4>255){
     interval_4=255;
    }
    if (interval_5>255){
     interval_5=255;
    }
    if (interval_6>255){
     interval_6=255;
    }
  
  if (vote==1){
     duty = interval_1;
      }
  else if (vote==2) {
    duty = interval_2;
    }
  else if (vote==3) {
    duty = interval_3;
    }
  else if (vote==4) {
    duty = interval_4;
    }
    
  else if (vote==5){
    duty = interval_5;
    }
  else if (vote==6){
    duty = interval_6;
    }
    analogWrite( LED_PIN, duty );
    delay(2000); //Delay 2 sec.
}
