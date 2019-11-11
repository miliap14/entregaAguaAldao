void caudal()
{
  do 
    {
      lcd.setCursor(0,0);
      lcd.print("Entregando...        ");
      lcd.setCursor(0,1);
      lcd.print("                 ");
      float frecuencia=ObtenerFrecuecia(); //obtenemos la frecuencia de los pulsos en Hz
      float caudal_L_m=frecuencia/factor_conversion; //calculamos el caudal en L/m
      dt=millis()-t0; //calculamos la variación de tiempo
      t0=millis();
      volumen=volumen+(caudal_L_m/60)*(dt/50); // volumen(L)=caudal(L/s)*tiempo(s)
  
      //-----Enviamos por el puerto serie---------------
      digitalWrite(contactor, LOW);

      /*if(caudal_L_m == 0)//posible error, no estamos consultando el caudal y nunca sale el for
        {
          for (int i = 60; i > 0 ; i--)
            {
              mostrar(0, 0, "Retirar antes de:", 0, 1, String(i) + "    ");
              if (caudal_L_m != 0)
                {
                  i = 0;
                }
              if (i == 1)
                {
                  digitalWrite(contactor, HIGH);//cortamos
                  cantidad = 0.0;
                  auxiliar = 0;
                  menu = 0;  
                }
              delay(200000);
            }
        }*/
       if(caudal_L_m == 0)
         {
          for( int i = 60 ; i > 0 ; i-- )
            {
              lcd.setCursor(0,0);
              lcd.print("Retirar antes de:");
              lcd.setCursor(0,1);
              lcd.print(i);
              delay(1000);
              Serial.println(caudal_L_m);
              if ( caudal_L_m != 0 )
                {
                  i = 0;
                }
            }
            
          digitalWrite(contactor, HIGH);//cortamos
          String payloadAsString = "";
          cantidad = 0.0;
          auxiliar = 0;
          selection = 0;
          volumen = 0;
           
         }
        
       Serial.print ("Caudal: ");
       Serial.print (caudal_L_m,3);
       Serial.print ("L/min\tVolumen: ");
       Serial.print (volumen,3);
       Serial.println (" L");
    }while(volumen <= (cantidad*0.92));

    digitalWrite(contactor, HIGH);//cortamos
    String payloadAsString = "";
    cantidad = 0.0;
    auxiliar = 0;
    selection = 0;
    volumen = 0;
}
