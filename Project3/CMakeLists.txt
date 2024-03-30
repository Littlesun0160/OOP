cmake_minimum_required(VERSION 3.25.0) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произойдёт аварийный выход.

set(PROJECT_NAME lab3) # задать константу с именем проекта 
project("${PROJECT_NAME}") # имя проекта 


set(CMAKE_CXX_STANDARD 17) # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" main.cpp
							Font.hpp) # добавить исполняемый файл

					 
file(COPY 5.txt DESTINATION "/") # скопировать файл text.txt в корневую папку проекта
file(COPY 7.txt DESTINATION "/")