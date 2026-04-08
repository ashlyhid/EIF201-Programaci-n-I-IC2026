#ifndef SKILL_H
#define SKILL_H

#include <string>

namespace EIF201 {
	class Skill {
	private:
		std::string name;
		std::string damageType;

		int power;
		int energyCost;
		int clampRage(int value, int min, int max);
		bool isValidType(std::string type);

	public:
		Skill(std::string name, std::string damageType, int power, int energyCost);
		~Skill();

		std::string getName() const;
		std::string getDamageType() const;
		int getPower() const;
		int getEnergyCost() const;
		int calculateEffect() const;
		std::string toString() const;
	};
}

#endif 
