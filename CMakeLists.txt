cmake_minimum_required(VERSION 3.5)
project(x_mysql)

include_directories(
    include
)

aux_source_directory(src DIR_LIB_SRCS)
add_library(${PROJECT_NAME}
    ${DIR_LIB_SRCS}
)

target_link_libraries(${PROJECT_NAME}
    mysqlclient
)

add_executable(mysql_demo example/mysql_demo.cpp)
target_link_libraries(mysql_demo
    ${PROJECT_NAME}
)

add_executable(x_mysql_demo example/x_mysql_demo.cpp)
target_link_libraries(x_mysql_demo
    ${PROJECT_NAME}
)