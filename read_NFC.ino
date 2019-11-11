void readNFC()
{
  delay(5000);
  if (nfc.tagPresent())
    {
      NfcTag tag = nfc.read();
    
      if (tag.hasNdefMessage()) // If your tag has a message
        {

          NdefMessage message = tag.getNdefMessage();
      
          int recordCount = message.getRecordCount();
          for (int i = 0; i < recordCount; i++)
              {
                NdefRecord record = message.getRecord(i);

                int payloadLength = record.getPayloadLength();
                byte payload[payloadLength];
                record.getPayload(payload);
        
                String payloadAsString = ""; // Processes the message as a string vs as a HEX value
                for (int c = 3; c < payloadLength; c++) 
                   {
                      payloadAsString += (char)payload[c];
                    }
                Serial.print("  Information (as String): ");
                Serial.println(payloadAsString);
                auxiliar = payloadAsString.toInt(); //Convertimos el valor a entero
              }
      }
    }
     else
      {
        lcd.setCursor(0,0);
        lcd.print("NO SE ENCONTRO          ");
        lcd.setCursor(0,1);
        lcd.print("LA TARJETA              ");
        delay(2000);
        cantidad = 0;
        selection = 0;
        entrega = 0;
      }
}
