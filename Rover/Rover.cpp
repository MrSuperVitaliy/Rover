#include "Rover.h"
#include "Arduino.h"

Rover::Rover(int rightDirection, int rightSpeed, int leftDirection, int leftSpeed) {
	pinMode(rightDirection, OUTPUT);
	pinMode(rightSpeed, OUTPUT);
	pinMode(leftDirection, OUTPUT);
	pinMode(leftSpeed, OUTPUT);
	_rightDirection = rightDirection;
	_rightSpeed = rightSpeed;
	_leftDirection = leftDirection;
	_leftSpeed = leftSpeed;
}


//Вперед на максимальной скорости
void Rover::forward() {
	digitalWrite(_rightDirection, 0);
	digitalWrite(_leftDirection, 0);

	digitalWrite(_rightSpeed, 1);
	digitalWrite(_leftSpeed, 1);
}

//Вперед на скорости speed. Диапазон от 0 по 255
void Rover::forward(int speed) {
	if (speed > 0 && speed < 256) {
		digitalWrite(_rightDirection, 0);
		digitalWrite(_leftDirection, 0);

		analogWrite(_rightSpeed, speed);
		analogWrite(_leftSpeed, speed);
	} else stop();
}

//Назад на максимальной скорости
void Rover::back() {
	digitalWrite(_rightDirection, 1);
	digitalWrite(_leftDirection, 1);

	digitalWrite(_rightSpeed, 1);
	digitalWrite(_leftSpeed, 1);
}

//Назад на скорости speed. Диапазон от 0 до 255
void Rover::back(int speed) {
	if (speed > 0 && speed < 256) {
		digitalWrite(_rightDirection, 1);
		digitalWrite(_leftDirection, 1);

		analogWrite(_rightSpeed, speed);
		analogWrite(_leftSpeed, speed);
	}
}

//Разворот влево на максимальной скорости.
//Левая гусеница назад, правая вперед
void Rover::left() {
	digitalWrite(_rightDirection, 0);
	digitalWrite(_leftDirection, 1);

	digitalWrite(_rightSpeed, 1);
	digitalWrite(_leftSpeed, 1);
}

//Разворот влево на скорости speed
//Левая гусеница назад, правая вперед
void Rover::left(int speed) {
	if (speed > 0 && speed < 256) {
		digitalWrite(_rightDirection, 0);
		digitalWrite(_leftDirection, 1);

		digitalWrite(_rightSpeed, speed);
		digitalWrite(_leftSpeed, speed);
	}
}

//Разворот направо на максимальной скорости
//Правая гусеница назад, левая вперед
void Rover::right() {
	digitalWrite(_rightDirection, 1);
	digitalWrite(_leftDirection, 0);

	digitalWrite(_rightSpeed, 1);
	digitalWrite(_leftSpeed, 1);
}

//Разворот направо на скорости speed
//Правая гусеница назад, левая вперед
void Rover::right(int speed) {
	if (speed > 0 && speed < 256) {
		digitalWrite(_rightDirection, 1);
		digitalWrite(_leftDirection, 0);

		digitalWrite(_rightSpeed, speed);
		digitalWrite(_leftSpeed, speed);
	}
}

//Запуск левой гусеницы. Диапазон скорости от -255 до 255.
//От -255 по -1 назад. От 1 по 255 вперед
void Rover::leftTrack(int speed) {
	if (speed > 0 && speed <= 255) {
		digitalWrite(_leftDirection, 0);
		analogWrite(_leftSpeed, speed);
	} else if (speed < 0 && speed >= -255) {
		digitalWrite(_leftDirection, 1);
		analogWrite(_leftSpeed, abs(speed));
	} else if (speed == 0) {
		digitalWrite(_leftSpeed, 0);
	}
}

//остановка правой гусеницы
void Rover::stopLeftTrack() {
	digitalWrite(_leftSpeed, 0);
}

//Запуск правой гусеницы. Диапазон скорости от -255 до 255.
//От -255 по -1 назад. От 1 по 255 вперед
void Rover::rightTrack(int speed) {
	if (speed > 0 && speed <= 255) {
		digitalWrite(_rightDirection, 0);
		analogWrite(_rightSpeed, speed);
	} else if (speed < 0 && speed >= -255) {
		digitalWrite(_rightDirection, 1);
		analogWrite(_rightSpeed, abs(speed));
	} else if (speed == 0) {
		digitalWrite(_rightSpeed, 0);
	}
}

//Остановка правой гусеницы
void Rover::stopRightTrack() {
	digitalWrite(_rightSpeed, 0);
}

//Остановка всего Rover
void Rover::stop() {
	digitalWrite(_rightSpeed, 0);
	digitalWrite(_leftSpeed, 0);
}
