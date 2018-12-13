/*======================================================================
*        filename: assgn_st.c
*        author: rambogui
*        data: 2018-11-24 16:39:02
======================================================================*/

#include <stdio.h>
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(int argc, char *argv[])
{
    inflatable bouquet = 
    {
        "sunflowers",
        0.20,
        12.49
    };
    inflatable choice;
    printf("name:%d, price:%f\n", bouquet.name, bouquet.price);

    choice = bouquet;
    printf("name:%d, price:%f\n", bouquet.name, bouquet.price);
    return 0;
}
