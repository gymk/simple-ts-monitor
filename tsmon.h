#ifndef __SIMPLE_TS_MONITORING_H__
    #define __SIMPLE_TS_MONITORING_H__

#include "tsmon_events.h"

typedef void* TS_MON_CTXT;

TS_MON_CTXT TSMON_GetInstance(void);
void TSMON_ReleaseInstance(TS_MON_CTXT pvInstance);

bool TSMON_StartMonitoring(TS_MON_CTXT pvInstance);
bool TSMON_StopMonitoring(TS_MON_CTXT pvInstance);

// TO DO - Add other functions

#endif /* !__SIMPLE_TS_MONITORING_H__ */