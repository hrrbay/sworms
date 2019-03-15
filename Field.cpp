#include "Field.h"

using Sep::Field;

Field::Field(FieldType type)
{
  type_ = type;
}

char Field::getCharacter()
{
  switch (type_)
  {
    case AIR:
      return ' ';
    case EARTH:
      return 'E';
    case WATER:
      return 'W';
    case WORM:
      return '~';
  }
}

void Field::setType(Field::FieldType type)
{
  type_ = type;
}

Field::FieldType Field::getType()
{
  return type_;
}