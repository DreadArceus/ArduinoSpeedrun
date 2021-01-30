void setup() //this function is run by arduino once on starting
{
    Serial.begin(9600); //we connect to the serial monitor

    /* Above line is a perfect example of something we only need to do once on starting,
        Thats the kind of code written in setup() */
}

void loop() //this function is ran over and over, as long as arduino is powered
{
    //lets say we have connected a Light Dependent Resistor(LDR) to pin A0 (first analog pin)
    int intensityOfLight = analogRead(A0);
    //above line would read the intensity of light measured by our LDR

    Serial.println(intensityOfLight);
    //Print intensity to the Serial Monitor, we get a better idea due to this

    /* now we can use this intensity to do stuff
        lets say we have a motor connected to pin 8 (digital pin)
        and we want it only spin/run when intensity crosses a threshold
        {Note: motor may be connected by 2 pins, this is just an example for simplicity} */
    if(intensityOfLight > 700)
    {
        digitalWrite(8, 1); //Activate motor
    }
    else
    {
        digitalWrite(8, 0); //Deactivate motor
    }
    delay(1000); //Pauses code for 1 second
}