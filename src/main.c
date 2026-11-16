#include <stdio.h>

int emergency_mode = 0;

struct alert_msg {
    char vehicle_type[16];
    double latitude;
    double longitude;
    int speed;
    int heading;
};

void set_emergency_mode(int on)
{
    emergency_mode = on;
    if (on)
        printf("EMERGENCY MODE: ON - siren and lights active\n");
    else
        printf("EMERGENCY MODE: OFF\n");
}

void build_alert(struct alert_msg *msg)
{
    snprintf(msg->vehicle_type, sizeof(msg->vehicle_type), "AMBULANCE");
    msg->latitude = 12.9172;
    msg->longitude = 77.6229;
    msg->speed = 50;
    msg->heading = 0;
}

void print_alert(const struct alert_msg *msg)
{
    printf("ALERT: %s at (%.4f, %.4f) speed %d km/h heading %d deg\n",
           msg->vehicle_type, msg->latitude, msg->longitude,
           msg->speed, msg->heading);
}

int main(void)
{
    struct alert_msg msg;

    printf("Ambulance OBU started\n");
    set_emergency_mode(1);

    if (emergency_mode) {
        build_alert(&msg);
        print_alert(&msg);
    }
    return 0;
}
