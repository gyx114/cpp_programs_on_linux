echo "compiling Point.o"
g++ -c Point.cpp -o Point.o
echo "compiling Line.o"
g++ -c Line.cpp -o Line.o
echo "compiling main.o"
g++ -c main.cpp -o main.o
echo "linking test"
g++ main.o Line.o Point.o -o test
