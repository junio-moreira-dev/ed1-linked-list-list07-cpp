cmake_minimum_required(VERSION 4.2)
project(ed1_linked_list_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed1_linked_list_cpp main.cpp
#        include/LinkedList.h
#        include/List.h
#        src/LinkedListTest.cpp)

# Inclui a pasta de cabeçalhos (.h) globalmente
include_directories(include)

# 1. Executável Principal (Aplicação / main.cpp)
add_executable(ed1_linked_list_cpp
        main.cpp
        include/LinkedList.h
        include/List.h
)

# 2. Executável dos Testes Unitários
add_executable(LinkedListTest
        src/LinkedListTest.cpp
        include/LinkedList.h
        include/List.h
)
