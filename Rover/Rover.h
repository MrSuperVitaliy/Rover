/*
	Rover библиотека для управления роботом со схемой H-Bridge with L298N
	Автор: Притула Виталий
	Начало: 06.08.2015
*/

#include "Arduino.h"

class Rover {
	public:
		Rover(int rightDirection, int rightSpeed, int leftDirection, int leftSpeed);

		//Вперед на максимальной скорости
		void forward();

		//Вперед на скорости speed. Диапазон от 0 по 255
		void forward(int speed);

		//Назад на максимальной скорости
		void back();

		//Назад на скорости speed. Диапазон от 0 до 255
		void back(int speed);

		//Разворот влево на максимальной скорости.
		//Левая гусеница назад, правая вперед
		void left();

		//Разворот влево на скорости speed
		//Левая гусеница назад, правая вперед
		void left(int speed);

		//Разворот направо на максимальной скорости
		//Правая гусеница назад, левая вперед
		void right();

		//Разворот направо на скорости speed
		//Правая гусеница назад, левая вперед
		void right(int speed);

		//Запуск левой гусеницы. Диапазон скорости от -255 до 255.
		//От -255 по -1 назад. От 1 по 255 вперед. 0 - стоп
		void leftTrack(int speed);

		//остановка правой гусеницы
		void stopLeftTrack();

		//Запуск правой гусеницы. Диапазон скорости от -255 до 255.
		//От -255 по -1 назад. От 1 по 255 вперед. 0 - стоп
		void rightTrack(int speed);

		//Остановка правой гусеницы
		void stopRightTrack();

		//Остановка всего Rover
		void stop();
	private:
		int _rightDirection;
		int _rightSpeed;
		int _leftDirection;
		int _leftSpeed;
};
