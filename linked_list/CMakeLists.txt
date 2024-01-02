cmake_minimum_required(VERSION 3.26)
project(linked_list C)

set(CMAKE_C_STANDARD 11)

add_executable(linked_list
        ll.h
        single_link/single_link.h
        single_link/single_link.c
        single_link/sl_test.c
        double_link/doubly-linked.c
        double_link/doubly-linked.h)
