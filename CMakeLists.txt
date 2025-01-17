cmake_minimum_required(VERSION 3.30)

project(libcpoly)

set(SRCS
    poly.c
    )
    
set(HEADERS
    poly.h
    )

add_library(libcpoly ${SRCS} ${HEADERS})
