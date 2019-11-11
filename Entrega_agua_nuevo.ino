/*
 * ENTREGA DE AGUA NUEVO
 * 05/08/19
 */
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <LiquidCrystal.h>

PN532_SPI pn532spi(SPI, 53);
NfcAdapter nfc = NfcAdapter(pn532spi);

// LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcd_key     = 0;
int key  = 0;

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

volatile int NumPulsos;         //variable para la cantidad de pulsos recibidos
int PinSensor = 2;              //Sensor conectado en el pin 2
float factor_conversion=6.7257; //para convertir de frecuencia a caudal
float volumen=0;
long dt=0;                      //variación de tiempo por cada bucle
long t0=0;                      //millis() del bucle anterior

//---Función que se ejecuta en interrupción---------------
const int contactor = 3;
float cantidad = 0.0; //litros a contar

//variables
int menu = 0;
int auxiliar = 0;
float precio = 1.0; //precio por litro.
float entrega = 0.0;
String mensaje1 = "";
String mensaje2 = "";
int tiempo= 0;
int control = 0;

void ContarPulsos ()
{
  NumPulsos++; //incrementamos la variable de pulsos
}

//---Función para obtener frecuencia de los pulsos--------
int ObtenerFrecuecia()
{
  int frecuencia;
  NumPulsos = 0;

  //Ponemos a 0 el número de pulsos
  interrupts();

  //Habilitamos las interrupciones
  delay(50);
  
  //muestra de 0,05 segundo
  noInterrupts(); //Deshabilitamos las interrupciones
  frecuencia=NumPulsos; //Hz(pulsos por segundo)
  return frecuencia;
}
 //---------- VARIABLES PRGORAMA ---------
 int selection = 0;
 /*
  *  Estaods de selection:
  *  0 = menu principal -> ingrese litros
  *  1 = etapa 1 retire agua -> acerque su tarjeta (en esta etapa, si no hay una tarjeta se sale y
  *                             el cartel aparece por un tiempo determinado.
  *  
  */
 
void setup() 
{
  Serial.begin( 9600 );
  lcd.begin( 16 , 2 );
  lcd.clear();
  nfc.begin();
  pinMode(PinSensor, INPUT);
  pinMode(contactor, OUTPUT);
  digitalWrite(contactor, HIGH);//cortamos
  attachInterrupt(0,ContarPulsos,RISING);//(Interrupción 0(Pin2),función,Flanco de subida)
  Serial.println ("Envie 'r' para restablecer el volumen a 0 Litros");
  t0=millis();
}

void loop() 
{
  read_LCD_buttons();
  write_LCD_buttons();
  if ( selection == 0)
    {
      ppal();
    }
  if ( selection == 1)
    {
      acerque();
    }
  if ( selection == 2)
    {
      dispenser();
    }
  if ( selection == 3)
  {
     caudal();
  }
}

void ppal()
{
  lcd.setCursor(0,0);
  lcd.print("INGRESE LITROS: ");
  lcd.setCursor(0,1);
  int litros = int(cantidad);
  lcd.print(litros);
  if ( litros < 10 )
    {
      lcd.setCursor(1,1);
      lcd.print("               ");
    }
  else
    {
      lcd.setCursor(2,1);
      lcd.print("             ");
    }
}

void acerque()
{
  lcd.setCursor(0,0);
  lcd.print("APOYE SU TARJETA");
  lcd.setCursor(0,1);
  lcd.print("                ");
  /*for (int i = 0; i <= 5 ; i++)
    {
      lcd.display();
      delay(500);
      lcd.noDisplay();
      delay(500);
    }*/
    //lcd.display();
   selection == 2;
}

void ends()
{
  
}
