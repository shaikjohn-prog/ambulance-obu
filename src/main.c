#include <stdio.h>

int emergency_mode = 0;

void set_emergency_mode(int on)
{
    emergency_mode = on;
    if (on)
        printf("EMERGENCY MODE: ON - siren and lights active\n");
    else
        printf("EMERGENCY MODE: OFF\n");
}

int main(void)
{
    printf("Ambulance OBU started\n");
    set_emergency_mode(1);
    return 0;
}
