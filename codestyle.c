//
// The file defines code-style of the project
//

// "PascalCase" for structs
// also add _s for struct types:
struct MyStruct_s {
  // snake_case for fields:
  int var;
  int *ref;
  float another_var;
};

// "PascalCase" for enum types
enum EnumType {
  // Items duplicate enum type?
  EnumType_Type1,
  EnumType_Type2,
};

// "PascalCase" for types
// Add _t for types:
typedef struct MyStruct_s MyStruct_t;
typedef int MyArray_t[2][10];
typedef enum EnumType EnumType_t;

// Or don't add _t:
typedef struct MyStruct_s MyStruct;
typedef int MyArray_t[2][10];
typedef enum EnumType EnumType;

// "PascalCase" is the name of the struct,
// and "snake_case" is the rest of the function name
// for functions that create structures instances.
MyStruct *MyStruct_new();
// arguments are "snake_case"
MyStruct *MyStruct_from_int(int my_val);
MyStruct MyStruct_new_to_owned();

// "camelCase" is the name of the struct,
// and "snake_case" is the rest of the function name
// for functions that interact with struct instances.
void myStruct_do_something(MyStruct *stct);

// "camelCase" for global and/or extern functions
extern void myExternalFunction();

// "snake_case" for other functions:
void my_function()
inline void my_inline_function();
static void my_static_function();

// "SCREAMING_SNAKE_CASE" for constants:
const int MY_CONSTANT;
// define constants too
#define MY_DEFINED_CONST

int main() { // open curve bracket on the same line

  // "snake_case" for variables
  int my_variable = 0;

  // whitespace between '=' and operators except '++' and '--'. Also after ;
  for (int i = 0; i < 10; i++);

  // all conditions in brackets
  if ((my_variable | 2) && my_variable) {}

}

// -------------------------
// Function documentation
// -------------------------

//! see https://www.doxygen.nl/manual/docblocks.html
//! or/and https://www.jetbrains.com/help/clion/creating-and-viewing-doxygen-documentation.html
//! or/and https://wiki.scilab.org/Doxygen%20documentation%20Examples
//! or/and (structs) https://stackoverflow.com/questions/7199151/use-doxygen-to-document-members-of-a-c-structure-outside-of-the-structure-defini

// example

/// Function that contain a docstring
/// @param [in] param1 Integer variable - first parameter
/// @param [in] param2 Integer variable - second parameter
void function_with_docstring(int param1, int param2);

/** @struct MyDocumentedStruct
 *  This is documented struct
 *  @brief uses for nothing
 *  @property int var
 *  just integer property
 *
 *  @property float $float_var
 *  float variable
 *
 */
struct MyDocumentedStruct {
  int var;
  float float_var;
};