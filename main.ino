//Utility Function
void reportStatus();

//Connections
const int motorA1 = 8;
const int motorA2 = 10;
const int motorB1 = 12;
const int motorB2 = 13;
const int leftSensorPin = A0;
const int rightSensorPin = A1;

//Sensor States
int leftSensorState;
int rightSensorState;

char movementState;

void setup()
{
    //Setup motors for output
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);

    //Setup sensors for input
    pinMode(leftSensorPin, INPUT);
    pinMode(rightSensorPin, INPUT);

    Serial.begin(9600);

    delay(3069);
}

void loop()
{
    //Read from IR sensors
    leftSensorState = analogRead(leftSensorPin);
    rightSensorState = analogRead(rightSensorPin);

    if(rightSensorState > 500 && leftSensorState > 500)
    {
        //Moves Forward
        if(movementState != 'F')
        {
            movementState = 'F';
            reportStatus();
        }
        digitalWrite(motorA1, HIGH);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, HIGH);
        digitalWrite(motorB2, LOW);
    }
    else if(rightSensorState > 500 && leftSensorState < 500)
    {
        //Turns Left
        if(movementState != 'L')
        {
            movementState = 'L';
            reportStatus();
        }
        digitalWrite(motorA1, HIGH);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW);
        digitalWrite(motorB2, LOW);
    }
    else if(rightSensorState < 500 && leftSensorState > 500)
    {
        //Turns Right
        if(movementState != 'R')
        {
            movementState = 'R';
            reportStatus();
        }
        digitalWrite(motorA1, LOW);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, HIGH);
        digitalWrite(motorB2, LOW);
    }
    else
    {
        //Stops
        if(movementState != 'X')
        {
            movementState = 'X';
            reportStatus();
        }
        digitalWrite(motorA1, LOW);
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW);
        digitalWrite(motorB2, LOW);
    }
}

void reportStatus()
{
    Serial.print(movementState);
    Serial.print(' ');
    Serial.print(leftSensorState);
    Serial.print(' ');
    Serial.print(rightSensorState);
    Serial.print('\n');
}