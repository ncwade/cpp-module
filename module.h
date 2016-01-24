#ifndef CPP_MOD_H
#define CPP_MOD_H
// If g++ is processing it we need make the symbols available for gcc.
#ifdef __cplusplus
extern "C" {
#endif
	extern int start_driver(void* data);
	extern void stop_driver(void);
#ifdef __cplusplus
}
#endif
#endif
