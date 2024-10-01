#pragma once
#include"Sala.h"


class Cinema {
	private:
		Sala* sala1;
		Sala* sala2;
		int niReg;
		int niVIP;
		int adulReg;
		int adulVIP;

	public:
		Cinema(Sala*, Sala*);

		virtual ~Cinema();

		Sala* getSala1();
		Sala* getSala2();
		int getNiReg();
		int getNiVIP();
		int getAdulReg();
		int getAdulVIP();

		void setSala1(Sala*);
		void setSala2(Sala*);
		void setNiReg(int);
		void setNiVIP(int);
		void setAdulVIP(int);
		void setAdulReg(int);

		string stringPrecios();
		string toString();
};

