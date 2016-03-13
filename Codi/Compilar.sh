#!/bin/bash
#Compila punt
g++ -c ./Implementacions/Punt.cc  -I ./Headers/
#Compila capsa
g++ -c ./Implementacions/Capsa.cc  -I ./Headers/
#Compila Cercle
g++ -c ./Implementacions/Cercle.cc  -I ./Headers/
#Compila el Main
g++ -c main.cc -I ./Headers/
# #Crea l'executable
g++ -o main.exe main.o ./{Capsa.o,Punt.o,Cercle.o}
