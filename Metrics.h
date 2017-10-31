#ifndef METRICS_H_
#define METRICS_H_
#include "AddressTrace.h"

void printMetrics();
/* Prints all current metrics to console. */

void instructionMetrics();
void traceMetrics(INST_TYPE type);
void latencyMetrics(CACHE cache, INST_TYPE type);
void hitMetrics(CACHE cacheHit, INST_TYPE inst_type, ADDR_TYPE addr_type);
void mesiMetrics(MESI prev, MESI curr);

#endif
