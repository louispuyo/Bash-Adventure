cmake_minimum_required(VERSION 3.16)
project(Bash_Adventure C)

set(CMAKE_C_STANDARD 99)

add_executable(Bash_Adventure src/main.c src/julio/main.h src/julio/entity.h src/julio/mob.h src/julio/item.h src/julio/inventaire.h src/julio/actions.h)

