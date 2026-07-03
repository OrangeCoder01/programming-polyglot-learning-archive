# include <DHT.h>
# include <LiquidCrystal.h>

#define DHT_pin 9
#define DHT_Type DHT11
#define Baud_Rate 9600

DHT Temp_Hum_S(DHT_pin, DHT_Type);
LiquidCrystal LC(13,12,2,3,4,5);


void setup()
{
 Serial.begin(Baud_Rate);
 Temp_Hum_S.begin();
 LC.begin(16,2);
}

void loop()
{
 float Humidity = Temp_Hum_S.readHumidity();
 float Temperature = Temp_Hum_S.readTemperature();

 LC.clear();
 LC.setCursor(0,0);

 if(isnan(Humidity) || isnan(Temperature))
  {
    Serial.println("Sensor Reading Failed!");
    LC.print("Can't Read");
    return;
  }

  LC.print("Temperature: "); LC.print(Temperature); LC.print(" ⁰C");
  LC.setCursor(0, 1);
  LC.print("Humidity: "); LC.print(Humidity); LC.print(" %");

  Serial.print("Temperature: "); Serial.print(Temperature); Serial.println(" C");

  Serial.print("Humidity: "); Serial.print(Humidity); Serial.println(" %");

  delay(2000);
  
}
