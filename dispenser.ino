void dispenser()
{
  entrega = cantidad * precio;
      /*Calculamos el saldo necesario: 
       * Ejemplo: el tipo quiere cargar 10 litros, si sale $1,5 el litro
       * entrega es igual a $15. y después corroboramos que tenga el saldo suficiente.
       * Además tenemos que prestarle dinero para sacar 10 litros.
       */
      readNFC(); //ya tiene un delay dentro de 5 segundos.

      if (auxiliar >= (entrega + (10 * precio)) )
        {
          auxiliar = auxiliar - entrega;
          writeNFC();
          /*
           * El codigo que sigue hacia abajo es tan solo para mostrar
           * el saldo restante.
           * Ver si es necesario.
           */
           /*
          lcd.setCursor(0,0);
          lcd.print("SALDO RESTANTE: ");
          lcd.setCursor(0,1);
          lcd.print(auxiliar);
          if(auxiliar < 10)
          {
            lcd.setCursor(1,1);
            lcd.print("                ");
          }
          if(auxiliar < 100)
          {
            lcd.setCursor(2,1);
            lcd.print("                ");
          }
          if(auxiliar < 1000)
          {
            lcd.setCursor(3,1);
            lcd.print("                ");
          }
          delay(2500);*/
        }
}
