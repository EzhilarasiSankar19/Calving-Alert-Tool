#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
 int xpin = A3; 
 int ypin = A2;                
 int zpin = A1; 
 int xvalue;
 int yvalue;
 int zvalue;

void setup()
{
    Serial.begin(9600);
    mlx.begin();                           
}


void loop()
{
  xvalue = analogRead(xpin);                               
  int x = map(xvalue, 257, 389, -100, 100);               
  float xg = (float)x/(-100.00);                          
  Serial.print(xg);                                       
  //Serial.print("g   ");                                  
   
  yvalue = analogRead(ypin);
  int y = map(yvalue, 257, 389, -100, 100);
  float yg = (float)y/(-100.00);
  Serial.print("\t");
  Serial.print(yg);
  //Serial.print("g   "); 
 
  zvalue = analogRead(zpin);
  int z = map(zvalue, 266, 394, -100, 100);
  float zg = (float)z/(100.00);
  Serial.print("\t"); 
  Serial.println(zg);
  //Serial.println("g   ");
 // delay(100);
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
  Serial.println();
  delay(300);
}
