#include <iostream>
#include <string>
#include <Windows.h>

struct Hockey {
	char Family[256];
	short Age;
	short Numbers_of_games;
	short Number_of_goals;
};

using namespace std;

void BaseTask()
{
	cout << "Базовый уровень" << endl;
	const int Hockey_player = 4;
	Hockey group[Hockey_player];
	int a = 0;

	for (size_t i = 1; i < Hockey_player; i++)
	{
		cout << "Хоккеист №" << i << ":" << endl;

		cout << "\nВведите фамилию хоккеиста: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Family, 256);

		cout << "Введите возраст хоккеиста: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Age;

		a += group[i].Age;

		cout << "Введите количество игр: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Numbers_of_games;

		cout << "Введите количество заброшенных шайб: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Number_of_goals;

		cout << endl;

		cin.clear();
	}

	a = a / (Hockey_player - 1);
	cout << "Средний возраст хоккеистов составляет: " << a << " лет." << endl;

	for (size_t i = 1; i < Hockey_player; i++)
	{
		if (group[i].Age < 25)
		{
			cout << "\nХоккеист №" << i << ":" << endl;

			cout << "\nФамилия: " << group[i].Family << endl;
			cout << "Возраст: " << group[i].Age << endl;
			cout << "Количество игр: " << group[i].Numbers_of_games << endl;
			cout << "Количество заброшенных шайб: " << group[i].Number_of_goals << endl;
		}
	}
	cout << endl;
	cout << "--------------------------------------------------------------------------------------------------------------" << endl;
}

struct Date {
	double hour;
	double minute;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	if ((hour >= 0) && (hour < 24))
	{
		if ((minute >= 0) && (minute < 60))
		{
			result = true;
		}
		else
		{
			result = false;
		}
	}
	else
	{
		result = false;
	}

	return result;
}

struct Flight {
	short Number;
	Date Arrival;
	Date Departure;
	char Route[256];
	char Mark[256];
	short Distance;
};

void MediumTask()
{
	cout << "Средний уровень:" << endl;
	const int N = 3;
	Flight group[N];
	int* mass = new int[N];

	for (size_t i = 0; i < N; i++)
	{
		cout << "Введите номер авиарейса: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Number;

		do
		{
			cout << "Введите время вылета: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].Arrival.hour >> group[i].Arrival.minute;
		} while (!group[i].Arrival.isCorrect());

		do
		{
			cout << "Введите время прилета: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].Departure.hour >> group[i].Departure.minute;
		} while (!group[i].Departure.isCorrect());

		//Находим разницу времени прилета и вылета самолета в минутах
		double a = (group[i].Arrival.hour * 60) + group[i].Arrival.minute;
		double b = (group[i].Departure.hour * 60) + group[i].Departure.minute;
		double c;

		if (a > b)
		{
			c = (1440 - a) + b;
		}
		else
		{
			if (a == b)
			{
				c = 1440;
			}
			else
			{
				c = b - a;
			}
		}

		//Переводим полученную разницу в часы
		c = c / 60;

		cout << "Введите направление: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Route, 256);

		cout << "Введите марку самолета: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].Mark, 256);

		cout << "Введите расстояние в километрах: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].Distance;

		mass[i] = group[i].Distance / c;

		cout << endl;

		cin.clear();
	}

	int max = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (mass[i] > max)
		{
			max = mass[i];
		}
	}

	for (size_t i = 0; i < N; i++)
	{
		if (max == mass[i])
		{
			cout << "\n№ Авиарейса: " << group[i].Number << endl;
			cout << "Время вылета: " << group[i].Arrival.hour << "." << group[i].Arrival.minute << endl;
			cout << "Время прилета: " << group[i].Departure.hour << "." << group[i].Departure.minute << endl;
			cout << "Напраление: " << group[i].Route << endl;
			cout << "Марка самолета: " << group[i].Mark << endl;
			cout << "Расстояние: " << group[i].Distance << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	BaseTask();
	MediumTask();
}
