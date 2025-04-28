# 主项目源代码配置

# 源代码目录
set(PROJECT_NAME rapidjson_quick)

# 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp)
add_executable(memory stream/memory.cpp)

# 应用项目编译器选项
set_project_compiler_options(${PROJECT_NAME})
set_project_compiler_options(memory)


# 链接库
target_link_libraries(${PROJECT_NAME}
        PRIVATE RapidJSON rapidjson
)
target_link_libraries(memory
        PRIVATE RapidJSON rapidjson
)

# 包含头文件目录
target_include_directories(${PROJECT_NAME}
        PRIVATE ${CMAKE_SOURCE_DIR}/include
)
target_link_directories(memory
        PRIVATE ${CMAKE_SOURCE_DIR}/include
)