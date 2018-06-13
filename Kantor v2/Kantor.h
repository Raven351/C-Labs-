#pragma once

class Kantor {
private:
	float const avgUSD;
	float const avgEUR;
	float const spread;
	float income; //zarobki kantoru ze spreadu na jednorazowej transakcji
	float totalIncome; // laczne zarobki kantoru

public:
	Kantor(float avgUSD, float avgEUR);
	float kupUSD(float pln);
	float kupEUR(float pln);
	float sprzedajUSD(float usd);
	float sprzedajEUR(float eur);
	float PobierzIncome();
	float PobierzTotalIncome();
	float KursKantoru(float waluta, bool typ);
};
