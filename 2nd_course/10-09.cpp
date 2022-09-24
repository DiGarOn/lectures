/*

Cmake - не занимается сборкой. выполняет генерацию конфига для системы сборки (make)

CmakeLists.txt:
    cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)
    project(HELLO)
    add_executable(helloDemo main.cpp func.cpp)

ninja - система сборки 
преимущества - может работать с make файлом и системой make
недостаток - возможные проблемы с памятью

qmake - система конфигурации проектами на основе библиотеки QT. генирирует make
-project - генирируют проект 


1) qmake -project - создает файл QT проекта имя.pro
2) qmake
3) make

Анализ покрытия 
    lcov
    gcov
Нужен отчет о покрытии 
    g++ -fprofile-arcs -ftest-coverage main.cpp -lgcov -o main
    ./main
    lcov -d. --capture --output-file cov.info
    genhtml -o report cov.info

Юнит-тестирование
    google-test
Введение в agile
    экстремальное программирование

 §
Написание кода-\
            \-отладка-\
                \-документрирование-\
                            \-сопровождение
    
RAD:
     /  разработка  \
отладка    <----   тестирование


*/
//EX:
#include <gtest/gtest.h>
TEST(gtest_simple_test_case1, gtest_simple) { ASSERT_EQ(1,0) << "1 != 0"; }
int main(int argc, char ** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}