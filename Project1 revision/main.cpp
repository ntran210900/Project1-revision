#include <iostream>
#include <string>

using namespace std;


void rightJustify(char* arr, const int SIZE)
 {
	int len = strlen(arr);
	int shiftAmount = SIZE - len;
	for (int i = SIZE - 1; i >= 0; --i) {
		if (i >= shiftAmount)
			arr[i] = arr[i - shiftAmount];
		else
			arr[i] = '0';
	}
	arr[SIZE] = '\0';
}

void splitTer(char* input, const int SIZE, char* decimal, char *whole)
{
	
	int pointer = 0;
	for (int i = 0; i < SIZE; i++)
	{
		
		if (input[i] == '.')
			pointer = i;	
		else if (input[pointer] != '.')
			whole[i] = input[i];		
		else		
			decimal[i - pointer-1] = input[i];
	}
	if (pointer > 0)
	{
		whole[pointer] = '\0';
		decimal[SIZE] = '\0';
	}
	else if(pointer == 0&& input[0]!='.')
	{
		decimal[pointer] = '\0';
		whole[SIZE] = '\0';
	}
	else
	{
		decimal[SIZE] = '\0';
		whole[pointer] = '\0';
	}
	
	rightJustify(whole, SIZE);
	rightJustify(decimal, SIZE);
	

}
//void binaryConvertor(int number, bool* binary, int count) {
//	if (number != 0 && number != 1) {
//		if (number & 0x01) {
//			binary[count] = true;
//			number = (number - 1) / 2;
//		}
//		else {
//			binary[count] = false;
//			number = number / 2;
//		}
//		count--;
//		binaryConvertor(number, binary, count);
//	}
//	else if (number == 0) {
//		binary[count] = false;
//		return;
//	}
//	else if (number == 1) {
//		binary[count] = true;
//		return;
//	}
//}
//char* cstringAdd(char* balance, char* deposit)
//{
//	int carry = 0;
//	char* newBalance = nullptr;
//	newBalance = new char[23];
//	int count = 21;
//	for (int i = 21; i >= 0; i--)
//	{
//		if (balance[i] != balance[0] || deposit[i] != deposit[0])
//		{
//			int sum = 0;
//			if (balance[i] == balance[0])
//				sum = (deposit[i] - '0') + carry;
//			else if (deposit[i] == deposit[0])
//				sum = (balance[i] - '0') + carry;
//			else
//				sum = (balance[i] - '0') + (deposit[i] - '0') + carry;
//			newBalance[i] = (sum % 10) + '0';
//			carry = sum / 10;
//			count--;
//		}
//	}
//}
int getBreakPoint(char* left, const int SIZE)
{
	int breakPoint = 0;
	while (left[breakPoint] == '0' && breakPoint < SIZE) {
		breakPoint++;
	}
	if (breakPoint == SIZE) {
		return SIZE - 1;
	}
	else
	return breakPoint;
}
int ctin(char letter)
{
	return letter - '0';
}
void subtractChar(char* left, char *right,const int SIZE)
{
	int carry = 0;
	int breakPoint= getBreakPoint(left,SIZE) ;
	for (int i = SIZE - 1; i >= breakPoint; i--)
	{
		int sum = 0;
		sum=ctin(left[i]) - right[i] - carry;
		if (sum < 0)
		{
			sum =abs(sum);
			carry = 1;
		}
		else
		{
			sum = ctin(left[i])  - right+ carry;
			carry = 0;

		left[i] = sum  + '0';
		cout<<left[i]<<endl;
		
	}
}
bool isNegative(char* input)
{
	if (input[0] == '-')
	{
		input[0] = 32;
		return true;

	}
	else
	{
		return false;
	}
}

int main()
{
	const int SIZE = 52;
	char * input = new char[SIZE];
	char* decimal = new char[SIZE];
	char* whole = new char[SIZE];

	cout << "Enter the folating point number: ";
	cin.getline(input, SIZE);

	bool negative = isNegative(input);

	splitTer(input, SIZE,decimal,whole);
	cout << whole << endl;
	cout << decimal << endl;
	subtractChar(whole, 5, SIZE);
	cout<< whole << endl;
}