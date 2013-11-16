/*
 * Common utilities and idioms
 */
#ifndef MACROS_H
#define MACROS_H



#define NOOP ((void)0)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

/*
 * STR gives s as a string
 * XSTR expands s before stringifying
 */
#define  STR(l) #l
#define XSTR(m) STR(m)





#endif/* MACROS_H */
