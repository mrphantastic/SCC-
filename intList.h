/* intList.h
 * (what is the purpose of this file? Replace question with your text)
 */

#ifndef C101IntList
#define C101IntList
/* Multiple typedefs for the same type are an error in C. */

typedef struct IntListNode * IntList;

/** intNil denotes the empty IntList */
extern const IntList intNil;

/* Access functions
 * precondition: L!=intNil
 */

/** first
 */
int intFirst(IntList oldL);

/** rest
 */
IntList intRest(IntList oldL);

/* Constructors
 * precondition: newE isn't NULL
 * postcondition: if newL=intCons(newE,oldL) then
 * intFirst(newL)==newE &
 * intRest(newL)==old:
 */

/** cons
 */
IntList intCons(int newE, IntList oldL);

#endif

