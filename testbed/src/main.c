#include "core/application.h"
#include <core/asserts.h>
#include <core/logger.h>
#include <stdlib.h>

int main(void) {
    application_config config;
    config.name = "RMelo Game Engine";
    config.start_height = 480;
    config.start_width = 480;
    config.start_pos_y = 180;
    config.start_pos_x = 180;

    application_create(&config);
    application_run();

    return 0;
}
