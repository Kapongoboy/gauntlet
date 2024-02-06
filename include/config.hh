#pragma once
#include <iostream>
#include <string>

class Config{
    public:
        int screen_width;
        int screen_height;
        int fps;
        std::string title;

        Config(){
            this->_set_defaults();
        };

        Config(int argc, char* argv[]){
            if (argc < 3){
                std::cerr << "Not enough arguments, please provide at least an option and it's value\n";
                std::cout << "\nUsage: ./game -sw [screen_width] -sh [screen_height] -t [title] -f [fps]\n";
            }

            this->_set_defaults();
            this->_parse_args(argc, argv);
        }

    private:
        void _parse_args(int argc, char* argv[]){
            for (size_t i = 1; i < argc; i++){
                try{
                    if (std::string(argv[i]) == "-sw"){
                        this->screen_width = std::stoi(argv[i+1]);
                    } else if (std::string(argv[i]) == "-sh"){
                        this->screen_height = std::stoi(argv[i+1]);
                    } else if (std::string(argv[i]) == "-t"){
                        this->title = argv[i+1];
                    } else if (std::string(argv[i]) == "-f"){
                        this->fps = std::stoi(argv[i+1]);
                    }
                } catch (std::exception& e){
                    std::cerr << "Invalid argument: " << argv[i] << " or value is missing\n";
                    std::cout << "\nUsage: ./game -sw [screen_width] -sh [screen_height] -t [title] -f [fps]\n";
                }
            }
        };

        void _set_defaults(){
            this->screen_width = 800;
            this->screen_height = 450;
            this->title = "Game Title Placeholder";
            this->fps = 60;
        }
};
