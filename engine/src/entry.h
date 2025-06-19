#pragma once

#include "core/application.h"
#include "core/kmemory.h"
#include "core/logger.h"
#include "game_types.h"

extern b8 create_game(game *out_game);

/**
 * The main entry point of the application
 */
int main(void) {
    initialize_memory();

    game game_inst;
    if (!create_game(&game_inst)) {
        KFATAL("Could not create game!");
        return -1;
    }

    if (!game_inst.render || !game_inst.update || !game_inst.initialize ||
        !game_inst.on_resize) {
        KFATAL("The game's function pointers must be assigned!");
        return -2;
    }

    if (!application_create(&game_inst)) {
        KINFO("Application failed to create!");
        return 1;
    };

    if (!application_run()) {
        KINFO("Application did not shutdown gracefully!");
        return 2;
    };

    shutdown_memory();

    return 0;
}
