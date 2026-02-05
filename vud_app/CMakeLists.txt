# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(vud_app)

include_directories(include)

file(GLOB SOURCE "src/*.c")
target_sources(app PRIVATE main.c ${SOURCE})
