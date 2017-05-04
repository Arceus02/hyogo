#include "Field.h"

Field::Field(int x, int y, FieldType fieldType, int amount) {
	this->x = x;
	this->y = y;
	this->fieldType = fieldType;
	this->amount = amount;
}

const int Field::getX() const {
	return x;
}

const int Field::getY() const {
	return y;
}

const FieldType Field::getFieldType() const {
	return fieldType;
}

const int Field::getAmount() const {
	return amount;
}

void Field::extract(int amount) {
	this->amount -= amount;
}