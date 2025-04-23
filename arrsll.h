#ifndef arrsll_H
#define arrsll_H
#include "boolean.h"
#include <stdio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next

typedef struct Warga *addresswg;
typedef struct Kota *addresskt;
typedef struct Kota {
	 char *kt;
	 addresswg Warga;
} Kota;

typedef struct Warga {
	 char *nm;
	 addresswg Warga;
} Kota;	  

// Modul

// End Modul

#endif

