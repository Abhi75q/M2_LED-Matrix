  #ifndef __AVR_ATmega328P__ 

  #define _AVR_ATmega328_
  #endif

  #include <avr/io.h>
#ifndef _OPTIMIZE_
#endif
#include <util/delay.h>  //delay header
#define DDRB _SFR_IO8(0x04)
#define DDB0 0
#define DDB1 1
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB _SFR_IO8(0x05)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define DDRD _SFR_IO8(0x0A)

#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD _SFR_IO8(0x0B)
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

 unsigned int main(void)
{
    DDRD = 0x05; //PORTD as output

    DDRB = 0x04; //PORTB as output
    
unsigned char ALPHA[]={0,0,0,0,0,0,0,0,0,0,0,
    0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,
    0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,
    0b01111001,0b11111011,0b11011111,0b11011110,0b11011100,0b11011000,0b11111111,0b11111111    ,0,0,
    0,0b11000011,0b11000011,0b11000011,0b11000011,0b11100111,0b01111110,0b00111100,0,0,
    0b11111110,0b11111111,0b00000011,0b00000011,0b00000011,0b00000011,0b11111111,0b11111110,0,0,
    0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,
    0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,
    0,0b01111110,0b10111101,0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0,0,
    0b11000011,0b11000011,0b11000011,0b11111111,0b11111111,0b11000011,0b11000011,0b11000011,0,0,
    0b00011111,0b11011111,0b11011000,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,
    0,0b11011011,0b11011011,0b11011011,0b11011011,0b11011011,0b11111111,0b11111111,0,0,
    0b11001110,0b11011111,0b11011011,0b11011011,0b11011011,0b11011011,0b11111011,0b01110011,0,0,
    0b11000000,0b11000000,0b11000000,0b11111111,0b11111111,0b11000000,0b11000000,0b11000000,0,0,
    0,0,0,0,0,0,0,0,0,0,0,
    };

    unsigned char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2……2^7

    
    while(1)
    {

        int a, x, i;
        // there are 142 values in the set of ALPHA to display 'CIRCUIT DIGEST', then shift them after each loop execution
        for( x=0;x<142;x++)
        {
                for( a=0;a<20;a++) //show each character 20 times before shifting a column
                {
                    
                    for ( i=0;i<8;i++)
                    {
                        PORTB = ~PORT[i];    //ground the PORTC pin
                        PORTB = ALPHA[i+x];  //power the PORTB
                        _delay_ms(1);
                        PORTD = PORT[i];     //clear pin after 1msec
                    }
                    
                }
    }            
        }
}
