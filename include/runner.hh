#pragma once
#include "config.hh"
#include "raylib.h"
#include <iostream>
#include <string>

class Runner{
    public:
        Config cfg;
        std::string game_name;

        Runner(bool debug = false){
            this->cfg = Config();
            this->game_name = "Placeholder";
            if (debug){this->_print_config();};
            this->_init();
        }

        Runner(Config config, std::string name, bool debug = false){
            this->cfg = config;
            this->game_name = name;
            if (debug){this->_print_config();};
            this->_init();
        }

        ~Runner(){
            CloseWindow();
        }

        void run(void* game_loop = nullptr){
            while (!WindowShouldClose()){
                BeginDrawing();
                    ClearBackground(RAYWHITE);
                EndDrawing();
            }
        }

    private:
        void _init(){
            std::cout << "**Setting up " << this->game_name << "**\n";
            InitWindow(this->cfg.screen_width, this->cfg.screen_height, this->cfg.title.c_str());
            SetTargetFPS(this->cfg.fps);
        }

        void _print_config(){
            std::cout << "screen_width: " << this->cfg.screen_width << "\n";
            std::cout << "screen_height: " << this->cfg.screen_height << "\n";
            std::cout << "title: " << this->cfg.title << "\n";
            std::cout << "fps: " << this->cfg.fps << "\n";
        }
};
