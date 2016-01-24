#include <linux/slab.h>
#include <linux/module.h>

// Need to wrap our kmalloc/kree methods in something we can access from C++.
void *allocWrapper(size_t neededSpace) {
   return kmalloc(neededSpace, GFP_KERNEL);
}
void freeWrapper(void *ptrToSpace) {
   return kfree(ptrToSpace);
}
