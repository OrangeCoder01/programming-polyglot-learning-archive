const int input_signal_pin = 18;
const int input_reading_pin = 34;
const int output_reading_pin = 35;


void setup()
{
  pinMode(input_signal_pin  , OUTPUT);
  pinMode(input_reading_pin , INPUT );
  pinMode(output_reading_pin, INPUT) ;
  Serial.begin(115200);
}


void op_amp_testing()
{
  tone(input_signal_pin, 1000);
  float vin = 3.3*(analogRead(input_reading_pin))/4095.0;
  float vout = 3.3*(analogRead(output_reading_pin))/4095.0;
  float gain = vout/vin;

  Serial.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
  Serial.print("Vin: ");Serial.println(vin);
  Serial.print("Vout: ");Serial.println(vout);
  Serial.print("Gain: ");Serial.println(gain);
  Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

}

void loop()
{
  op_amp_testing();
  delay(200);
}