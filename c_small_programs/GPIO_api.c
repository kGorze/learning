#include <gpiod.h>

int main(){
    struct gpiod_chip *chip = gpiod_chip_open("/dev/gpiochip0");
    struct gpiod_line *line = gpiod_line_request_output(chip, "GPIO18", 0);
    gpiod_line_request_output(line, "blinky", 0);
    for(;;){
        gpiod_line_set_value(line, 1); usleep(2000);
        gpiod_line_set_value(line, 0); usleep(2000);
    }
}