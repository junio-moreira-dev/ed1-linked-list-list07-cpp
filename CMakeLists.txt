cmake_minimum_required(VERSION 4.2)
project(ed1_linked_list_list07_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_executable(ed1_linked_list_cpp main.cpp
#        include/LinkedList.h
#        include/List.h
#        src/LinkedListTest.cpp)

cmake_minimum_required(VERSION 3.20)
project(ed1_linked_list_list07_cpp)

set(CMAKE_CXX_STANDARD 20)

# Permite incluir arquivos da pasta include/ diretamente com #include "LinkedList.h"
include_directories(include)

# Executável principal caso queira rodar o main.cpp da raiz
add_executable(main_app main.cpp)

# Executáveis independentes para cada exercício da lista:
add_executable(Exer01_AddSorted src/Exer01_AddSorted.cpp)
add_executable(Exer02_DeleteNodeWithoutHead src/Exer02_DeleteNodeWithoutHead.cpp)
add_executable(Exer03_ReverseLinkedList src/Exer03_ReverseLinkedList.cpp)
add_executable(Exer04_MergeTwoSortedLists src/Exer04_MergeTwoSortedLists.cpp)
add_executable(Exer05_RemoveNthFromEnd src/Exer05_RemoveNthFromEnd.cpp)
