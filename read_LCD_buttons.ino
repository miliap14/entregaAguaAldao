int read_LCD_buttons()  // Lee los botones y devuelve le valor pulsado
{
 key = analogRead(0);      // Leemos la puerta A0 
 // Mis botones dan:  0, 145, 329,507,743 ; Comprueba que tu shield devuelve valores parecidos
 // Y ahora los comparamos con un margen comodo

 if (key > 1100) return btnNONE; //Si no se pulsa nada salimos (el 99% de las veces) 
 if (key >= 000 && key < 005)   
    {
      delay(150);
      return btnRIGHT;  
    }
 if (key > 90 && key < 100)  
    {
      delay(150);
      return btnUP; 
    }
 if (key > 240 && key < 260)  
    {
      delay(150);
      return btnDOWN;
    }
 if (key > 400 && key < 420)  
    {
      delay(150);
      return btnLEFT; 
    }
 if (key > 630 && key < 650)  
    {
      delay(150);
      return btnSELECT;  
    }

 return btnNONE;  //
}
