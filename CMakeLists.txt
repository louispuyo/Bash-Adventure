cmake_minimum_required(VERSION 3.16)
project(Bash_Adventure0)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(.vscode)
include_directories(bin)
include_directories(src)
include_directories(src/louis)
include_directories(test)

add_executable(Bash_Adventure0
        .idea/.gitignore
        .idea/Bash-Adventure.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        .vscode/settings.json
        bin/main
        "bin/NE PAS OUVRIR.txt"
        src/louis/FonctionsFichier.h
        src/louis/modelsMap.c
        src/louis/plateau.c
        src/main.c
        test/test.md
        README.md
        requirements.md)
