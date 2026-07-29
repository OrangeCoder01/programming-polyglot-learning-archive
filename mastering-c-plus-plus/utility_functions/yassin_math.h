#include <iostream>

float pow(float element, int power)
{
    if(power > 0)
    {
        if(power == 1){return element;}

        float value = element;
        for(int i = 0; i < power - 1; i ++){value *= element;}
        return value;
    }
    else if(power == 0){return 1.0f;}
    else
    {
        if(power == -1){return 1.0f/element;}

        float value = 1.0f/element;
        if(power == -1){return value;}
        for(int i = (power + 1); i < 0; i++ ){value *= 1/element;}
        return value;
    }
}

float sqrt(float element, int root)
{
    int integer_part  = 0;
    for(int i = 0; pow((float)(i), root) <= element; i++){integer_part = i;}
    
    float value = integer_part;
    if(root > 0 )
    {
        float decimal_point = 1.0f;
        int precision = 3;
        for(int i = 0; i < precision; i++)
        {
            decimal_point /= 10.0f;
            for(int j = 0; j <= 9; j++)
            {
                float possible_value = value + (j * decimal_point);
                if(pow(possible_value, root) <= element){value = possible_value;}
                else{break;}
            }
        }
    }
    return value;
}

float round(float input, int decimal_point)
{
    float val_before_round_point = (input * pow(10.0f, decimal_point));
    int val_after_round_point_by_a_decimal_place = (int)(val_before_round_point * 10.0f) % 10;

    if(val_after_round_point_by_a_decimal_place >= 5){val_before_round_point += 1.0f;}
    val_before_round_point = (float)((int)(val_before_round_point));

    return (val_before_round_point * pow(10.0f, -decimal_point));
}

