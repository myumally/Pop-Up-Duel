@echo off
set CXX=g++
set CXXFLAGS=-Wall -Wextra -I C:\SFML\include -I include -g
set LDFLAGS=-LC:\SFML\lib -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system

rem Noms des exécutables
set EXE=pop.exe

rem Création du dossier build s'il n'existe pas
if not exist build mkdir build

rem Compilation des fichiers sources
for %%f in (src\*.cpp) do (
    echo Compilation de %%f
    %CXX% %CXXFLAGS% -c %%f -o build\%%~nf.o
)

rem Création des exécutables
echo Edition des liens pour %EXE%
%CXX% build\*.o -o %EXE% %LDFLAGS%

echo Compilation terminée !
exit /b

