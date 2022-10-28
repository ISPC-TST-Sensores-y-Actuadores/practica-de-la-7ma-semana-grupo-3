#include <VirtualWire.h>// INCLUYO LIBRERIA A UTILIZAR EN EL PROGRAMA

void setup()
{  // INICIALIZO LA CONFIGURACION SERIA A 9600 BAUDIOS
    Serial.begin(9600);    
    // ENVIO MENSAJE POR MONITOR SERIE
    Serial.println("Emisor RF");

    // Se inicializa el RF
    vw_set_ptt_inverted(true);
    vw_set_tx_pin(2); //Pin 2 como salida para el RF 
    vw_setup(2000); // velocidad: Bits per segundo
}
 // VARIABLE QUE ALMACENA EL CARACTER ENVIADO
     char dato[1];
void loop()
{

   
      dato[0]='1';// VALOR INICIAL
      vw_send((uint8_t*)dato,sizeof(dato));// CONFIGURO PARA ENVIAR DATO
      vw_wait_tx();     //ESPERO LA TRANSMISION    
    // ENVIO MENSAJE POR EL MONITOR SERIE
    Serial.println("Emisor Enviando 1");
    delay(3000);// DELAY DE 1 SEGUNDO PARA ENVIAR OTRO DATO
      dato[0]='0';// ENVIO OTRO CARACTER
      vw_send((uint8_t*)dato,sizeof(dato));// CONFIGURO PARA ENVIAR
      vw_wait_tx();    // ESPERA PARA ENVIAR
    // ENVIO MENSAJE POR EL MONITOR SERIE     
    Serial.println("Emisor Enviando 0");
    delay(3000);// DELAY DE 1 SEGUNDO 
}
