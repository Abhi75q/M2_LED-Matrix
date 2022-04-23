# PROJECT REPORT

 # Project Name: Text Display on 8*8 Led Matrix
 
## Introduction:  

8*8 LED Matrix contains 64 LEDs (Light Emitting Diodes) which are arranged in the form of a matrix; hence the name is LED matrix.
We are going to make  matrix through simulation on Simullide.
Then we will write a C program for ATmega328 AVR Microcontroller to control these 64 LEDs matrix.
The Atmega, according to program, powers appropriate LEDs to show characters in scrolling fashion.

 ## Components Required:
 
ATmega328p

Power supply(5V)

64 LEDs

100ohm resistors (8 pieces)

AVR ISP Programmer

Vs code for coding purpose



## Circuit and Working Explanation:  

There are 64 LEDs arranged in a matrix form. So, we have 8 columns and 8 rows. Over those rows and columns, all the positive terminals in a row and brought together. For each row, there is one common positive Terminal for all 8 LED in that row.

![image](https://user-images.githubusercontent.com/100043455/164884273-4354770a-d1e7-46e7-a1e9-0c4dbd6418dd.png)

 




So for 8 rows we have 8 common positive terminals. Consider the first row, as seen in the figure, 8 LEDs from D57 to D64 have a common positive terminal and are denoted by ‘POSITIVE0’. Now if we want to glow the A0 of LED Matrix. Likewise, if we want to glow any LED (or all) in any ROW then we need to power the corresponding common Positive Terminal Pin of that respective Row.

This is not over yet and just leaving the MATRIX POWS with positive supply will not yield anything. We need to ground the Leds negatives to glow them.   So, in 8*8 LED matrix, all the negative terminals of the LEDs in the column are brought together to form eight Common Negative Terminals, lie all the negative terminals in the first column are connected together to the C7(NEGATIVE7).

![image](https://user-images.githubusercontent.com/100043455/164884285-8eb3bc0a-6755-4e83-be4a-d0c0fb9adcba.png)


 

## Driving 8*8 LED Matrix using Multiplexing:

Now let’s say we want to turn ON LED57 then we need to power PORTA0 of ATmega328 and ground the PORTC0 of ATmega328. Now for turning both LED57 and LED50 on, we need to power PINA0, PINA1 and ground PINC0, PINC1. But doing so will not only turn D57, D50 but also D49, D58.
To avoid that we use a technique called Multiplexing.

The human eye cannot capture a frequency more than 30HZ. That is if a LED goes ON and OFF continuously at the rate of 30HZ or more.
The eye sees the LED as continuously ON. However, this is not case and LED will be actually turning ON and OFF constantly. This technique is called multiplexing.
Let’s say for example, we want to only turn on LED57 and LED50 without turning on D49 and D58. Trick is, we will first provide power to first row to turn ON LED57 and wait for 1mSEC, and then we will turn it OFF. Then we will provide power to second row to turn on LED50 and wait for 1mSEC then will turn it OFF. The cycle goes continuously with high frequency and LED57 & LED50 will getting On and Off rapidly and both the LEDs will appear to be continuously ON to our eye. Means we are only providing power to the one row at a time, eliminating the chances of turning on other LEDs in other rows. We will use this technique to show all characters.


## Program-

#define _AVR_ATmega328p_
  #define _AVR_ATmega328_
  #endif


  #include <avr/io.h>
#ifndef _OPTIMIZE_
#endif


    
#define F_CPU 11059200UL //defining crystal frequency
#include <util/delay.h>  //delay header
#define DDRB _SFR_IO8(0x04)
#define DDB0 0
#define DDB1 1
#define DDB2 2
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


int main(void)
{
    DDRD = 0x05; //PORTD as output


    DDRB = 0x04; //PORTB as output
    
char ALPHA[]={0,0,0,0,0,0,0,0,0,0,0,
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


    char PORT[8] = {1,2,4,8,16,32,64,128}; //pin values of a port 2^0,2^1,2^2……2^7
        uint8_t l =0;
    
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


## SimulIDE diagram:
 
 ![image](https://user-images.githubusercontent.com/100043455/164884335-5c87fabb-8bda-4ee8-a7fe-965279a6005e.png)


In the diagram I have used atmega328.
8pices of resistor (100ohm)
Voltage source(5V)
8*8 led matrix


 


