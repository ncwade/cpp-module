#ifndef KERNEL_INTERFACE_H
#define KERNEL_INTERFACE_H

extern "C" {
	typedef unsigned int size_t;
	// C++ is unaware of kernel logging methods.
	#define KERN_INFO ""
	// Allow to initialize variables to NULL.
	#define NULL 0UL
	extern void printk(const char *fmt, ...);
	extern void *allocWrapper(size_t neededSpace);
	extern void freeWrapper(void *ptrToSpace);
}

inline void *operator new(size_t neededSpace)  {return allocWrapper(neededSpace);}
inline void operator delete(void *ptrToSpace) {return freeWrapper(ptrToSpace);}

#endif
