// pr9_Pavlov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
Вариант 10. Уровень заряда устройств
Массив содержит уровень заряда нескольких устройств от 0 до 100 .
Реализуйте функции:
1. увеличить заряд на 10 ;
2. уменьшить заряд на 10 ;
3. установить заряд всех устройств равным 100 ;
4. ограничить значения диапазоном от 0 до 100 .
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

void increaseCharge(double* data, int size) {
	for (int i = 0; i < size; i++) {
		data[i] += 10.0;
	
		if (data[i] > 100.0) data[i] = 100.0;
}
}

void descreaseCharge(double* data, int size) {
	for (int i = 0; i < size; i++) {
		data[i] -= 10.0;

		if (data[i] < 0.0) data[i] = 0.0;
	}
}
void setFullCharge(double* data, int size)
{
	for (int i = 0; i < size; i++) {
		data[i] = 100.0;
	}
}

	void limitChargeRange(double* data, int size) {
		for (int i = 0; i < size; i++) {
			data[i] += 10.0;
			if (data[i] < 0.0) data[i] = 0.0;
			if (data[i] > 100.0) data[i] = 100.0;
		}
	}

void applayProcessing(double* data, int size, void(*processor)(double*, int)) {
	if (processor != nullptr) {
		processor(data, size);
	}
}
void printArray(const double* data, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << std::fixed  << std::setprecision(1) <<  data[i] << " ";
	}

}
int main()
{
	setlocale(LC_ALL, "Ru");
	srand(static_cast<unsigned int>(time(0)));
	const int SIZE = 10;
	double devices[SIZE];
	for (int i = 0; i < SIZE; i++) {
		devices[i] = static_cast<double>(rand() % 1001) / 10.0;
	}
	void (*processors[])(double*, int) = {
		increaseCharge, descreaseCharge,setFullCharge,limitChargeRange
	};
	void (*selectedProcessor)(double*, int) = nullptr;
	double originalDevices[SIZE];
	int choice = 0;
	while (true) {
		std::cout << "\nMENU:\n";
		std::cout << "Массив:";
		printArray(devices, SIZE);
		std::cout << "\n1.Увеличить заряд на 10\n";
		std::cout << "2.Уменьшить заряд на 10\n";
		std::cout << "3.Установить заряд всех устройств равным 100\n";
		std::cout << "4.Ограничить значения диапазоном от 0 до 100\n";
		std::cout << "5.Восстановить исходные данные\n";
		std::cout << "6.Выход\n";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (choice == 6) {
			std::cout << "Выход из программы!!\n";
			break;

		}
		if (choice >= 1 && choice <= 4) {
			selectedProcessor = processors[choice - 1];
			std::cout << "\nДо обработки:\n";
			printArray(devices, SIZE);
			applayProcessing(devices, SIZE, selectedProcessor);
			std::cout << "\nПосле обработки:\n";
			printArray(devices, SIZE);
		}
		else if (choice == 5) {
			std::copy(originalDevices, originalDevices + SIZE, devices);
			std::cout << "\nДанные восстановлены до начальных!";
		}
		else {
			std::cout << "\nНеверный пункт в меню!";
		}
	
}
	return 0;

}


