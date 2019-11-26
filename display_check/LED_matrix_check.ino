#define C_INPUT  2
#define R_INPUT  3
//RCK shift register pin
#define LATCH    4
#define C_SR_CLK 5
#define R_SR_CLK 6


#define DEBUG


void setup()
{
    #ifdef   DEBUG
    Serial.begin(9600);
    #endif //DEBUG
    
    for(int p = 2; p <= 6; ++p)
    {
        #ifdef   DEBUG
        Serial.println((String)"Pin " + p + " now output enabled\n");
        #endif //DEBUG
        pinMode(p, OUTPUT);
    }
    
    #ifdef   DEBUG
    Serial.println();
    #endif //DEBUG
}

void loop()
{
    for(int r = 0; r <= 7; ++r)
    {
        #ifdef   DEBUG
        Serial.println((String)"Row " + r + " now active\n");
        #endif //DEBUG
        lightRow(r);
        delay(1000);
    }
}


void enableInput(bool column)
{
    if(column)
    {
        digitalWrite(C_SR_CLK, HIGH);
        return;
    }
    digitalWrite(R_SR_CLK, HIGH);
}

void disableInput(bool column)
{
    if(column)
    {
        digitalWrite(C_SR_CLK, LOW);
        digitalWrite(C_INPUT, LOW);
        return;
    }
    digitalWrite(R_SR_CLK, LOW);
    digitalWrite(R_INPUT, LOW);
}


void lUpdate()
{
    digitalWrite(LATCH, HIGH);
    delay(800);
    digitalWrite(LATCH, LOW);
}

void lightRow(int row)
{
    //Data
        //Columns
    enableInput(1);
    #ifdef   DEBUG
    Serial.println("Wrote 11111111 to column shift register\n");
    #endif //DEBUG
    for(int c = 0; c <= 7; ++c)
        digitalWrite(C_INPUT, HIGH);
    disableInput(1);

        //Rows
    enableInput(0);
    #ifdef   DEBUG
    Serial.print("Wrote ");
    #endif //DEBUG
    for(int r = 0; r <= 7; ++r)
    {
        if(r == row)
        {
            #ifdef   DEBUG
            Serial.print(1);
            #endif //DEBUG
            digitalWrite(R_INPUT, HIGH);
        }
        else
        {
            #ifdef   DEBUG
            Serial.print(0);
            #endif //DEBUG
            digitalWrite(R_INPUT, LOW);
        }

        delay(800);
    }
    disableInput(0);

    #ifdef   DEBUG
    Serial.println(" to row shift register\n");
    #endif //DEBUG

    lUpdate();
}
