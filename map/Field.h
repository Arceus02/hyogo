#pragma once

enum FieldType {
	FIELD_MINERAL, FIELD_GAZ
};

class Field {
public:
	Field(int x, int y, FieldType fieldType, int amount);

	const int getX() const;

	const int getY() const;

	const FieldType getFieldType() const;

	const int getAmount() const;

	void extract(int amount);

private:
	int x, y;
	FieldType fieldType;
	int amount;
};