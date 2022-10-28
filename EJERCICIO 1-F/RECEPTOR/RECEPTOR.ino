#include <VirtualWire.h>// INCLUYO LIBRERIA
// CONFIGURACION
void setup()
{
 
    // Se inicializa el RF
    vw_set_ptt_inverted(true); // 
    vw_set_rx_pin(2);  //Pin 2 como entrada del RF
    vw_setup(2000);  // velocidad: Bits per segundo
    Serial.begin(9600);  // CONFIGURO EL MONITOR SERIE
    Serial.println("RECEPTOR");// ENVIO MENSAJE
    vw_rx_start();       // Se inicia como receptor
    
    pinMode(13, OUTPUT);    //Configuramos el pin del Led como SALIDA, LED INTEGRADO
    digitalWrite(13, false);// ESTA APAGADO
}

void loop()
{  // CONFIGURO EL DATO A RECIBIR
    uint8_t dato [VW_MAX_MESSAGE_LEN];
    uint8_t datoleng=VW_MAX_MESSAGE_LEN;
 
    //verificamos si hay un dato valido en el RF
    if (vw_get_message(dato,&datoleng))
    {  
        if( dato[0]=='1') // SI DATO ES DE VALOR 1
        {
            Serial.println("GRUPO3");// ENVIO MENSAJE
            digitalWrite(13, HIGH); //Encendemos el Led INTEGRADRO
            delay(3000);
        }
        else 
        {    Serial.println("         ");// NO SE ENVIA NADA
             delay(3000);
            digitalWrite(13, LOW); //Apagamos el Led
        }            
    }
}
