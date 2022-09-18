#include <iostream>

class Calculator
{
public:
	// Названия методов не соответствуют соглашению по оформлению кода, но в задаче так. Считаем, что это ТЗ.

	double add()
	{
		return _num1 + _num2;
	}

	double multiply()
	{
		return _num1 * _num2;
	}

	double subtract_1_2()
	{
		return _num1 - _num2;
	}

	double subtract_2_1()
	{
		return _num2 - _num1;
	}

	double divide_1_2()
	{
		return _num1 / _num2;
	}

	double divide_2_1()
	{
		return _num2 / _num1;
	}

	double get_num1()
	{
		return _num1;
	}

	bool set_num1(double num1)
	{
		return tryToSetValue(this->_num1, num1);
	}

	double get_num2()
	{
		return _num2;
	}

	bool set_num2(double num2)
	{
		return tryToSetValue(this->_num2, num2);
	}

	Calculator()
	{
		_num1 = _num2 = 1;
	}
private:
	double _num1;
	double _num2;
	bool tryToSetValue(double& target, double value)
	{
		if (value != 0)
		{
			target = value;
			return true;
		}

		return false;
	}
};

class CalcInitializer
{
public:
	void initialize(Calculator& calc)
	{
		double value = 0;
		do
		{
			std::cout << MSG_ENTER_NUM1;
			std::cin >> value;
			if (calc.set_num1(value))
			{
				break;
			}
			else
			{
				std::cout << MSG_INVALID_INPUT << std::endl;
			}
		} while (true);

		do
		{
			std::cout << MSG_ENTER_NUM2;
			std::cin >> value;
			if (calc.set_num2(value))
			{
				break;
			}
			else
			{
				std::cout << MSG_INVALID_INPUT << std::endl;
			}
		} while (true);
	}
private:
	const std::string MSG_ENTER_NUM1 = "Введите num1: ";
	const std::string MSG_ENTER_NUM2 = "Введите num2: ";
	const std::string MSG_INVALID_INPUT = "Неверный ввод!";
};

class CalcDemonstrator
{
public:
	void demonstrate(Calculator& calc)
	{
		std::cout << "num1 + num2 = " << calc.add() << std::endl;
		std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
		std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
		std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Calculator calc;
	CalcInitializer calcInit;
	CalcDemonstrator calcDemo;
	while (true)
	{
		calcInit.initialize(calc);
		calcDemo.demonstrate(calc);
	}
}
