#include "long_number.hpp"

using biv::LongNumber;

LongNumber::LongNumber() 
    : numbers(nullptr), length(0), sign(1) {
    numbers = new int[1];
    numbers[0] = 0;
    length = 1;
}

LongNumber::LongNumber(const char* const str){
	length = get_length(str);
	numbers = new int[length];
	
	if (str[0] == '-'){
		sign = -1;
		for (int i =1; i<length; i++){
			numbers[i-1] = str [i]-'0';
		}
	} else {
		sign = 1;
		for (int i=0;i<length; i++){
			numbers[i]=str[i]-'0';
		}
	}
}

LongNumber::LongNumber(const LongNumber& x)
	:length(x.length), sign(x.sign){
	numbers = new int[length];
	std::memcpy(numbers, x.numbers, length * sizeof(int));
}

LongNumber::LongNumber(LongNumber&& x)
	:numbers
	
LongNumber::~LongNumber() {
	delete[] numbers;
}




bool LongNumber::operator == (const LongNumber& x) const{
	if (sign != x.sign || length != x.length){
		return false;
	} else {
	for(int i=0; i < length; i++){
		if (numbers[i] != x.numbers[i]){
			return false;
		}
	}else{
		return true;
	}
	}
}

bool LongNumber::operator!=(const LongNumber& x) const{
	if (sign != x.sign || length != x.length){
		return true;
	} else {
		for( int i =0; i<length; i++){
			if (numbers[i] != x.numbers[i]){
				return true;
			}
		} else {
			return false;
		}
	}
}

bool LongNumber:: operator > (const LongNumber& x) const{
	if (sign != x.sign){
		return sign>x.sign;
	}
	if (length != x.length){
		if (sign == 1){
			return length > x.length;
		}
		return length < x.length;
	}
	for( int i = 0; i < length; i++){
		if ( numbers[i] !=x.numbers[i]{
			if (sign ==1){
				return numbers[i] > x. numbers[i];
			}
			return numbers[i] < x.numbers[i];
		}
	}
	return false;
}








LongNumber LongNumber::operator + (const LongNumber& x) const {
	int max_len = std::max(length,x.length)+1;
	int* result_numbers = new int[max_len]();
	int i = length -1;
	int j = x.length -1;
	int k = max_len -1;
	
	while (i>=0 || j>=0 || carry){
		int sum = carry;
		if (i >= 0) sum += numbers[i--];
		if (j >= 0) sum += x.numbers[j--];
		result_numbers[k--] = sum % 10;
		carry = sum/10;
	}
	
	LongNumber result;
    result.numbers = result_numbers + k + 1; 
    result.length = max_len - (k + 1);
    result.sign = 1;

    return result;
}


	//int length = 0;
	//while (str[length] != '\0'){
	//	length++;
	//}
	
	