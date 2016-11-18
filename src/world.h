#ifndef _world_h_
#define _world_h_

typedef void (*world_func)(int, int, int, int, void *);

extern "C" {
 void __declspec(dllexport) create_world(int p, int q, world_func func, void *arg);
}


#endif
