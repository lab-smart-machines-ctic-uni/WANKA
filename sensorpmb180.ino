#include <SFE_BMP180.h>
#include <Wire.h>


SFE_BMP180 bmp180;

void setup()
{

  Serial.begin(9600);

  if (bmp180.begin())
    Serial.println("BMP180 iniciado correctamenten");
  else
  {
    Serial.println("Error al iniciar el BMP180");
    while(1); // bucle infinito
  }
}

void loop()
{
  char status;
  double T,P;
  double Pcalibrada,Altitud;
  
  status = bmp180.startTemperature();//Inicio de lectura de temperatura
  if (status != 0)
  {   
    delay(status); //Pausa para que finalice la lectura
    status = bmp180.getTemperature(T); //Obtener la temperatura
    if (status != 0)
    {
      status = bmp180.startPressure(3); //Inicio lectura de presión
      if (status != 0)
      {        
        delay(status);//Pausa para que finalice la lectura        
        status = bmp180.getPressure(P,T); //Obtenemos la presión
        if (status != 0)
        {                  
          Serial.print("Temperatura: ");
          Serial.print(T,2);
          Serial.print(" *C , ");
          Serial.print("Presion: ");
          Serial.print(Pcalibrada=P-4,2);
          Serial.println(" mb");
          Serial.print("Altitud: ");
          Serial.print(Altitud=-8.6832*Pcalibrada + 8791.5);
          Serial.println(" metros");          
        }      
      }      
    }  
    
      if(Altitud>5000)
      {}
      else
      {}

     
  } 
  delay(1000);
}
