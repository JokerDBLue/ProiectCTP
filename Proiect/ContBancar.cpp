#include "ContBancar.h"


ContBancar::ContBancar()
{
	this->balans = 0;
	this->cod = "";
	this->codspate = "";
}
ContBancar::ContBancar(string cod, string codspate, int balans)
{
	this->balans = balans;
	this->cod = cod;
	this->codspate = codspate;
}
string ContBancar::GetCod()
{
	return cod;
}
string ContBancar::GetCodSpate()
{
	return codspate;
}
int ContBancar::GetBalans()
{
	return balans;
}

void ContBancar::SetCod(string cod)
{
	this->cod = cod;
}
void ContBancar::SetCodSpate(string codspate)
{
	this->codspate = codspate;
}

ContBancar::~ContBancar()
{
}