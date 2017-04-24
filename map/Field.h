#pragma once

enum FieldType {
	FIELD_MINERAL, FIELD_GAZ
};

class Field {
public:
	Field(int x, int y, FieldType fieldType, int amount);

	int getX();

	int getY();

	FieldType getFieldType();

	int getAmount();

	void extract(int amount);

private:
	int x, y;
	FieldType fieldType;
	int amount;
};