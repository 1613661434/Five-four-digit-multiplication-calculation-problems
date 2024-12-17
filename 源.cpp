#include<iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
using namespace std;

//5道四位数乘四位数的计算题1
int generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

bool isNumber(string input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	//5道四位数乘四位数的计算题2
	system("color FC"); // 颜色改为亮红色
	srand(time(0));

	int num1, num2, userAnswer, correctAnswer;
	int correctCount = 0;
	const int totalQuestions = 5;
	time_t startTime = time(0);

	for (int i = 1; i <= totalQuestions; i++) {
		num1 = generateRandomNumber(1000, 9999);
		num2 = generateRandomNumber(1000, 9999);
		correctAnswer = num1 * num2;

		cout << "问题" << i << ": " << num1 << " * " << num2 << " = ";

		string input;
		cin >> input;

		while (!isNumber(input)) {
			cout << "输入有误！请重新输入: ";
			cin >> input;
		}

		userAnswer = stoi(input);

		if (userAnswer == correctAnswer) {
			cout << "正确!" << endl;
			correctCount++;
		}
		else {
			cout << "错误!" << endl;
			cout << "正确答案是：" << correctAnswer << endl;
		}
	}

	time_t currentTime = time(0);
	int elapsedTime = difftime(currentTime, startTime);

	if (elapsedTime <= 420) { // 7 minutes = 420 seconds
		cout << "恭喜您！您在7分钟内答完所有问题，您所用的时间为：";
		if (elapsedTime / 60 != 0)cout << elapsedTime / 60 << "分";
		cout << elapsedTime % 60 << "秒" << endl;
	}
	else {
		cout << "您未在7分钟内答完所有问题，您所用的时间为：";
		if (elapsedTime / 60 != 0)cout << elapsedTime / 60 << "分";
		cout << elapsedTime % 60 << "秒" << endl;
	}

	cout << totalQuestions << "个题目中，您总共答对 " << correctCount << " 个 " << endl;
	system("pause");
	return 0;
}