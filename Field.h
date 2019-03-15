#ifndef SWORMS_FIELD_H
#define SWORMS_FIELD_H

namespace Sep
{
  class Field
  {
    public:
      enum FieldType
      {
        AIR, EARTH, WATER, WORM
      };

      Field(FieldType type);

      FieldType getType();

      void setType(FieldType type);

      char getCharacter();

      virtual ~Field();

    private:
      FieldType type_;

  };
}

#endif //SWORMS_FIELD_H