cmake_minimum_required(VERSION 3.16)
project(Bash_Adventure C)

set(CMAKE_C_STANDARD 99)

add_executable(Bash_Adventure src/julio/entity.h src/julio/mob.h src/julio/item.h
        src/julio/inventaire.h src/julio/actions.h src/julio/testJ.c
        src/julio/player.h src/julio/monde.h)

if(FALSE) # fake a block comment
    add_executable(src/main.c map1.c)
endif()