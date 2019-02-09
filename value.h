/* Created by Tau on 06/02/2019 */
#ifndef _HG_VALUE_H_
#define _HG_VALUE_H_

#include <inttypes.h>

typedef enum {
    BOOL_VALUE,
    NULL_VALUE,
    INT_VALUE,
    DOUBLE_VALUE,
    STRING_VALUE,
    Object_VALUE,
} ValueType;

typedef struct {
    int8_t v;  // v==0 false
} Bool;

typedef struct StringTag {
    char* str;
    int cnt;
    void (*refer)(struct StringTag*);
    void (*release)(struct StringTag*);
} String;

String *initString(char *s);

typedef struct {
    char* name;
    // TODO: object detail
} Object;

typedef struct {
    ValueType type;
    union {
        Bool bool_value;
        int32_t int_value;
        double double_value;
        Object object_value;
        String string_value;
    } v;
} Value;

// char *toString(Value v);

void valuePrint(Value v);

Value valueAdd(Value a, Value b);

Value valueSubtract(Value a, Value b);

Value valueMultiply(Value a, Value b);

Value valueDivide(Value a, Value b);

Value valueModule(Value a, Value b);

Value valuePower(Value a, Value b);

Value valueNot(Value v);

Value valueAnd(Value a, Value b);

Value valueOr(Value a, Value b);

Value valueMinus(Value v);

Value valueEqual(Value a, Value b);

Value valueNotEqual(Value a, Value b);

Value valueGreater(Value a, Value b);

Value valueLess(Value a, Value b);

Value valueGreaterOrEqual(Value a, Value b);

Value valueLessOrEqual(Value a, Value b);

#endif /*_HG_VALUE_H_*/
