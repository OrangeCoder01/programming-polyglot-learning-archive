#include <LiquidCrystal.h>
LiquidCrystal LC(12,11,5,4,3,2);

void setup()
{
  LC.begin(16,2);
  LC.print("Hello,");
  LC.setCursor(0, 1);
  LC.print("Hello World!");
  LC.noCursor();
}

void loop()
{

}
