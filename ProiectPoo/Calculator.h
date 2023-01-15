#pragma once
template <typename T> 
class Calculator
{
public:
	T CalculateSum(T first, T second) { return first + second; }
	T CalculateSubtraction(T first, T second) { return first - second; }
	T CalculateMultiplication(T first, T second) { return first * second; }
	T CalculateDivision(T first, T second) { return first / second; }
	T CalculateModulo(T first, T second) { return first % second; }
};