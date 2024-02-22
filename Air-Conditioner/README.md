# Air-Conditioner

# Project Description:
Using hardware kit, you are required to design air conditioner system
#
#Hardware components:
#
LCD
#
Keypad
#
Temperature sensor
#
Buzzer
#
Software
#
#System requirements:
#
1- When system start LCD prompt welcome message for 1 second, then display the default temp is 20 ,the message appear for 1 second
#
2- ask to set initial temperature for 0.5 second and disappear
#
3- display range of temperature min=18,max=35
#
4- button_1 and button_2 used for increment and decrement respectively
#
5- each button press the temperature on the screen is update
#
Min=18        Temp            Max=35
#
||||||||||||||||||||||||||||||||||||
#
6- Once button_3 is pressed the temperature is set and LCD display current temp=…..
And display buzzer shape if temperature > set temperature & buzzer ON
#
7- once button_4 is press back to step_2 (readjust mode),stop buzzer if it was working add timeout
#
8- if button_5 is press mean reset temperature to its default and display
Temp value is resettled to 20 degree
#
9- after set mode all buttons are not allowed except button_4 and button_5 and display error message for 0.5 second (the operation is not allowed)-add timeout
#
#
#
Button_1 : Increment
#
Button_2 : Decrement
#
Button_3 : Set temperature
#
Button_4 : Adjust temperature
#
Button_5 : Reset to default
