#ifndef __DEBUG__
#define __DEBUG__


#ifdef __USA_DEBUG__
#define DEBUG(A) printf(A)
#else
#define DEBUG(A) 
#endif


#endif