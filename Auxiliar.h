#ifndef AuxForDigs

#define AuxForDigs


float random(float lowerBound, float upperBound, int dig = 0)
{
    int ten = 1;

    for(int i = 1; i <= dig; i++)
        ten *= 10;

    int big = upperBound * ten;
    int lil = lowerBound * ten;

    float value = rand() % (big - lil + 1) + lil;

    return value / ten;
}

int floatDecimals ( float value )
{
    int dec = 0;
    while ( (float)((int)value) != value )
    {
        dec ++;
        value *= 10;
    }
    return dec;
}

float map (float myValue, float itsLowerBound, float itsUpperBound, float lowerBound, float upperBound)
{
    float goodValue = lowerBound ;
    goodValue += (upperBound - lowerBound) ;
    goodValue *= ((myValue - itsLowerBound ) / (itsUpperBound - itsLowerBound));
    return goodValue;
}


#endif // AuxForDigs
