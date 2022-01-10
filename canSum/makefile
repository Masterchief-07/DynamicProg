cc= g++-11
params= -Wall -std=c++2a

all: canSum canSumArray bestSumArray bestSumArray2 canConstruct canConstructArray

canSum: canSum.cpp
	$(cc) $(params) canSum.cpp -o canSum

canSumArray: canSumArray.cpp
	$(cc) $(params) canSumArray.cpp -o canSumArray

bestSumArray: bestSumArray.cpp
	$(cc) $(params) bestSumArray.cpp -o bestSumArray

bestSumArray2: bestSumArray2.cpp
	$(cc) $(params) bestSumArray2.cpp -o bestSumArray2
canConstruct: canConstruct.cpp
	$(cc) $(params) canConstruct.cpp -o canConstruct

canConstructArray: canConstructArray.cpp
	$(cc) $(params) canConstructArray.cpp -o canConstructArray

clean:
	rm -rf canSum canSumArray bestSumArray
