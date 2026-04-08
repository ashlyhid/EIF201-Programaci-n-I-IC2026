#include "Squad.h"
#include <iostream>

using namespace EIF201;

Squad::Squad(std::string name, int capacity) {
	this->name = (name == "") ? "Unnamed Squad" : name;
	this->capacity = capacity;
	this->count = 0;
	warriors = new Warrior * [capacity];
}

Squad::~Squad() {
	for (int i = 0; i < count; i++) {
		delete warriors[i];
	}
	delete[] warriors;
}

void Squad::expand() {
	int newCapacity = capacity * 2;
	Warrior** temp = new Warrior * [newCapacity];

	for (int i = 0; i < count; i++) {
		temp[i] = warriors[i];
	}	

	delete[] warriors;
	warriors = temp;
	capacity = newCapacity;
}

Warrior* Squad::recruit(std::string name, std::string cls, int atk, int def, int hp, int maxSkills) {
	if (count == capacity) {
		expand();	
	}

	Warrior* newWarrior = new Warrior(name, cls, atk, def, hp, maxSkills);
	warriors[count++] = newWarrior;

	return newWarrior;
}

bool Squad::dissmis(std::string name)		 {
	for (int i = 0; i < count; i++) {
		if (warriors[i]->getName() == name) {
			delete warriors[i];

			for (int j = i; j < count - 1; j++) {
				warriors[i] = warriors[j + 1];
			}

			count--;
			return true;
		}
	}
	return false;
}

int Squad::totalPower() const {
	int total = 0;
	for (int i = 0; i < count; i++) {
		total += warriors[i]->combatPower();
	}
	return total;
}

void Squad::showSquad() const {
	int total = 0;
	for (int i = 0; i < count; i++) {
		total += warriors[i]->combatPower();
	}
	return total;
}

void Squad::showSquad() const {
	std::cout << "Escuadra: " << name << std::endl;
	std::cout << "Guerreros: " << count << std::endl;

	for (int i = 0; i < count; i++) {
		warriors[i]->show();
		std::cout << "----------" << std::endl;
	}
	std::cout << "Poder Total: " << totalPower << std::endl;
}

int Squad::getCount() const {
	return count;
}

std::string Squad::getName() const {
	return name;
}

Warrior** Squad::getByClass(std::string cls, int& resultCount) const {
	resultCount = 0;

	for (int i = 0; i < count; i++) {
		if (warriors[i]->getClass() == cls) {
			resultCount++;
		}
	}
	if (resultCount == 0) {
		return nullptr;
	}

	Warrior** result = new Warrior * [resultCount];
	int index = 0; 
	for (int i = 0; i < count; i++) {
		if (warriors[i]->getClass() == cls) {
			result[index++] = warriors[i];
		}
	}
	return result;
}

void Squad::sortByPower() {
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (warriors[i]->combatPower() < warriors[j + 1]->combatPower()) {
				Warrior* temp = warriors[j];
				warriors[j] = warriors[j + 1];
				warriors[j + 1] = temp;
			}
		}
	}
}

std::string Squad::simulateBattle(const Squad& enemy) const {
	int power1 = this->totalPower();
	int power2 = enemy.totalPower();

	std::string result = "Batalla: \n";
	result += this->name + " (" + std::to_string(power1) + ") vs";
	result += enemy.getName() + " (" + std::to_string(power2) + ") \n";

	if (power1 >  power2) {
		result = "Ganador: " + this->name;
	}
	else if (power2 > power1) {
		result = "Ganador: " + enemy.getName();	
	}
	else {
		result = "Empate";
	}
	return result;
}