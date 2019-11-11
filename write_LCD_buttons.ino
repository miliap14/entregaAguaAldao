void write_LCD_buttons()
{
 lcd_key = read_LCD_buttons();  
/* Suspendemos estos botones porque no lo usamos
   if( lcd_key == btnRIGHT)
   {
 
   }
      // lcd.print("RIGHT ");
   else if ( lcd_key == btnLEFT )
   {
    
    }
      // lcd.print("LEFT   ");
   else*/ 
   if ( lcd_key == btnUP)
        {
          Serial.println("Arriba apretado");
          if ( selection == 0 )
          {
            if ( cantidad < 50.0 )
              {
                cantidad = cantidad + 1.0;
              }
          }
          
        }
   else if ( lcd_key == btnDOWN)
        {

          //-------------------
          Serial.println("Abajo apretado");
          if ( selection == 0 )
            {
              cantidad = cantidad - 1.0;
              if ( cantidad < 0 )
                {
                  cantidad = 0.0;
                }
            }
        }
   else if ( lcd_key == btnSELECT && cantidad != 0) //Si apretamos select y hay una cantidad ingresada
        {
         Serial.println("Seleccionar apretado");
         if ( selection == 0 )
            {
              selection = 1;
            }
        }
   else if ( lcd_key == btnNONE)
        {
        }
}
