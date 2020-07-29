#ifndef __NN_CONFIG_H
#define __NN_CONFIG_H

#define EXPR__(arg)	#arg
#define EXPR_(arg)	EXPR__(arg)
#define EXPR(arg)	EXPR_(arg)

#define CONC__(_1, _2)	_1##_2
#define CONC_(_1, _2)	CONC__(_1, _2)
#define CONC(_1, _2)	CONC_(_1, _2)

#define ERROR(FMT, ...) fprintf(stderr, FMT, ##__VA_ARGS__)

#define __ARGS_INTER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define __ARGS(...) __ARGS_INTER(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define FOR_1(func, x, ...) __VAL_EQ(x) func(x);
#define FOR_2(func, x, ...) __VAL_EQ(x) func(x) FOR_1(func, __VA_ARGS__)
#define FOR_3(func, x, ...) __VAL_EQ(x) func(x) FOR_2(func, __VA_ARGS__)
#define FOR_4(func, x, ...) __VAL_EQ(x) func(x) FOR_3(func, __VA_ARGS__)
#define FOR_5(func, x, ...) __VAL_EQ(x) func(x) FOR_4(func, __VA_ARGS__)
#define FOR_6(func, x, ...) __VAL_EQ(x) func(x) FOR_5(func, __VA_ARGS__)
#define FOR_7(func, x, ...) __VAL_EQ(x) func(x) FOR_6(func, __VA_ARGS__)
#define FOR_8(func, x, ...) __VAL_EQ(x) func(x) FOR_7(func, __VA_ARGS__)

#define FOR_(N, func, x, ...) CONC(FOR_, N)(func, x, __VA_ARGS__)
#define FOR(func, x, ...) FOR_(FOR_NARG(x, __VA_ARGS__), func, x, __VA_ARGS__)

#define FOR_EQ_1(func, x, ...) x = func(x)
#define FOR_EQ_2(func, x, ...) x = func(x); FOR_EQ_1(func, __VA_ARGS__)
#define FOR_EQ_3(func, x, ...) x = func(x); FOR_EQ_2(func, __VA_ARGS__)
#define FOR_EQ_4(func, x, ...) x = func(x); FOR_EQ_3(func, __VA_ARGS__)
#define FOR_EQ_5(func, x, ...) x = func(x); FOR_EQ_4(func, __VA_ARGS__)
#define FOR_EQ_6(func, x, ...) x = func(x); FOR_EQ_5(func, __VA_ARGS__)
#define FOR_EQ_7(func, x, ...) x = func(x); FOR_EQ_6(func, __VA_ARGS__)
#define FOR_EQ_8(func, x, ...) x = func(x); FOR_EQ_7(func, __VA_ARGS__)

#define FOR_EQ_(N, func, x, ...) CONC(FOR_EQ_, N)(func, x, __VA_ARGS__)
#define FOR_EQ(func, x, ...) FOR_EQ_(__ARGS(x, __VA_ARGS__), func, x, __VA_ARGS__)

#endif	/*__NN_CONFIG_H */
