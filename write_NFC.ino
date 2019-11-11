void writeNFC()
{
    if (nfc.tagPresent()) 
       {
        NdefMessage message = NdefMessage();
        String texto = String(auxiliar);
        Serial.print("TEXTO: ");
        Serial.println(texto);
        message.addTextRecord(texto); // Text Message you want to Record
        boolean success = nfc.write(message);
        if (success) 
          {
            lcd.setCursor(0,0);
            lcd.print("MUCHAS GRACIAS         ");
            lcd.setCursor(0,1);
            lcd.print("RETIRE SU AGUA      ");
            delay(2000);
            selection = 3;
          } 
        else 
          {
            lcd.setCursor(0,0.);
            lcd.print("FALLO EL PROCESO");
            lcd.setCursor(0,1);
            lcd.print("POR FAVOR REPITA");
            selection = 0;
          }
        }
     else
      {
        lcd.setCursor(0,0);
        lcd.print("NO SE ENCONTRO          ");
        lcd.setCursor(0,1);
        lcd.print("LA TARJETA              ");
        delay(2000);
        selection = 0;
      }
    delay(2000);
    
}
