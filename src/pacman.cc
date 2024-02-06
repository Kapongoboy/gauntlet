#include "config.hh"
#include "runner.hh"

int main(int argc, char* argv[]) {
    Config config;
    if (argc == 0){
        config = Config();
    } else {
        config = Config(argc, argv);
    }

    auto game = Runner(config, "Pacman");
    game.run();
    return 0;
}
