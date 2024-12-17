#include<iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include <ctime>
using namespace std;

//5����λ������λ���ļ�����1
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
	//5����λ������λ���ļ�����2
	system("color FC"); // ��ɫ��Ϊ����ɫ
	srand(time(0));

	int num1, num2, userAnswer, correctAnswer;
	int correctCount = 0;
	const int totalQuestions = 5;
	time_t startTime = time(0);

	for (int i = 1; i <= totalQuestions; i++) {
		num1 = generateRandomNumber(1000, 9999);
		num2 = generateRandomNumber(1000, 9999);
		correctAnswer = num1 * num2;

		cout << "����" << i << ": " << num1 << " * " << num2 << " = ";

		string input;
		cin >> input;

		while (!isNumber(input)) {
			cout << "������������������: ";
			cin >> input;
		}

		userAnswer = stoi(input);

		if (userAnswer == correctAnswer) {
			cout << "��ȷ!" << endl;
			correctCount++;
		}
		else {
			cout << "����!" << endl;
			cout << "��ȷ���ǣ�" << correctAnswer << endl;
		}
	}

	time_t currentTime = time(0);
	int elapsedTime = difftime(currentTime, startTime);

	if (elapsedTime <= 420) { // 7 minutes = 420 seconds
		cout << "��ϲ��������7�����ڴ����������⣬�����õ�ʱ��Ϊ��";
		if (elapsedTime / 60 != 0)cout << elapsedTime / 60 << "��";
		cout << elapsedTime % 60 << "��" << endl;
	}
	else {
		cout << "��δ��7�����ڴ����������⣬�����õ�ʱ��Ϊ��";
		if (elapsedTime / 60 != 0)cout << elapsedTime / 60 << "��";
		cout << elapsedTime % 60 << "��" << endl;
	}

	cout << totalQuestions << "����Ŀ�У����ܹ���� " << correctCount << " �� " << endl;
	system("pause");
	return 0;
}