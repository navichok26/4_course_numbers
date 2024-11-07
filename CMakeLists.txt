cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(MyProject)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавляем файл BigNums.h в список включаемых директорий
include_directories(${CMAKE_SOURCE_DIR}/deps/include)

# Создаем список подпапок, в которых находятся main.cpp
set(SUBDIRS 1 2 3 4 6)

# Добавляем Google Test
# include(FetchContent)

# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
# )

# FetchContent_MakeAvailable(googletest)

# Проходим по каждой подпапке и добавляем цель для компиляции main.cpp
foreach(SUBDIR ${SUBDIRS})
    # Компиляция main.cpp и algos.cpp
    add_executable(main_${SUBDIR} ${SUBDIR}/main.cpp ${SUBDIR}/algos.cpp ${CMAKE_SOURCE_DIR}/deps/bigNum.cpp ${CMAKE_SOURCE_DIR}/deps/millerRabin.cpp)

    # Компиляция test_main.cpp и algos.cpp
    # add_executable(test_${SUBDIR} ${SUBDIR}/test_main.cpp ${SUBDIR}/algos.cpp ${CMAKE_SOURCE_DIR}/deps/bigNum.cpp)
    # target_link_libraries(test_${SUBDIR} gtest_main)

    # # Добавляем тесты
    # add_test(NAME test_${SUBDIR} COMMAND test_${SUBDIR})
endforeach()
