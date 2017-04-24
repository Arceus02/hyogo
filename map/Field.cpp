#include "Field.h"

Field::Field(int x, int y, FieldType fieldType, int amount) {
	this->x = x;
	this->y = y;
	this->fieldType = fieldType;
	this->amount = amount;
}

int Field::getX() {
	return x;
}

int Field::getY() {
	return y;
}

FieldType Field::getFieldType() {
	return fieldType;
}

int Field::getAmount() {
	return amount;
}

void Field::extract(int amount) {
	this->amount -= amount;
}