#ifndef TOOLKIT_H
#define TOOLKIT_H

/* Data header files for manipulating data types */
/* Data suite holds the typedef of simplified datatype declaration alias and "BankAccount" Struct. */
#include "data/data_suite.h"
/* The database that is managed (initialized with 8 arbitrary set name). */
#include "data/database.h"
/* Generic Datatype containing user-defined union with combination of different datatypes and its type checker. */
#include "data/generic_datatype.h"

/* Library functions */
/* General functions header files generally applicable to many different parameteric input. */
#include "lib/generic_functionality/general_functions.h"

/* Helper functions is for managing string and char arrays. */
#include "lib/input/input_helpers.h"

/* Applying linked list for achieving flexibility in database management.  */
#include "lib/linked_list/linkedlist_c.h"

/* Valdations functions that checks the permissibility of an input by returning False or True flags. */
#include "lib/validators/validator.h"

#endif