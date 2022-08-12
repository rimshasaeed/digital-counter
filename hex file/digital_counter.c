#include <xc.h>

// Set crystal frequency to 20MHz
#define _XTAL_FREQ 20000000

// Define the name of each control pin
#define digit1 PORTBbits.RB0
#define digit2 PORTBbits.RB1
#define digit3 PORTBbits.RB2
#define digit4 PORTBbits.RB3

// Define switch pins
#define SW1 PORTCbits.RC0
#define SW2 PORTCbits.RC1

// Store a binary bit pattern to be send to PORTD
char binary_pattern[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// Define variables to store the digits
unsigned int a,b,c,d;

// Initialize counter variable
unsigned int counter = 0;

// Main Program
void main(void)
{
    // Set direction control registers to active low
    TRISC = 0xff;
    TRISB = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    
    // Initialize digit control pins
    digit1 = 1;
    digit2 = 1;
    digit3 = 1;
    digit4 = 1;

    while(1)
    {
        // UP COUNTER
        if(SW1==0 && SW2==1)
        {
            // Increment
            counter++;
            
            // Wait till flag reaches 10000
            if(counter>=9999)   
            {
                counter = 0;
            }
            
            // Set values for 7-segment display
            a = counter / 1000;          // holds Thousands digit
            b = ((counter/100)%10);      // holds Hundreds digit
            c = ((counter/10)%10);       // holds Tens digit
            d = (counter%10);            // holds Ones digit

            // Display fourth digit
            PORTD = binary_pattern[a];   // send 1000's place data to fourth digit
            digit1 = 0;                  // turn on forth display unit
            __delay_ms(10);              // delay
            digit1 = 1;                  // turn off forth display unit

            // Display third digit
            PORTD = binary_pattern[b];   // send 100's place data to 3rd digit
            digit2 = 0;                  // turn on 3rd display unit
            __delay_ms(10);              // delay
            digit2 = 1;                  // turn off 3rd display unit

            // Display second digit
            PORTD = binary_pattern[c];   // send 10th place data to 2nd digit
            digit3 = 0;                  // turn on 2nd display unit
            __delay_ms(10);              // delay
             digit3 = 1;                 // turn off 2nd display unit

            // Display first digit
            PORTD = binary_pattern[d];   // send unit place data to 1st digit
            digit4 = 0;                  // turn on 1st display unit
            __delay_ms(10);              // delay
            digit4 = 1;                  // turn off 1st display unit
        }
        
        // DOWN COUNTER
        else if(SW2==0 && SW1==1)
        {
            // Decrement
            counter--;          
            
            // Wait till flag reaches 0
            if(counter==0)   
            {
                counter = 9999;
            }
            
            // Set values for 7-segment display
            a = counter / 1000;          // holds Thousands digit
            b = ((counter/100)%10);      // holds Hundreds digit
            c = ((counter/10)%10);       // holds Tens digit
            d = (counter%10);            // holds Ones digit

            // Display fourth digit
            PORTD = binary_pattern[a];   // send 1000's place data to fourth digit
            digit1 = 0;                  // turn on forth display unit
            __delay_ms(10);              // delay
            digit1 = 1;                  // turn off forth display unit

            // Display third digit
            PORTD = binary_pattern[b];   // send 100's place data to 3rd digit
            digit2 = 0;                  // turn on 3rd display unit
            __delay_ms(10);              // delay
            digit2 = 1;                  // turn off 3rd display unit

            // Display second digit
            PORTD = binary_pattern[c];   // send 10th place data to 2nd digit
            digit3 = 0;                  // turn on 2nd display unit
            __delay_ms(10);              // delay
             digit3 = 1;                 // turn off 2nd display unit

            // Display first digit
            PORTD = binary_pattern[d];   // send unit place data to 1st digit
            digit4 = 0;                  // turn on 1st display unit
            __delay_ms(10);              // delay
            digit4 = 1;                  // turn off 1st display unit
        }
        
        // PAUSE THE COUNTER
        else if(SW1==1 && SW2==1)
        {
            // Set values for 7-segment display
            a = counter / 1000;          // holds Thousands digit
            b = ((counter/100)%10);      // holds Hundreds digit
            c = ((counter/10)%10);       // holds Tens digit
            d = (counter%10);            // holds Ones digit

            // Display fourth digit
            PORTD = binary_pattern[a];   // send 1000's place data to fourth digit
            digit1 = 0;                  // turn on forth display unit
            __delay_ms(10);              // delay
            digit1 = 1;                  // turn off forth display unit

            // Display third digit
            PORTD = binary_pattern[b];   // send 100's place data to 3rd digit
            digit2 = 0;                  // turn on 3rd display unit
            __delay_ms(10);              // delay
            digit2 = 1;                  // turn off 3rd display unit

            // Display second digit
            PORTD = binary_pattern[c];   // send 10th place data to 2nd digit
            digit3 = 0;                  // turn on 2nd display unit
            __delay_ms(10);              // delay
             digit3 = 1;                 // turn off 2nd display unit

            // Display first digit
            PORTD = binary_pattern[d];   // send unit place data to 1st digit
            digit4 = 0;                  // turn on 1st display unit
            __delay_ms(10);              // delay
            digit4 = 1;                  // turn off 1st display unit
        }
    }
    return;
}