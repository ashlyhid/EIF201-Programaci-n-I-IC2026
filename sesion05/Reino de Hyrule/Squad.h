#ifndef SQUAD_H
#define SQUAD_H

#include <string>
#include "Warrior.h"


namespace EIF201 {
	class Squad {
	private:
		std::string name;
		Warrior** Warriors;
		int capacity;
		int count;
		
		void expand();

	private:
		Squad(std::string name, int capacity);
		~Squad();

		Warrior* recruit(std::string name, std::string cls, int atk, int def, int hp, int maxSkills);
		bool dissmis(std::string name);

		int totalPower() const;
		void showSquad() const;

		int getCount() const;
		std::string getName() const;

		Warrior** getByClass(std::string cls, int& resultCount) const;

		void sortByPower();
		std::string	simulateBattle(const Squad& enemy) const;
	};
}

#endif 
